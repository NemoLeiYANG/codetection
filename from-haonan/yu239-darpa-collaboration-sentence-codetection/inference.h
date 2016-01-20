/*
 *  Different Scheme->C APIs for codetection
 */

double bp_sentences_inference(double ***f, double ***u, double ***h, double ****boxes_menu, 
			      double *****g2, int J, int *Ts, int *Ms, int *Qs, int **predicates, 
			      int W, int *v_ids, int **grouped_objects, int *Ns, int mode, int top_k,	 
			      // output
			      int *boxes);
