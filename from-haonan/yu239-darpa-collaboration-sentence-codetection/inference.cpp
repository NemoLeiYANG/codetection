#include <cstdio>
#include <cstdarg>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <cstring>
#include <ctime>
#include <vector>
extern "C"{
#include "inference.h"
}
#include "inference.hpp"
#include "codetectionlib-cpp.hpp"
#include "omp.h"
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

extern int track_constraint;

/* J - object group number
   f[n][t][k] - flow score
   u[n][t][k] - color saliency
   g[n][t][k][k'] - temporal coherence
   boxes_menu[n][t][k] - x1 y1 x2 y2 score
   g2[j][m][q][k][l] - similarity within one object group
   Ts[n] - video length
   Ms[j] - number of similarity pairs in group j
   Qs[j] - selected frame number for similarity in group j
   W - number of predicates
   predicates[w] - [0] predicate-id [1,2] object-id 
   v_ids[z] - video idx for object z
   grouped_objects[j][n] - the id of the nth object in group j 
   Ns[j] - number of objects in group j   
*/
extern "C" double bp_sentences_inference
(double ***f, double ***u, double ***h, double ****boxes_menu, double *****g2,
 int J, int *Ts, int *Ms, int *Qs, int **predicates, int W,
 int *v_ids, int **grouped_objects, int *Ns, int mode, int top_k,	 
 // output
 int *boxes){
 
 std::vector<double> unary;
  SparseMat binary;
  graphical_model_scores(f, u, h, boxes_menu, g2, J, Ts, Ms, Qs, predicates, W, v_ids,
			 grouped_objects, Ns, mode, top_k, unary, binary);
  
  int Z = 0; // total number of distinct tracks
  for (int j = 0; j < J; j ++) Z += Ns[j];
  // each track is a variable, in total Z
  size_t *vars = new size_t[Z];
  for (int z = 0; z < Z; z ++) vars[z] = top_k;
  Space space(vars, vars + Z);
  GraphModel gm(space);
  
  // add unary
  size_t fgshape[] = {size_t(top_k)}; 
  for (int z = 0; z < Z; z ++){
    Function fg(fgshape, fgshape+1, INFINITY);
    for (int i = 0; i < top_k; i ++)
      fg(i) = -unary[z*top_k+i];
    FID fgid = gm.addFunction(fg);
    // add factors
    size_t fgv[] = {size_t(z)};
    gm.addFactor(fgid, fgv, fgv+1);
  }

  // add binary
  size_t g2shape[] = {size_t(top_k), size_t(top_k)};
  for (SparseMat::iterator it = binary.begin(); it != binary.end(); it ++){
    PII key = it->first;
    double** score_mat = it->second;
    Function g2g(g2shape, g2shape+2, INFINITY);
    int z1 = key.first, z2 = key.second;
    for (int i = 0; i < top_k; i ++)
      for (int k = 0; k < top_k; k ++)
	g2g(i,k) = -score_mat[i][k];
    FID g2id = gm.addFunction(g2g);
    size_t g2v[] = {size_t(z1), size_t(z2)};
    gm.addFactor(g2id, g2v, g2v+2);
    // free table
    for (int i = 0; i < top_k; i ++)
      delete [] score_mat[i];
    delete [] score_mat;
  }

  //  inference
  const size_t maxIterations=100;
  const double damping=0.0;
  const double tolerance=1e-7;
  // libdaiBp::UpdateRule = PARALL | SEQFIX | SEQRND | SEQMAX
  libdaiBP::UpdateRule updateRule = libdaiBP::PARALL;
  size_t verboseLevel=0;
  libdaiBP::Parameter parameter(maxIterations, damping, tolerance, updateRule,verboseLevel);
  libdaiBP bp(gm, parameter); 
  
  // optimize (approximately)
  clock_t t1, t2;
  t1 = clock();
  bp.infer();
  t2 = clock();
  std::cout << (double(t2) - double(t1))/CLOCKS_PER_SEC*1000 << " ms" << std::endl;
  std::cout << "MAP with Belief Propagation " << -bp.value() << std::endl;
  std::vector<size_t> labeling(Z); 
  bp.arg(labeling);
  int cnt = 0;
  for (unsigned int z = 0; z < labeling.size(); z ++){
    std::cout << "labeling: " << labeling[z] << std::endl;
    for (int t = 0; t < Ts[v_ids[z]]; t ++)
      boxes[cnt++] = int(labeling[z]);
  }
  delete [] vars;
  return -bp.value();
}
