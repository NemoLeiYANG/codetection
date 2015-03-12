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
				      int T, int top_k, int dummy_f, int dummy_g, 
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

  // add unary score functions
  for (unsigned int t = 0; t < numVariables; t ++){
    FID fid;
    size_t fshape[] = {numLabels}; 
    Function ff(fshape, fshape+1, dummy_f); 
    for (int i = 0; i < top_k; i ++){
      ff(i) = -f[t][i];
    }
    fid = gm.addFunction(ff);
    // add factors
    size_t fv[] = {size_t(t)};
    gm.addFactor(fid, fv, fv+1);
  }

  // add binary score functions
  size_t gshape[] = {numLabels, numLabels};
  bool newBinaryMatrix = true;
  for (int i = 0; i < num_gscores; i++){ //loop through lines of g
    if newBinaryMatrix {
	Function gg(gshape, gshape + 2, 0.0);
	newBinaryMatrix = false;
	for (unsigned int j = 0; j < numLabels; j++){
	  gg(numLabels-1,j) = dummy_g;
	  gg(j,numLabels-1) = dummy_g;
	}
      }
    size_t frame1 = g[i][1];
    size_t box1 = g[i][2];

    //check if next frame1 or frame2 is different from current
    //if so, mark newBinaryMatrix true and add current gg to factors
    
  }


  // // add functions
  // for (unsigned int t = 0; t < numVariables; t ++){
  //   FID fid, gid;
  //   size_t fshape[] = {size_t(top_k)+1}; 
  //   //size_t gshape[] = {size_t(top_k), size_t(top_k)};
  //   Function ff(fshape, fshape+1, dummy_f); 
  //   //Function gg(gshape, gshape+2, -INFINITY);
  //   for (int i = 0; i < top_k; i ++){
  //     ff(i) = -f[t][i];
  //     // if (t > 0){
  //     // 	for (int k = 0; k < top_k; k ++)
  //     // 	  gg(k,i) = -g[t-1][k][i];
  //     // }
  //   }
  //   fid = gm.addFunction(ff);
  //   // if (t > 0)
  //   //   gid = gm.addFunction(gg);
  //   // add factors
  //   size_t fv[] = {size_t(t)};
  //   //*****REMEMBER THAT IN C THE FRAMES ARE NUMBERED 0 TO T-1 WHILE IN MATLAB THEY ARE NUMBERED 1 TO T******************
  //   // size_t gv[] = {size_t(t-1), size_t(t)};
  //   gm.addFactor(fid, fv, fv+1);
  //   // if (t > 0)
  //   //   gm.addFactor(gid, gv, gv+2);
  // }

  //  inference
  const size_t maxIterations=100;
  const double damping=0.0;
  const double tolerance=1e-5;
  // libdaiBp::UpdateRule = PARALL | SEQFIX | SEQRND | SEQMAX
  libdaiBP::UpdateRule updateRule = libdaiBP::PARALL;
  size_t verboseLevel=0;
  libdaiBP::Parameter parameter(maxIterations, damping, tolerance, updateRule,verboseLevel);
  libdaiBP bp(gm, parameter);
  // optimize (approximately)
  clock_t t1, t2;
  t1 = clock();
  bp.infer( );
  t2 = clock();
  std::cout << (double(t2) - double(t1))/CLOCKS_PER_SEC*1000 << " ms" << std::endl;
  std::cout << "libDAI Belief Propagation " << -bp.value() << std::endl;
  std::vector<size_t> labeling(T); 
  bp.arg(labeling);
  for (unsigned int i = 0; i < labeling.size(); i ++)
    boxes[i] = int(labeling[i]);
  delete [] vars;
  return -bp.value();
}
