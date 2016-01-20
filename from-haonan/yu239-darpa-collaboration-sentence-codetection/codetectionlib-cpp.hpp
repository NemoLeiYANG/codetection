#ifndef CODETECTIONLIB_CPP_HPP
#define CODETECTIONLIB_CPP_HPP

#include <vector>
#include <unordered_map>
#include <utility>

template <class T>
inline void hash_combine(std::size_t & seed, const T & v)
{
  std::hash<T> hasher;
  seed ^= hasher(v) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
}

namespace std
{
  template<typename S, typename T> struct hash<pair<S, T>>
  {
    inline size_t operator()(const pair<S, T> & v) const
    {
      size_t seed = 0;
      ::hash_combine(seed, v.first);
      ::hash_combine(seed, v.second);
      return seed;
    }
  };
}

typedef std::pair<int,int> PII;
typedef std::unordered_map<PII,double**> SparseMat;

void graphical_model_scores(double ***f, double ***u, double ***h, double ****boxes_menu, 
			    double *****g2, int J, int *Ts, int *Ms, int *Qs, int **predicates, int W,
			    int *v_ids, int **grouped_objects, int *Ns, int mode, int top_k,
			    // output
			    std::vector<double>& unary,
			    SparseMat& binary);

#endif
