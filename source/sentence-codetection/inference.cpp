#include <cstdio>
#include <cstdarg>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <cstring>
#include <ctime>
#include <vector>
#include "opengm/graphicalmodel/graphicalmodel.hxx"
#include "opengm/graphicalmodel/space/discretespace.hxx"
#include "opengm/functions/explicit_function.hxx"
#include "opengm/operations/adder.hxx"
#include "opengm/operations/minimizer.hxx"
#include "opengm/inference/messagepassing/messagepassing.hxx"
#include "opengm/inference/external/libdai/bp.hxx"

typedef opengm::DiscreteSpace<> Space;
typedef opengm::ExplicitFunction<double> Function;
typedef opengm::GraphicalModel<double, opengm::Adder, Function, Space> GraphModel;
typedef GraphModel::FunctionIdentifier FID;
typedef opengm::BeliefPropagationUpdateRules<GraphModel, opengm::Minimizer> UpdateRules;
typedef opengm::MessagePassing<GraphModel, opengm::Minimizer, UpdateRules, opengm::MaxDistance> BP;
//typedef opengm::external::libdai::Bp<GraphModel, opengm::Minimizer> libdaiBP;

extern "C" double bp_object_inference(double **f, double **g, 
				      int T, int top_k, 
				      double dummy_f, double dummy_g, 
				      int num_gscores, int *boxes) {

  // each frame has a variable with top_k possible labels
  // ACTUALLY USING TOP_K+1 LABELS NOW WITH THE DUMMY STATE
  size_t numVariables = size_t(T);
  size_t numLabels = size_t(top_k) + 1;  //extra label for dummy state
  size_t *vars = new size_t[numVariables];
  for (unsigned int t = 0; t < numVariables; t ++)
    vars[t] = numLabels;
  Space space(vars, vars + numVariables);
  GraphModel gm(space);

  double some_small_number = 1e-10;
  double default_f_score = -log(0.5); // for testing-log(some_small_number);
  //removed for testing
  // if (dummy_f != 0.0)
  //   default_f_score = -log(dummy_f);
  // if (dummy_f == 1.0)
  //   default_f_score = -log(1.0-some_small_number);

  //debugging
  //printf("dummy_f = %f, dummy_g = %f\n",dummy_f,dummy_g);

  // add unary score functions
  for (unsigned int t = 0; t < numVariables; t ++){
    FID fid;
    size_t fshape[] = {numLabels}; 
    Function ff(fshape, fshape+1, default_f_score); 
    for (int i = 0; i < top_k; i ++){
      ff(i) = -log(0.5);//for testing-log(f[t][i]); //might need conditioning here
    }
    fid = gm.addFunction(ff);
    // add factors
    size_t fv[] = {size_t(t)};
    gm.addFactor(fid, fv, fv+1);

    //debugging
    // printf("ff values for t = %u: ",t);
    // for (unsigned int i = 0; i < numLabels; i++){
    //   printf("%f ",ff(i));
    // }
    // printf("\n");

  }
  printf("Unary functions added\n");

  // printf("--------------------\n");
  // for (int i = 0; i < num_gscores; i++){
  //   printf("%f %f %f %f %f\n",g[i][0],g[i][1],g[i][2],g[i][3],g[i][4]);
  // }
  // printf("--------------------\n");

  // add binary score functions
  size_t gshape[] = {numLabels, numLabels};
  size_t prevf1, prevf2;
  double dummy_g_score = -log(0.5);// for testing some_small_number);
  // removed for testing
  // if (dummy_g != 0.0)
  //   dummy_g_score = -log(dummy_g);
  // if (dummy_g == 1.0)
  //   dummy_g_score = -log(1.0-some_small_number);

  //first find indices into g matrix where frame change breaks are
  int numbreaks = (numVariables*(numVariables-1))/2; //nChoose2
  int breaks[numbreaks];// = {0}; 
  memset(breaks, 0, numbreaks*sizeof(int)); //manually initializing array
  breaks[0] = 0;
  int b_ind = 1;
  prevf1 = size_t(g[0][0]);
  prevf2 = size_t(g[0][2]);
  for (int i = 0; i < num_gscores; i++) {
    if ((prevf1 != (size_t(g[i][0]))) ||
	(prevf2 != (size_t(g[i][2])))) {
      breaks[b_ind] = i;
      b_ind++;
      prevf1 = size_t(g[i][0]);
      prevf2 = size_t(g[i][2]);
    }
  }

  // //print for debug
  // printf("Break indices: ");
  // for (int i = 0; i < b_ind; i++) {
  //   printf("%d ", breaks[i]);
  // }
  // printf(" ; numbreaks = %d, b_ind = %d\n",numbreaks,b_ind);	      

  //then loop through breaks, declare new gg every time, and add only the scores within that break
  for (int j = 0; j < b_ind; j++) {
    size_t frame1, box1, frame2, box2;
    double score;
    int start_ind = breaks[j];
    int end_ind;
    if (j == (b_ind - 1))
      end_ind = num_gscores;
    else
      end_ind = breaks[j+1];
    frame1 = size_t(g[start_ind][0]) - 1;  //need a -1 here b/c MATLAB vs. C
    frame2 = size_t(g[start_ind][2]) - 1;

    // //put a limit here to limit the distance between frames (limiting the number of gg functions added)
    // size_t frame_distance_threshold = 60;
    // if (abs(frame2-frame1) > frame_distance_threshold)
    //   continue;

    Function gg(gshape, gshape + 2, -log(0.5));// for testing some_small_number));
    //initialize dummy values in gg ****MIGHT I WANT TO KEY THIS TO ADJACENCY****
    for (unsigned int k = 0; k < numLabels; k++){
	gg(numLabels-1,k) = dummy_g_score;
	gg(k,numLabels-1) = dummy_g_score;
      }

    //debugging initialization
    // for (unsigned int l = 0; l < numLabels; l++){
    // 	for (unsigned int k = 0; k < numLabels; k++){
    // 	  printf("%.4f ",gg(l,k));
    // 	}
    // 	printf("\n");
    // }

    for (int i = start_ind; i < end_ind; i++) { //add score from each row of g
      box1 = size_t(g[i][1]) - 1;  //need a -1 here b/c MATLAB vs. C
      box2 = size_t(g[i][3]) - 1;
      score = g[i][4];
      gg(box1,box2) = -log(0.5); // for testing score); //might need conditioning here
      // printf("i = %d, frame1 = %zu, box1 = %zu, frame2 = %zu, box2 = %zu, score = %f\n",
      // 	   i, frame1, box1, frame2, box2, score);
    }

    //debugging after score add
    // printf("gg for frame1=%zu,frame2=%zu\n",frame1,frame2);
    // for (unsigned int l = 0; l < numLabels; l++){
    // 	for (unsigned int k = 0; k < numLabels; k++){
    // 	  printf("%.4f ",gg(l,k));
    // 	}
    // 	printf("\n");
    // }

    //add function
    FID gid = gm.addFunction(gg);
    //printf("added function for frame1 = %zu, frame2 = %zu\n",frame1,frame2);
    //add factors
    size_t gv[] = {size_t(frame1),size_t(frame2)};
    gm.addFactor(gid, gv, gv+2);
    //printf("added function & factor for frame1 = %zu, frame2 = %zu\n",frame1,frame2);
  }
  printf("Binary scores complete\n");


  //  inference
  const size_t maxIterations=100;
  const double damping=0.0;
  //const double tolerance=1e-5;
  const double convergenceBound = 1e-7;
  // libdaiBp::UpdateRule = PARALL | SEQFIX | SEQRND | SEQMAX
  //libdaiBP::UpdateRule updateRule = libdaiBP::PARALL;
  //size_t verboseLevel=0;
  //libdaiBP::Parameter parameter(maxIterations, damping, tolerance, updateRule,verboseLevel);
  BP::Parameter parameter(maxIterations,convergenceBound,damping);
  printf("before bp call\n");
  //libdaiBP bp(gm, parameter);
  BP bp(gm, parameter);
  printf("after bp call\n");
  // optimize (approximately)
  clock_t t1, t2;
  printf("before bp.infer\n");
  t1 = clock();
  bp.infer( );
  t2 = clock();
  printf("after bp.infer\n");
  std::cout << (double(t2) - double(t1))/CLOCKS_PER_SEC*1000 << " ms" << std::endl;
  std::cout << "OpenGM Belief Propagation " << -bp.value() << std::endl;
  std::vector<size_t> labeling(T); 
  bp.arg(labeling);
  for (unsigned int i = 0; i < labeling.size(); i ++)
    boxes[i] = int(labeling[i]);
  delete [] vars;
  return -bp.value();
}
