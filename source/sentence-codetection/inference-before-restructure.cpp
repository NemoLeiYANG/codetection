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
typedef opengm::external::libdai::Bp<GraphModel, opengm::Minimizer> libdaiBP;

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
  bool newBinaryMatrix = true;
  size_t frame1, box1, frame2, box2;
  double score;
  double dummy_g_score = -log(0.5);// for testing some_small_number);
  // removed for testing
  // if (dummy_g != 0.0)
  //   dummy_g_score = -log(dummy_g);
  // if (dummy_g == 1.0)
  //   dummy_g_score = -log(1.0-some_small_number);
  Function gg(gshape, gshape + 2, -log(0.5));// for testing some_small_number));
  for (int i = 0; i < num_gscores; i++){ //loop through lines of g
    if (newBinaryMatrix) { //re-initialize gg
      //printf("in newBinaryMatrix conditional\n");
      //Function gg(gshape, gshape + 2, 0.0);
      for (unsigned int k = 0; k < numLabels; k++){
	for (unsigned int j = 0; j < numLabels; j++) {
	  gg(k,j) = -log(0.5);// for testing some_small_number);
	}
      }
      for (unsigned int j = 0; j < numLabels; j++){
	gg(numLabels-1,j) = dummy_g_score;
	gg(j,numLabels-1) = dummy_g_score;
      }
      newBinaryMatrix = false;

      //debugging initialization
      // for (unsigned int j = 0; j < numLabels; j++){
      // 	for (unsigned int k = 0; k < numLabels; k++){
      // 	  printf("%.4f ",gg(j,k));
      // 	}
      // 	printf("\n");
      // }

    }
    //add score from each row of g
    frame1 = size_t(g[i][0]) - 1; //need a -1 here b/c MATLAB vs. C
    box1 = size_t(g[i][1]) - 1;
    frame2 = size_t(g[i][2]) - 1;
    box2 = size_t(g[i][3]) - 1;
    score = g[i][4];
    gg(box1,box2) = -log(0.5); // for testing score); //might need conditioning here
    // printf("i = %d, frame1 = %zu, box1 = %zu, frame2 = %zu, box2 = %zu, score = %f\n",
    // 	   i, frame1, box1, frame2, box2, score);
    //added this row--check to see if more rows for this frame1/frame2 combo or not
    if ((i == (num_gscores - 1)) ||    //if i == num_gscores-1, we know we're done
	(frame1 != (size_t(g[i+1][0]) - 1)) || //check if next frame1 or frame2 
	(frame2 != (size_t(g[i+1][2]) - 1))) { //is different from current
      //if so, mark newBinaryMatrix true 
      newBinaryMatrix = true;
      //also want to add binary scores from temporal coherency to gg here 
      //(so its only done once per gg function)

      //debugging
      // printf("gg for frame1=%zu,frame2=%zu\n",frame1,frame2);
      // for (unsigned int j = 0; j < numLabels; j++){
      // 	for (unsigned int k = 0; k < numLabels; k++){
      // 	  printf("%.4f ",gg(j,k));
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
  }
  printf("Binary scores complete\n");

  //  inference
  const size_t maxIterations=100;
  const double damping=0.0;
  const double tolerance=1e-5;
  // libdaiBp::UpdateRule = PARALL | SEQFIX | SEQRND | SEQMAX
  libdaiBP::UpdateRule updateRule = libdaiBP::PARALL;
  size_t verboseLevel=0;
  libdaiBP::Parameter parameter(maxIterations, damping, tolerance, updateRule,verboseLevel);
  printf("before bp call\n");
  libdaiBP bp(gm, parameter);
  printf("after bp call\n");
  // optimize (approximately)
  clock_t t1, t2;
  printf("before bp.infer\n");
  t1 = clock();
  bp.infer( );
  t2 = clock();
  printf("after bp.infer\n");
  std::cout << (double(t2) - double(t1))/CLOCKS_PER_SEC*1000 << " ms" << std::endl;
  std::cout << "libDAI Belief Propagation " << -bp.value() << std::endl;
  std::vector<size_t> labeling(T); 
  bp.arg(labeling);
  for (unsigned int i = 0; i < labeling.size(); i ++)
    boxes[i] = int(labeling[i]);
  delete [] vars;
  return -bp.value();
}
