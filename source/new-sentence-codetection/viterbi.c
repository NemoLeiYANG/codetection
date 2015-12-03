// int t is a frame
// int T is the number of frames
// int P[t] is the number of proposals in frame t
// int p is a proposal index
// double f[t][p] is the unary score of proposal p in frame t
// double g[t][p1][p] is the binary score between proposal p1 in frame t-1 and
//   proposal p in frame t
// double l[t][p] is the lattice value
// int lp[t][p] is the lattice index
// double lT is the score
// int lTp is the selected proposal in frame T-1
//   if p is the selected proposal in frame t then lp[t][p] is the selected
//   proposal in frame t-1
void viterbi(void) {
  for (int p = 0; p<P[0]; p++) l[0][p] = f[0][p];
  for (int t = 1; t<T; t++) {
    for (int p = 0; p<P[t]; p++) {
      l[t][p] = -INFINITY;
      for (int p1 = 0; p1<P[t-1]; p1++) {
	if (l[t-1][p1]+g[t][p1][p]>l[t][p]) {
	  l[t][p] = l[t-1][p1]+g[t][p1][p];
	  lp[t][p] = p1;
	}
      }
      l[t][p] += f[t][p];
    }
  }
  lT = -INFINITY;
  lTp;
  for (int p = 0; p<P[T-1]; p++) {
    if (l[T-1][p]>lT) {
      lT = l[T-1][p];
      lTp = p;
    }
  }
}

void free_viterbi(void) {
  for (int t = 0; t<T; t++) {
    free(f[t]);
    if (t>0) for (int p1 = 0; p1<P[t]; p1++) free(g[t][p1]);
    free(l[t]);
    free(lp[t]);
  }
  free(P);
}
