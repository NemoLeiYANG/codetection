// g++ -Wall -O2 -D IL_STD -o st.o -I ~ -I ~/libDAI/include beliefp-st-qobi.cpp -L ~/libDAI/lib -ldai -lgmpxx -lgmp

#include <cstdio>
#include <cstdarg>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <cstring>
#include "opengm/graphicalmodel/graphicalmodel.hxx"
#include "opengm/graphicalmodel/space/discretespace.hxx"
#include "opengm/functions/explicit_function.hxx"
#include "opengm/operations/adder.hxx"
#include "opengm/operations/minimizer.hxx"
#include "opengm/inference/external/libdai/bp.hxx"

typedef opengm::DiscreteSpace<> Space;
typedef opengm::ExplicitFunction<double> Function;
typedef opengm::GraphicalModel<double, opengm::Adder, Function, Space> GraphModel;
typedef GraphModel::FunctionIdentifier FID;
typedef opengm::external::libdai::Bp<GraphModel, opengm::Minimizer> libdaiBP;

#define MINUS_INF -(1.0/0.0)

/// do not change the above code

double sentence_tracker(){
  
  //////// 1
  size_t *vars = new size_t[vars_n];
  ///////////////

  vars[i] = n;  // -> each variable i has n labels


  /////// 2
  Space space(vars, vars + vars_n);
  GraphModel gm(space);
  /////////////////////


  /////// 3 add funtions
  ///// unary
  // for each node x, defining unary cost
  size_t fshape[] = {n_labels_for_x}; 
  Function ff(fshape, fshape+1, -MINUS_INF);
  // for label i
  ff(i) = i*i;

  FID fid;
  fid = gm.addFunction(ff);
  
  // for each node x, define factors
  size_t fv[] = {x};
  gm.addFactor(fid, fv, fv+1);

  
  //// binary
  size_t gshape[] = {n_labels_for_x, n_labels_for_y};
  Function gg(gshape, gshape+2, -MINUS_INF);
  // for each label i of x and label j of y
  gg(i,j) = i*j;

  FID gid;
  gid = gm.addFunction(gg);
  
  // for each pair of nodes x and y
  size_t gv[] = {x, y};
  gm.addFactor(gid, gv, gv+2);

  ////// 4 inference (maybe also do not change code below)
  const size_t maxIterations=100;
  const double damping=0.0;
  const double tolerance=1e-5;
  // libdaiBp::UpdateRule = PARALL | SEQFIX | SEQRND | SEQMAX
  libdaiBP::UpdateRule updateRule = libdaiBP::PARALL;
  size_t verboseLevel=0;
  libdaiBP::Parameter parameter(maxIterations, damping, tolerance, updateRule, verboseLevel);
  libdaiBP bp(gm, parameter);                                        
  // optimize (approximately)
  bp.infer();
  double score = -bp.value();
  // you probably should call another function to get the indices out from bp
  delete [] vars;
  return score;
}

int main(){
  return 0;
}
