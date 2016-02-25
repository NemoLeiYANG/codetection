double bp_sentence_codetection_inference(int num_nouns, int num_tubes,
					 double **unary_score_matrix,
					 int num_helper_nouns,
					 int **helper_noun_pairs_matrix,
					 double ***helper_noun_scores_matrix,
					 int num_matching_noun_pairs,
					 int **matching_noun_pairs_matrix,
					 double **visual_similarity_matrix,
					 int *output_tubes);
			       // double **f, double **g, int T, int top_k, 
			       // double dummy_f, double dummy_g, 
			       // int num_gscores, int *boxes);

double bp_sentence_codetection_inference_simple(int num_nouns, int num_tubes,
						double **unary_score_matrix,
						int num_helper_nouns,
						int **helper_noun_pairs_matrix,
						double ***helper_noun_scores_matrix,
						int *output_tubes);

double run_inference_1and2(double **f, double **g, int T, int top_k, double dummy_f, 
			   double dummy_g,int num_gscores, int *boxes);

double run_inference_4(double **f, double **g, int T, int top_k, double dummy_f, 
			   double dummy_g,int num_gscores, int *boxes);

void elementwise_2d_matrix_multiply(int rows, int cols, 
				    double **mat1, double **mat2, double **outmat);

double bp_object_inference_new(double **f, double **g, int T, int top_k, 
			       double dummy_f, double dummy_g, 
			       int num_gscores, int *boxes);

double bp_object_inference(double **f, double **g, int T, int top_k, 
			   double dummy_f, double dummy_g, 
			   int num_gscores, int *boxes);

double bp_label_inference(int num_peaks, int num_labels,
			  double f_value, double **g, int *labels);

double bp_label_inference_original(int num_peaks, int num_labels,
				   double f_value, double default_g_value, 
				   double **g, double dummy_g, int *labels);
double bruteforce_label_inference(int num_peaks, int num_labels,
				  double f_value, double **g, int *labels);

double label_inference_test_with_noise(int num_peaks, int num_labels,
				       double f_value, double **g, int *labels, 
				       int numIterations, float noiseLimit);

double label_inference_with_noise(int num_peaks, int num_labels,
				  double f_value, double **g, 
				  int *labels, int numIterations, 
				  double noiseLimit, double tol);


