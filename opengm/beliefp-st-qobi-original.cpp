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

/* T is the number of frames
   L is the number of tracks
   O is the number of classes
   I1 is the number of single-detection features
   I2 is the number of detection-pair features
   E is the number of entries
   W is the number of words
   K[e] is the number of states for entry e
   R[e] is the number of roles for entry e
   Phi1[i] the number of feature values for single-detection feature i
   Phi2[i] the number of feature values for detection-pair feature i
   b[e][k] is the initial-state probability for state k of entry e
   a[e][k0][k1] is the transition probability from state k0 to state k1 of
   entry e
   z[e][k] is the final-state probability for state k of entry e
   c[e][k][i][phi] is the output probability for feature-value phi of feature
   i for state k for entry e
   J[t][o] is the number of detections for class o in frame t
   f[t][o][j] is the score for detection j of class o in frame t
   g[t][o][j0][j1] is the temporal coherency score between detection j0 of
   class o in frame t-1 and detection j1 of class o in frame t
   e[w] is the entry index for word w
   l[w][r] is the track for role r of word w
   phi1[t][o][j][i] is the quantized single-detection feature value for
   feature i of detection j of class o in frame t   
   phi2[t][o0][j0][o1][j1][i] is the quantized detection-pair feature value for
   feature i of detections j0 of class o0 and j1 of class o1 in frame t
*/

