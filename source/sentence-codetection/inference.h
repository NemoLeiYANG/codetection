double bp_object_inference(double **f, double **g, int T, int top_k, 
			   double dummy_f, double dummy_g, 
			   int num_gscores, int *boxes);

// double bp_label_inference(int num_peaks, int num_labels,
// 			  double f_value, double **g, int *labels);

double bp_label_inference_original(int num_peaks, int num_labels,
				   double f_value, double default_g_value, 
				   double **g, double dummy_g, int *labels);
