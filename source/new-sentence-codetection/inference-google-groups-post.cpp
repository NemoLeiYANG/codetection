#include <cstdio>
#include <cstdarg>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <cstring>
#include <ctime>
#include <vector>
#include <map>
#include "opengm/functions/sparsemarray.hxx"
#include "opengm/graphicalmodel/graphicalmodel.hxx"
#include "opengm/graphicalmodel/space/discretespace.hxx"
#include "opengm/functions/explicit_function.hxx"
#include "opengm/operations/adder.hxx"
#include "opengm/operations/minimizer.hxx"
#include "opengm/inference/messagepassing/messagepassing.hxx"
#include "opengm/inference/external/libdai/bp.hxx"

typedef opengm::DiscreteSpace<> Space;
typedef opengm::ExplicitFunction<double> Function;
typedef opengm::SparseFunction<double,size_t,size_t> SparseFunction;
typedef opengm::meta::TypeListGenerator<Function, SparseFunction>::type FunctionTypeList;
typedef opengm::GraphicalModel<double, opengm::Adder, FunctionTypeList, Space> GraphModel;
typedef GraphModel::FunctionIdentifier FID;
typedef opengm::BeliefPropagationUpdateRules<GraphModel, opengm::Minimizer> UpdateRules;
typedef opengm::MessagePassing<GraphModel, opengm::Minimizer, UpdateRules, opengm::MaxDistance> BP;
typedef opengm::external::libdai::Bp<GraphModel, opengm::Minimizer> libdaiBP;

extern "C" double bp_object_inference(double **f, double **g, 
				      int T, int top_k, int dummy_f, int dummy_g,
				      int *boxes) {

  // each frame has a variable with top_k possible labels
  // ACTUALLY USING TOP_K+1 LABELS NOW WITH THE DUMMY STATE
  size_t *vars = new size_t[T];
  for (int t = 0; t < T; t ++)
    vars[t] = top_k+1; //extra label for dummy state
  Space space(vars, vars + T);
  GraphModel gm(space);
  // add funtions
  for (int t = 0; t < T; t ++){
    FID fid, gid;
    size_t fshape[] = {size_t(top_k)+1}; 
    //TBD size_t gshape[] = ??
    Function ff(fshape, fshape+1, dummy_f); 
    //TBD SparseFunction gg(??)
    for (int i = 0; i < top_k; i ++){
      ff(i) = -f[t][i];
      //TBD initialize gg values
    }
    fid = gm.addFunction(ff);
    //TBD gid = gm.addFunction(gg);

    // add factors
    size_t fv[] = {size_t(t)};
    //TBD size_t gv[] = ??
    gm.addFactor(fid, fv, fv+1);
    //TBD gm.addFactor(??)
  }

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