double sentence_tracker(unsigned int T,
			unsigned int L,
			unsigned int O,
			unsigned int I1,
			unsigned int I2,
			unsigned int E,
			unsigned int W,
			unsigned int *K,
			unsigned int *R,
			unsigned int *Phi1,
			unsigned int *Phi2,
			double **b,
			double ***a,
			double **z,
			double ****c,
			unsigned int **J,
			double ***f,
			double ****g,
			unsigned int ****phi1,
			unsigned int ******phi2,
			unsigned int *e,
			unsigned int **l){
  size_t i, j, k, t, w, u, v, ww=W, o;
  size_t vars_t = L+ww;
  size_t *vars = new size_t[T*vars_t];
  size_t iis[T];  // iis[t]: the total number of detections in frame t
  for (t = 0; t < T; t ++){
    iis[t] = 0;
    for (o = 0; o < O; o ++)
      iis[t] += J[t][o];
  }

  // build graphical model
  for (t = 0; t < T; t ++){
    for (j = 0; j < L; j ++)
      vars[t*vars_t+j] = iis[t];
    for (w = 0; w < ww; w ++)
      vars[t*vars_t+L+w] = K[e[w]];
  }
  Space space(vars, vars + T*vars_t);
  GraphModel gm(space);
  
  // add funtions
  // ==== f and g ==== //
  for (t = 0; t < T; t ++){
    FID fid, gid;
    size_t fshape[] = {iis[t]}; 
    // gshape will never be used when t == 0
    size_t gshape[] = {(t>0?iis[t-1]:iis[t]), iis[t]};
    Function ff(fshape, fshape+1, -MINUS_INF);
    Function gg(gshape, gshape+2, -MINUS_INF);
    i = 0;
    for (size_t o1 = 0; o1 < O; o1 ++)     
      for (size_t j1 = 0; j1 < J[t][o1]; j1 ++){
	ff(i) = -f[t][o1][j1];
	if (t > 0){
	  k = 0;
	  for (size_t o2 = 0; o2 < O; o2 ++)
	    for (size_t j2 = 0; j2 < J[t-1][o2]; j2 ++){
	      if (o2 == o1)
		gg(k,i) = -g[t][o2][j2][j1];
	      k ++;
	    }
	}
	i ++;
      }
    fid = gm.addFunction(ff);
    if (t > 0)
      gid = gm.addFunction(gg);
    // add factors
    for (j = 0; j < L; j ++){
      size_t fv[] = {t*vars_t+j};
      size_t gv[] = {(t-1)*vars_t+j, t*vars_t+j};
      gm.addFactor(fid, fv, fv+1);
      if (t > 0)
	gm.addFactor(gid, gv, gv+2);
    }
  }

  // ==== a and b ==== //
  for (w = 0; w < ww; w ++){
    size_t uu = K[e[w]];
    FID bid, aid;
    size_t bshape[] = {uu};
    size_t ashape[] = {uu, uu};
    Function bb(bshape, bshape+1, -MINUS_INF);
    Function aa(ashape, ashape+2, -MINUS_INF);
    for (u = 0; u < uu; u ++){
      bb(u) = -b[e[w]][u];
      for (v = 0; v < uu; v ++)
	aa(v,u) = -a[e[w]][v][u];
    }  
    bid = gm.addFunction(bb);
    aid = gm.addFunction(aa);
    // add factors
    for (t = 0; t < T; t ++){      
      size_t bv[] = {t*vars_t+L+w};
      // av will never be used when t == 0
      size_t av[] = {(t-1)*vars_t+L+w, t*vars_t+L+w};
      if (t == 0)
  	gm.addFactor(bid, bv, bv+1);
      else
  	gm.addFactor(aid, av, av+2);
    }
    // final state
    FID zid;
    size_t zshape[] = {uu};
    Function zz(zshape, zshape+1, -MINUS_INF);
    size_t zv[] = {(T-1)*vars_t+L+w};
    for (u = 0; u < uu; u ++)
      zz(u) = -z[e[w]][u];
    zid = gm.addFunction(zz);
    gm.addFactor(zid, zv, zv+1);
  }
  
  // ==== h ==== //
  int n_roles;
  for (t = 0; t < T; t ++){
    for (w = 0; w < ww; w ++){
      n_roles = R[e[w]];
      assert(n_roles < 3 && n_roles > 0);
      FID hid;
      size_t fshape[3];
      if (n_roles == 1)
  	fshape[0] = iis[t], fshape[1] = K[e[w]];
      else
  	fshape[0] = fshape[1] = iis[t], fshape[2] = K[e[w]];
      Function h(fshape, fshape+n_roles+1, -MINUS_INF);
      for (u = 0; u < K[e[w]]; u ++){
	i = 0;
	for (size_t o1 = 0; o1 < O; o1 ++)     
	  for (size_t j1 = 0; j1 < J[t][o1]; j1 ++){	    
	    if (n_roles == 2){
	      k = 0;	      
	      for (size_t o2 = 0; o2 < O; o2 ++)
		for (size_t j2 = 0; j2 < J[t][o2]; j2 ++){				
		  double like = 0;
		  for (size_t i1 = 0; i1 < I1; i1 ++) {
		    // sum all of the one-argument features for the first argument
		    // of two-argument words
		    like +=
		      c
		      [e[w]]
		      [u]
		      [i1]
		      [phi1[t][o1][j1][i1]];
		    // sum all of the one-argument features for the second argument
		    // of two-argument words
		    like +=
		      c
		      [e[w]]
		      [u]
		      [I1+i1]
		      [phi1[t][o2][j2][i1]];
		  }
		  // sum all of the two-role features for two-argument words
		  for (size_t i2 = 0; i2 < I2; i2 ++) {
		    like +=
		      c
		      [e[w]]
		      [u]
		      [2*I1+i2]
		      [phi2[t][o1][j1][o2][j2][i2]];
		  }
		  h(i,k,u) = -like;
		  k ++;
		}
	    }
	    else{
	      double like = 0;
	      for (size_t i1 = 0; i1 < I1; i1++) {
		like +=
		  c
		  [e[w]]
		  [u]
		  [i1]
		  [phi1[t][o1][j1][i1]];
	      }
	      h(i,u) = -like;
	    }
	    i ++;
  	}
      }
      hid = gm.addFunction(h);
      // add factors
      size_t hv[3];
      if (n_roles == 1)
  	hv[0] = t*vars_t+l[w][0], hv[1] = t*vars_t+L+w;
      else {
  	hv[0] = t*vars_t + l[w][0];
  	hv[1] = t*vars_t + l[w][1];
  	hv[2] = t*vars_t + L + w;
      }
      gm.addFactor(hid, hv, hv+n_roles+1);
    }
  }

  // ==== inference ==== //
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
  delete [] vars;
  return score;
}

int main(){
  return 0;
}
