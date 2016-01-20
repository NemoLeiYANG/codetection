#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include <unordered_set>
#include <assert.h>
#include <time.h>
#include <fftw3.h>
#include <cmath>
#include <fstream>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/utility.hpp>
#include <opencv2/tracking/tracker.hpp>
#include <opencv2/features2d/features2d.hpp>
#include <opencv2/calib3d/calib3d.hpp>
#include <opencv2/xfeatures2d/nonfree.hpp>
#include <opencv2/video/tracking.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>
#include "omp.h"
#include "codetectionlib-cpp.hpp"
#include "inference.hpp"
extern "C"{
#include "codetectionlib-c.h"
}

#define LOG_2PI 1.837877
#define MAX_CMD_N 100
#define MINI_OBJ 5e-3
#define BIG_OBJ 5e-2
#define DIST_THRES_LARGE 0.25
#define DIST_THRES_SMALL 0.05
#define VIDEO_START 15
#define NMS_THRES 0.8
//#define IM_W 768.0
//#define IM_H 432.0
#define SIGMOID_B 20

enum MoveDir {MOVE_UP, MOVE_DOWN, MOVE_HORI, MOVE, MOVE_LEFT, MOVE_RIGHT, MOVE_VERT};
enum SpatialType {TO_THE_LEFT_OF, TO_THE_RIGHT_OF, CLOSE, IN, ON_TOP_OF, CLOSER, FURTHER, BELOW, ABOVE};

typedef cv::xfeatures2d::SIFT SIFT;

/* ======= gloabl variables that can be changed by scheme ====== */
volatile int track_constraint = 1;
volatile int n_orientations = 1;
volatile int video_fps = 20;
volatile int sentence_directed = 0;
volatile double _gamma_ = 0;
volatile double IM_W = 0;
volatile double IM_H = 0;

extern "C" void set_track_constraint(int c){
  track_constraint = c;
}

extern "C" void set_video_fps(int fps){
  video_fps = fps;
}

extern "C" void set_n_orientations(int n){
  n_orientations = n;
}

// 0: with sentential information
// 1: with only binary movement information (yes/no)
// 2: without any sentential information
extern "C" void set_sentence_directed(int b){
  sentence_directed = b;
}

extern "C" void set_gamma(double g){
  _gamma_ = g;
}

extern "C" void set_imw(double w) {
  IM_W = w;
}

extern "C" void set_imh(double h) {
  IM_H = h;
}

void get_pairs(int N, int mode, std::vector<int>& m1, std::vector<int>& m2){
  m1.clear(); m2.clear();
  if (mode <= 1){
    for (int n = 0; n < N-1; n ++){
      m1.push_back(n); m2.push_back(n+1);
    }
    if (mode==1 && N>1){
      m1.push_back(0); m2.push_back(N-1);
    }
  }
  else{
    assert(mode == 2);
    for (int n = 0; n < N; n ++)
      for (int n_ = n+1; n_ < N; n_ ++){
	m1.push_back(n); m2.push_back(n_);
      }
  }
}

double bessi0(double x){ 
  double ax;
  double y;
  if ((ax = fabs(x))<3.75){ 
    y = x/3.75;
    y *= y;
    return 1.0+y*(3.5156229
		  +y*(3.0899424
		      +y*(1.2067492
			  +y*(0.2659732+y*(0.360768e-1+y*0.45813e-2)))));
  }
  else{ 
    y = 3.75/ax;
    return exp(ax-0.5*log(ax))
      *(0.39894228
	+y*(0.1328592e-1
	    +y*(0.225319e-2
		+y*(-0.157565e-2
		    +y*(0.916281e-2
			+y*(-0.2057706e-1
			    +y*(0.2635537e-1
				+y*(-0.1647633e-1
				    +y*0.392377e-2))))))));
  }
}

double log_vonmises(double x, double mean, double kappa){ 
  assert(kappa >= 0);
  if(abs(x - M_PI) < 1e-10)    // PI -> -PI
    x = -M_PI;
  assert(mean>=-M_PI && mean<M_PI);
  assert(x>=-M_PI && x< M_PI);	/* wear goggles */
  x -= mean;
  return kappa*cos(x) - LOG_2PI - log(bessi0(kappa));
}

void compute_dense_flow(const cv::Mat& im1, const cv::Mat& im2, cv::Mat& flow){
  assert(im1.rows==im2.rows && im2.cols==im2.cols);
  cv::Mat prev, next;
  cv::cvtColor(im1, prev, CV_BGR2GRAY);
  cv::cvtColor(im2, next, CV_BGR2GRAY);
  cv::calcOpticalFlowFarneback(prev,
			       next,
			       flow, // h*w type CV_32FC2 (fixed)
			       0.5,  // pyr_scale
			       1,    // levels
			       8,    // winsize
			       10,   // iterations
			       5,    // poly_n
			       1.1,  // poly_sigma
			       0);  
}

void compute_integral_flow(const cv::Mat& im1, const cv::Mat& im2,
			   cv::Mat& integral_flow){
  /* im1 - first 8-bit three-channel input image (CV_8UC3)
     im2 - second input image with the same size and type as im1
     integral_flow - output flow image with size (h+1)*(w+1) and type CV_32FC2
     the first row and column are all zeros
     the first channel is x, the second channel is y
  */ 
  cv::Mat flow;
  compute_dense_flow(im1, im2, flow);
  cv::integral(flow, integral_flow, CV_64F);
}

// needswork: maybe should use quick-select (O(n))
double median(const std::vector<double>& lst, double fraction){
  std::vector<double> tmp_lst(lst.size());
  std::copy(lst.begin(), lst.end(), tmp_lst.begin());
  std::sort(tmp_lst.begin(), tmp_lst.end());
  return tmp_lst[int(lst.size()*fraction)];
}

cv::Vec2d average_flow_in_rect(const cv::Rect& rect, const cv::Mat& integral_flow){
  int y1 = rect.y;
  int x1 = rect.x;
  int y2 = y1 + rect.height - 1;
  int x2 = x1 + rect.width - 1;
  double area = rect.height * rect.width;
  cv::Vec2d tl = ((y1==0||x1==0)? cv::Vec2d(0,0): integral_flow.at<cv::Vec2d>(y1-1, x1-1));
  cv::Vec2d tr = (y1==0? cv::Vec2d(0,0): integral_flow.at<cv::Vec2d>(y1-1, x2));
  cv::Vec2d bl = (x1==0? cv::Vec2d(0,0): integral_flow.at<cv::Vec2d>(y2, x1-1));
  cv::Vec2d br = integral_flow.at<cv::Vec2d>(y2, x2);
  return (br-tr-bl+tl) * (1.0/area);
}

cv::Vec2d median_flow_in_rect(const cv::Rect& rect, const cv::Mat& flow){
  std::vector<double> xs, ys;

  for (int i = rect.y; i < rect.y+rect.height; i ++)
    for (int j = rect.x; j < rect.x+rect.width; j ++){
      cv::Vec2f pix = flow.at<cv::Vec2f>(i,j);
      xs.push_back(pix[0]);
      ys.push_back(pix[1]);
    }
  return cv::Vec2d(median(xs,0.8), median(ys,0.8));
}

static double sigmoid(double x, double a, double b){
  return 1.0 / (1 + exp(- b * (x - a)));
}

double box_x(double *box){
  return (box[0] + box[2]) / 2;
}

double box_y(double *box){
  return (box[1] + box[3]) / 2;
}

double box_dist2(double *box1, double *box2){
  double dx = box_x(box1) - box_x(box2);
  double dy = box_y(box1) - box_y(box2);
  return dx*dx + dy*dy;
}

double box_dist(double *box1, double *box2){
  return sqrt(box_dist2(box1, box2));
}

double box_height(double *box){
  return box[3] - box[1] + 1;
}

double box_width(double *box){
  return box[2] - box[0] + 1;
}

double box_area(double *box){
  return box_height(box)*box_width(box);
}

cv::Rect average_boxes(const cv::Rect& box1, const cv::Rect& box2){
  return cv::Rect(int((box1.x+box2.x)/2),
		  int((box1.y+box2.y)/2),
		  int((box1.width+box2.width)/2),
		  int((box1.height+box2.height)/2));
}

cv::Rect box2cvrect(double *box, double scale = 1){
  // sometimes there will be box with height or width equal to 1
  return cv::Rect(int(box[0]*scale), int(box[1]*scale),
		  MAX(1,int((box[2]-box[0]+1)*scale)), MAX(int((box[3]-box[1]+1)*scale),1));
}

double IoU(const cv::Rect& b1, const cv::Rect& b2){
  double max_x1 = MAX(b1.x, b2.x);
  double min_x2 = MIN(b1.x+b1.width-1, b2.x+b2.width-1);
  double max_y1 = MAX(b1.y, b2.y);
  double min_y2 = MIN(b1.y+b1.height-1, b2.y+b2.height-1);
  if (min_x2<=max_x1 || min_y2 <= max_y1)
    return 0;
  double intersected_area = (min_x2-max_x1+1)*(min_y2-max_y1+1);
  //  double union_area = b1.area() + b2.area() - intersected_area;
  double union_area = MIN(b1.area(), b2.area());
  return intersected_area / union_area;
}

double IoU_tubes(const std::vector<cv::Rect>& tube1,
		 const std::vector<cv::Rect>& tube2){
  double overlap = -INFINITY;
  for (unsigned int i = 0; i < tube1.size(); i ++)
    overlap = MAX(overlap, IoU(tube1[i], tube2[i]));
  //  return overlap / tube1.size();
  return overlap;
}

double rect_distance(const cv::Rect& r1, const cv::Rect& r2){
  double x1 = r1.x + r1.width/2.0;
  double y1 = r1.y + r1.height/2.0;
  double x2 = r2.x + r2.width/2.0;
  double y2 = r2.y + r2.height/2.0;
  return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

int cdf_binary_search(std::vector<double>& a, int l, int r, double p){
  int m = (l+r) / 2;
  if ((m == 0 && p <= a[m])
      || (m > 0 && p > a[m-1] && p <= a[m]))
    return m;
  if (p > a[m])
    return cdf_binary_search(a, m+1, r, p);
  else
    return cdf_binary_search(a, l, m-1, p);
}

int sample_from_cdf(std::vector<double> dist){
  double point = ((double) rand() / (RAND_MAX));
  return cdf_binary_search(dist, 0, dist.size()-1, point);
}

double coherence_score(double *box1, double *box2, double fx, double fy){
  double x1, y1, x2, y2, h1, w1, h2, w2;
  double dist;
  x1 = box_x(box1); y1 = box_y(box1);
  x2 = box_x(box2); y2 = box_y(box2);
  x1 += fx; y1 += fy;
  dist = sigmoid(sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)), 5, -0.2);
  h1 = box_height(box1); w1 = box_width(box1);
  h2 = box_height(box2); w2 = box_width(box2);
  double ratio = MAX(w1,h1)*MIN(w2,h2)/MIN(w1,h1)/MAX(w2,h2);
  // return -MAX(dist,
  // 	      fabs(log(ratio)));
  return log(dist) - fabs(log(ratio));
}

cv::Rect resize_box(const cv::Rect& box, int im_width, int im_height, double scale = 0.5){
  double cx = (box.x+box.x+box.width-1) / 2;
  double cy = (box.y+box.y+box.height-1) / 2;
  double new_width = box.width * scale;
  double new_height = box.height * scale;
  // can be done with rect & rect intersection
  double x1 = MAX(0, cx-new_width/2);
  double y1 = MAX(0, cy-new_height/2);
  double x2 = MIN(im_width-1, cx+new_width/2);
  double y2 = MIN(im_height-1, cy+new_height/2);
  return cv::Rect(int(x1), int(y1), int(x2-x1+1), int(y2-y1+1));
}

std::string type2str(int type) {
  std::string r;
  uchar depth = type & CV_MAT_DEPTH_MASK;
  uchar chans = 1 + (type >> CV_CN_SHIFT);
  switch ( depth ) {
  case CV_8U:  r = "8U"; break;
  case CV_8S:  r = "8S"; break;
  case CV_16U: r = "16U"; break;
  case CV_16S: r = "16S"; break;
  case CV_32S: r = "32S"; break;
  case CV_32F: r = "32F"; break;
  case CV_64F: r = "64F"; break;
  default:     r = "User"; break;
  }
  r += "C";
  r += (chans+'0');
  return r;
}

void mnd_threshold(cv::Mat& mat, double threshold, double max_val){
  // binarizing a multi-dimension cv::Mat needs manual effort
  for (unsigned int i = 0; i < mat.total(); i ++){
    float *val = (float*)mat.data + i;
    if (*val <= threshold) *val = 0;
    else *val = max_val;
  }
}

// normalize [a1,b1] to [a2,b2]
// (x-a1)/(b1-a1)*(b2-a2) + a2
void mnd_minmax_normalize(cv::Mat& mat, double a2, double b2){  
  assert(b2 > a2);
  double a1, b1;
  cv::minMaxIdx(mat, &a1, &b1, 0, 0);
  for (unsigned int i = 0; i < mat.total(); i ++){
    float *val = (float*)mat.data + i;
    *val = (*val-a1)/(b1-a1)*(b2-a2) + a2;
  }
}

void calc_histogram(const cv::Mat& roi, int channels[], cv::MatND& ref_hist, int dims,
		    int hist_size[], const float* ranges[], const cv::Mat& mask = cv::Mat(), 
		    bool uniform = true){
  cv::calcHist(&roi, 1, channels, mask, ref_hist, 
  	       dims, hist_size, ranges, uniform, false);
  cv::normalize(ref_hist, ref_hist, 1, 0, cv::NORM_L1);
}

double chisq(const cv::MatND& hist1, const cv::MatND& hist2){
  double dist = 0;
  for (unsigned int i = 0; i < hist1.total(); i ++){
    float *x = (float*)hist1.data + i;
    float *y = (float*)hist2.data + i;
    if (*x + *y != 0)
      dist += (*x-*y)*(*x-*y)/(*x+*y)/2;
  }
  return dist;
}

cv::MatND get_ref_hist(const cv::Mat& ref_im, const cv::Rect& box, const cv::Mat& mask,
		       int dims, int *hist_size, const float** ranges, int* channels, bool uniform = true){
  int im_width = ref_im.cols;
  int im_height = ref_im.rows;
  
  cv::Mat ref_roi;
  cv::MatND ref_hist, ref_hist_out, ref_hist_in, ref_hist_idx;
  cv::Rect rbox;      
 
  ref_roi = ref_im(box);
  calc_histogram(ref_roi, channels, ref_hist, dims, hist_size, ranges, mask(box), uniform);

  double larger = 2;
  rbox = resize_box(box, im_width, im_height, larger);
  ref_roi = ref_im(rbox);
  calc_histogram(ref_roi, channels, ref_hist_out, dims, hist_size, ranges, mask(rbox), uniform);
  ref_hist_idx = ref_hist - ref_hist_out;
  mnd_threshold(ref_hist_idx, 0, 1);
  ref_hist = ref_hist.mul(ref_hist_idx);

  double smaller = 0.5;
  rbox = resize_box(box, im_width, im_height, smaller);
  ref_roi = ref_im(rbox);
  calc_histogram(ref_roi, channels, ref_hist_in, dims, hist_size, ranges, mask(rbox), uniform);
  ref_hist_idx = ref_hist_in - ref_hist;
  mnd_threshold(ref_hist_idx, 0, 1);
  ref_hist = ref_hist.mul(ref_hist_idx);    

  mnd_minmax_normalize(ref_hist, 0, 255);
  return ref_hist;
}

bool rotation_angle(const std::vector<cv::KeyPoint>& keypoints1,
		    const cv::Mat& desc1, 
		    const std::vector<cv::KeyPoint>& keypoints2,
		    const cv::Mat& desc2, 
		    double& angle){
  if (keypoints1.size()==0 || keypoints2.size()==0)
    return false;
  // Matching descriptor vectors using FLANN matcher
  cv::FlannBasedMatcher matcher;
  std::vector<cv::DMatch> matches;
  matcher.match(desc1, desc2, matches);

  double max_dist = -INFINITY; double min_dist = INFINITY;
  // Quick calculation of max and min distances between keypoints
  for(int i = 0; i < desc1.rows; i++){ 
    double dist = matches[i].distance;
    min_dist = MIN(min_dist, dist);
    max_dist = MAX(max_dist, dist);
  }
  // keep only "good" matches (i.e., whose distance is less than 1.5*min_dist)
  std::vector<cv::DMatch> good_matches;
  for(int i = 0; i < desc1.rows; i ++){ 
    if(matches[i].distance < MAX(1.5*min_dist,1e-5))
      good_matches.push_back(matches[i]);
  }
  // if there are less than three good matches
  // there is not enough information to estimate the rigid transformation
  if (good_matches.size() < 3)
    return false;
  
  std::vector<cv::Point2f> pts1;
  std::vector<cv::Point2f> pts2;  
  for(unsigned int i = 0; i < good_matches.size(); i ++){
    //-- Get the keypoints from the good matches
    pts1.push_back(keypoints1[good_matches[i].queryIdx].pt);
    pts2.push_back(keypoints2[good_matches[i].trainIdx].pt);
  }
  cv::Mat H = estimateRigidTransform(pts1, pts2, false);
  if (H.rows == 0) // estimation failed (points are inconsistent)
    return false;
  double cos_theta = H.at<double>(0,0);
  double sin_theta = H.at<double>(1,0);
  double norm = sqrt(cos_theta*cos_theta + sin_theta*sin_theta); 
  angle = asin(fabs(sin_theta/norm));
  return true;
}

void rotation_probability(const std::vector<cv::Mat>& frames,
			  const std::vector<cv::Rect>& tube,
			  std::vector<double> &probs){
  int T = frames.size();
  int cols = frames[0].cols;
  int rows = frames[0].rows;
  std::vector<cv::Mat> im_patches(T);
  for (int t = 0; t < T; t ++){
    cv::Rect box = resize_box(tube[t], cols, rows, 1.2);
    cv::cvtColor(frames[t](box), im_patches[t], CV_BGR2GRAY);
  }

  // detect and extract descriptors for each box patch
  const int maxn_features = 100;
  std::vector<std::vector<cv::KeyPoint> > keypoints(T);
  std::vector<cv::Mat> desc(T);
#pragma omp parallel for
  for (int t = 0; t < T; t ++){
    cv::Ptr<SIFT> detector = SIFT::create(maxn_features);
    cv::Ptr<SIFT> extractor = SIFT::create();
    //    std::cout << im_patches[t].rows << " " << im_patches[t].cols << std::endl;
    double scale = MAX(64.0/im_patches[t].rows, 64.0/im_patches[t].cols);
    if (scale > 1)
      cv::resize(im_patches[t], im_patches[t], cv::Size(), scale, scale);
    detector->detect(im_patches[t], keypoints[t]);
    extractor->compute(im_patches[t], keypoints[t], desc[t]);
  }

  // compute the probability that at time t the object has 
  // an rotation compared to time t'<t
  const int max_rotation_time_frame = video_fps;  // 20fps * 1seconds -> 20 frames
#pragma omp parallel for
  for (int t = 0; t < T; t ++){
    probs[t] = -INFINITY;
    for (int t_ = MAX(0,t-max_rotation_time_frame); t_ < t; t_ ++){
      double angle;
      bool confident = rotation_angle(keypoints[t_], desc[t_],
				      keypoints[t], desc[t], angle);
      if (confident)
	probs[t] = MAX(probs[t], log_vonmises(angle, M_PI/2, 4));
    }
  }
}

void init_kalman(cv::KalmanFilter& kf, cv::Rect window){
  const int state_num = 4;
  const int measure_num = 2;
  
  cv::Mat state_post = (cv::Mat_<float>(state_num, 1) 
			<< window.x+window.width/2.0, // x0
			window.y+window.height/2.0,   // y0
			0,                            // vx0
			0);                           // vy0
  cv::Mat transition_matrix = (cv::Mat_<float>(state_num, state_num) 
			       << 1, 0, 1, 0,
			       0, 1, 0, 1,
			       0, 0, 1, 0,
			       0, 0, 0, 1);
    
  kf.init(state_num, measure_num);  
  kf.transitionMatrix = transition_matrix;
  kf.statePost = state_post.clone();
  kf.statePre = state_post.clone();
  cv::setIdentity(kf.measurementMatrix);
  cv::setIdentity(kf.processNoiseCov, cv::Scalar::all(1e-1));
  cv::setIdentity(kf.measurementNoiseCov, cv::Scalar::all(1e-3));
  cv::setIdentity(kf.errorCovPost, cv::Scalar::all(0.1));  
}

void color_hist(const cv::Mat& patch, cv::MatND& hist){
  const int h_bins = 180;
  //  const int s_bins = 20;
  int hist_size[] = {h_bins};
  float hrange[] = {0, 180};
  //  float srange[] = {0, 256};
  const float* ranges[] = {hrange};
  int channels[] = {0};
  calc_histogram(patch, channels, hist, 1, hist_size, ranges);
}

double color_saliency(const cv::Mat& frame, const cv::Rect& box){
  const int b_bins = 8;
  const int g_bins = 8;
  const int r_bins = 8;
  int hist_size[] = {b_bins, g_bins, r_bins};
  float brange[] = {0, 256};
  float grange[] = {0, 256};
  float rrange[] = {0, 256};
  const float* ranges[] = {brange, grange, rrange};
  int channels[] = {0, 1, 2};
  
  // needswork: use integral histogram to speed up computation
  cv::MatND hist, out_hist;
  cv::Mat mask;
  cv::Rect rbox;
  // compute inner histogram
  mask = cv::Mat::zeros(frame.rows, frame.cols, CV_8UC1);
  mask(box) = cv::Scalar(1);
  calc_histogram(frame, channels, hist, 3, hist_size, ranges, mask);

  // compute outer histogram
  rbox = resize_box(box, frame.cols, frame.rows, std::sqrt(2));
  mask = cv::Scalar(0);
  mask(rbox) = cv::Scalar(1); mask(box) = cv::Scalar(0);
  calc_histogram(frame, channels, out_hist, 3, hist_size, ranges, mask);
  
  // cv::Scalar mean, stddev;
  // cv::meanStdDev(hist, mean, stddev);
  // diversity = stddev.val[0];
  // compute distance
  double score = chisq(hist, out_hist);

  //assert(score>=0 && score<=1);
  // if (score < 0 || score > 1)
  //   fprintf(stderr, "warning: score = %lf\n", score);
  score = MAX(0, MIN(1,score));
  return score;
}

void meanshift_propagation(const std::vector<cv::Mat>& frames,
			   std::vector<cv::Rect>& tube,
			   int t0, cv::Rect box, int opt){
  int T = frames.size();
  int cols = frames[t0].cols;
  int rows = frames[t0].rows;

  int dims = 3;
  const int b_bins = 32;
  const int g_bins = 32;
  const int r_bins = 32;
  int hist_size[] = {b_bins, g_bins, r_bins};
  float brange[] = {0, 256};
  float grange[] = {0, 256};
  float rrange[] = {0, 256};
  const float* ranges[] = {brange, grange, rrange};
  int channels[] = {0, 1, 2};
  cv::Mat mask = cv::Mat::ones(rows, cols, CV_8U);
  bool uniform = true;
  
  cv::MatND ref_hist = get_ref_hist(frames[t0], box, mask, dims, 
				    hist_size, ranges, channels, uniform);
  
  int sT[2] = {t0+1, t0-1};
  int eT[2] = {T, -1};
  int inc[2] = {1, -1};
  cv::MatND backproj;
  cv::TermCriteria term(cv::TermCriteria::EPS|cv::TermCriteria::COUNT, 10, 1);

  cv::Rect prev, cnt;
  
  for (int j = 0; j < 2; j ++){    
    prev = box; 
    cnt = box;   
    // loop through frames
    for (int t = sT[j]; t != eT[j]; t += inc[j]){      
      cv::calcBackProject(&(frames[t]), 1, channels, ref_hist, backproj, ranges, 1, uniform);
      try{
	if (opt == 0)
	  cv::CamShift(backproj, cnt, term);
	else 
	  cv::meanShift(backproj, cnt, term);
      }
      catch (cv::Exception &e){
	// camshift lost the object
	cnt = prev;
	tube[t] = prev;
	continue;
      }
      tube[t] = cnt;
      prev = cnt;
    }
  }
  if (t0>0 && t0<T-1)
    tube[t0] = average_boxes(tube[t0-1], tube[t0+1]);
  else
    tube[t0] = box;
}

void camshift_propagation(const std::vector<cv::Mat>& frames,
			  std::vector<cv::Rect>& tube,
			  int t0, cv::Rect box){
  int T = frames.size();
  int dims = 1;
  const int h_bins = 180;
  int hist_size[] = {h_bins};
  bool uniform = false;
  int channels[] = {0};  
  float range_h[h_bins+1];  
  float step = 180.0 / h_bins;
  for(int i = 0; i < h_bins+1; i ++)
    range_h[i] = i*step;  
  const float* ranges[] = {range_h};  
  const int vmin = 10, vmax = 256, smin = 30;
  cv::Mat mask;
  cv::inRange(frames[t0], cv::Scalar(0,smin,vmin), cv::Scalar(180,256,vmax), mask);
  
  cv::MatND ref_hist = get_ref_hist(frames[t0], box, mask, dims, 
				    hist_size, ranges, channels, uniform);  
  int sT[2] = {t0+1, t0-1};
  int eT[2] = {T, -1};
  int inc[2] = {1, -1};
  cv::MatND backproj;
  cv::TermCriteria term(cv::TermCriteria::EPS|cv::TermCriteria::COUNT, 10, 1);
  cv::Rect prev, cnt;
  for (int j = 0; j < 2; j ++){    
    prev = box; 
    cnt = box;   
    // loop through frames
    for (int t = sT[j]; t != eT[j]; t += inc[j]){      
      cv::inRange(frames[t], cv::Scalar(0,smin,vmin), cv::Scalar(180,256,vmax), mask);      
      cv::calcBackProject(&(frames[t]), 1, channels, ref_hist, backproj, ranges, 1, uniform);

      backproj &= mask;

      try{
	cv::CamShift(backproj, cnt, term);
      }
      catch (cv::Exception &e){
	// camshift lost the object
	cnt = prev;
	tube[t] = prev;
	continue;
      }
      tube[t] = cnt;
      prev = cnt;
    }
  }
  
  if (t0>0 && t0<T-1)
    tube[t0] = average_boxes(tube[t0-1], tube[t0+1]);
  else
    tube[t0] = box;
}

// method: "MIL", "BOOSTING", "TLD", "MEDIANFLOW"
void flow_propagation(const std::vector<cv::Mat>& frames, 
		      std::vector<cv::Rect>& tube,
		      int t0, cv::Rect box, const std::string method = "BOOSTING"){
  int T = frames.size();
  int cols = frames[t0].cols;
  int rows = frames[t0].rows;
  cv::Rect2d cnt;
  tube[t0] = box;
  cv::Ptr<cv::Tracker> tracker = cv::Tracker::create(method.c_str());

  // backward
  tracker->init(frames[t0], box);
  for (int t = t0-1; t >= 0; t--){
    bool ret;
    try {
      ret = tracker->update(frames[t], cnt);
    }
    catch (cv::Exception &e){
      tube[t] = tube[t+1];
      continue;
    }
    if (ret) {
      int x, y, w, h;
      x = MAX(0,int(cnt.x));
      y = MAX(0,int(cnt.y));
      w = MIN(cols-x, int(cnt.width));
      h = MIN(rows-y, int(cnt.height));
      tube[t] = cv::Rect(x,y,w,h);
    }
    else
      tube[t] = tube[t+1];
  }
  // forward
  tracker->init(frames[t0], box);
  for (int t = t0+1; t < T; t ++){
    bool ret;
    try {
      ret = tracker->update(frames[t], cnt);
    }
    catch (cv::Exception &e){
      tube[t] = tube[t-1];
      continue;
    }
    if (ret){
      int x, y, w, h;
      x = MAX(0,int(cnt.x));
      y = MAX(0,int(cnt.y));
      w = MIN(cols-x, int(cnt.width));
      h = MIN(rows-y, int(cnt.height));
      tube[t] = cv::Rect(x,y,w,h);
    }
    else 
      tube[t] = tube[t-1];
  }
}

void hog_descriptor(const cv::Mat im, std::vector<float>& hog_desc){
  std::vector<cv::Point> locs;
  cv::Mat patch;
  cv::HOGDescriptor hog;
  cv::resize(im, patch, cv::Size(64,128));  
  cv::cvtColor(patch, patch, CV_BGR2GRAY);  
  hog_desc.clear();
  hog.compute(patch, hog_desc, cv::Size(0,0), cv::Size(0,0), locs);  
}

void mouse_callback(int e, int x, int y, int flags, void* param){
  cv::Rect *box = (cv::Rect *)param;
  switch(e){
  case CV_EVENT_LBUTTONDOWN:
    box->x = x, box->y = y;
    break;
  case CV_EVENT_LBUTTONUP:
    box->width = x - box->x + 1;
    box->height = y - box->y + 1;    
    break;
  }
}

bool size_ratio_test(const cv::Rect &box, int height, int width){
  double size_ratio = box.height*box.width / double(height*width);
  if (size_ratio > MINI_OBJ && size_ratio < BIG_OBJ)
    return true;
  return false;
}

cv::Mat imlib2cvmat(Imlib_Image imlib_img){
  imlib_context_set_image(imlib_img);
  int width = imlib_image_get_width();
  int height = imlib_image_get_height();
  DATA32 * imlib_data = imlib_image_get_data_for_reading_only();
  cv::Mat cvimg(height, width, CV_8UC3);
  for (int i = 0; i < width*height; i ++){
    cv::Vec3b pixel;
    pixel[0] = (imlib_data[i] & 0xFF);        // B                                                
    pixel[1] = ((imlib_data[i]>>8) & 0xFF);   // G
    pixel[2] = ((imlib_data[i]>>16) & 0xFF);  // R
    cvimg.at<cv::Vec3b>(i/width, i%width) = pixel;
  }
  return cvimg;
}

extern "C" void temporal_coherence(double **fxy, double ***boxes, int T, int top_k,
				   /* output */ double ***g){
  for (int t = 0; t < T-1; t ++)
    for (int i = 0; i < top_k; i ++)
      for (int j = 0; j < top_k; j ++){
	g[t][i][j] = coherence_score(boxes[t][i], boxes[t+1][j], 
				     fxy[t][2*i], fxy[t][2*i+1]);
	if (track_constraint && i!=j)
	  g[t][i][j] = -INFINITY;
      }
}

extern "C" void reselect_proposals(double ***boxes, Imlib_Image *frames, int T,
				   int pool_size, int top_k, int L,
				   /*output*/
				   double ***new_boxes){
  int top_k_move = int(top_k / 3);
  int top_k_nonmove = top_k - top_k_move;
  double ***new_boxes_move = new double**[T];
  double ***new_boxes_nonmove = new double**[T];
  for (int t = 0; t < T; t ++){
    new_boxes_move[t] = new double*[top_k_move];
    for (int k = 0; k < top_k_move; k ++)
      new_boxes_move[t][k] = new double[L];
    new_boxes_nonmove[t] = new double*[top_k_nonmove];
    for (int k = 0; k < top_k_nonmove; k ++)
      new_boxes_nonmove[t][k] = new double[L];
  }

  std::cout << "  sampling proposals for moving objects..." << std::endl;
  reselect_proposals_with_movement(boxes, frames, T, pool_size, top_k_move, 1, new_boxes_move);
  std::cout << "  sampling proposals for nonmoving objects..." << std::endl;
  reselect_proposals_with_movement(boxes, frames, T, pool_size, top_k_nonmove, 0, new_boxes_nonmove);
  
  for (int t = 0; t < T; t ++)
    for (int k = 0; k < top_k; k ++){
      for (int i = 0; i < L; i ++)
  	new_boxes[t][k][i] = (k<top_k_move?new_boxes_move[t][k][i]:new_boxes_nonmove[t][k-top_k_move][i]);
    }

  for (int t = 0; t < T; t ++){
    for (int k = 0; k < top_k_move; k ++)
      delete [] new_boxes_move[t][k];
    for (int k = 0; k < top_k_nonmove; k ++)
      delete [] new_boxes_nonmove[t][k];
    delete [] new_boxes_move[t];
    delete [] new_boxes_nonmove[t];
  }
  delete [] new_boxes_move;
  delete [] new_boxes_nonmove;
}

void kalman_smooth_points(int w, int h, std::vector<cv::Point>& pts){
  cv::KalmanFilter KF(4, 2, 0);
  KF.transitionMatrix = (cv::Mat_<float>(4, 4) << 1,0,1,0,   0,1,0,1,  0,0,1,0,  0,0,0,1);
  cv::Mat_<float> measurement(2,1); 
  measurement.at<float>(0) = pts[0].x;
  measurement.at<float>(1) = pts[0].y;
  
  // init
  KF.statePost.at<float>(0) = pts[0].x;
  KF.statePost.at<float>(1) = pts[0].y;
  KF.statePost.at<float>(2) = 0;
  KF.statePost.at<float>(3) = 0;
  KF.statePre = KF.statePost.clone();
  cv::setIdentity(KF.measurementMatrix);
  cv::setIdentity(KF.processNoiseCov, cv::Scalar::all(1e-2));
  cv::setIdentity(KF.measurementNoiseCov, cv::Scalar::all(1e-3));
  cv::setIdentity(KF.errorCovPost, cv::Scalar::all(.1));
  
  for (unsigned int t = 1; t < pts.size(); t ++){
    // First predict, to update the internal statePre variable
    cv::Mat prediction = KF.predict();
    cv::Point predictPt(prediction.at<float>(0),prediction.at<float>(1));                         

    // get the measurement
    measurement.at<float>(0) = pts[t].x;
    measurement.at<float>(1) = pts[t].y;
 
    // The "correct" phase that is going to use the predicted value and our measurement
    cv::Mat estimated = KF.correct(measurement);
    cv::Point statePt(MAX(0,MIN(w-1,estimated.at<float>(0))), 
		      MAX(0,MIN(h-1,estimated.at<float>(1))));
    pts[t] = statePt;
  }
}

void kalman_smooth_tube(int w, int h, std::vector<cv::Rect>& tube){
  std::vector<cv::Point> top_left;
  std::vector<cv::Point> bottom_right;
  for (unsigned int t = 0; t < tube.size(); t ++){
    top_left.push_back(cv::Point(tube[t].x,tube[t].y));
    bottom_right.push_back(cv::Point(tube[t].x+tube[t].width-1,
				     tube[t].y+tube[t].height-1));
  }

  kalman_smooth_points(w, h, top_left);
  kalman_smooth_points(w, h, bottom_right);

  for (unsigned int t = 0; t < tube.size(); t ++){
    if (bottom_right[t].x < top_left[t].x || bottom_right[t].y < top_left[t].y)
      bottom_right[t] = top_left[t];    
    tube[t] = cv::Rect(top_left[t].x, top_left[t].y,
		       bottom_right[t].x-top_left[t].x+1, bottom_right[t].y-top_left[t].y+1);
  }
}

extern "C" void reselect_proposals_with_movement(double ***boxes, Imlib_Image *frames, int T,
						 int pool_size, int top_k, int movement,
						 /*output*/
						 double ***new_boxes){  
  assert(T >= 2);
  // all frames are downsampled by half to speed up tracking
  std::vector<cv::Mat> cv_frames(T);
  std::vector<cv::Mat> cv_frames_hsv(T);
  for (int t = 0; t < T; t ++){
    // rgb frames
    cv_frames[t] = imlib2cvmat(frames[t]);
    // hsv frames
    cv::cvtColor(cv_frames[t], cv_frames_hsv[t], cv::COLOR_BGR2HSV);    
  }

  // compute the frame distribution and the box distribution 
  // according to optical flow
  int width = cv_frames[0].cols;
  int height = cv_frames[0].rows;
  std::vector<double> frame_flows;
  std::vector<std::vector<double> > box_flows(T);
  std::vector<double> flow_scores(T*top_k);
  std::vector<double> rotation_scores(T*top_k);
  // std::vector<double> color_diversity(T*top_k);
  std::vector<double> object_scores(T*top_k);
  std::vector<cv::Mat> integral_flow(T);
  //  std::vector<cv::Mat> optical_flow(T);

  // integral flow
  for (int t = 0; t < T; t ++){
    if (t < T-1)
      compute_integral_flow(cv_frames[t], cv_frames[t+1], integral_flow[t]);
    else
      integral_flow[t] = integral_flow[t-1].clone();
  }
  
  // compute the cdf of frames
  for (int t = 0; t < T; t ++){    
    cv::Vec2d f = average_flow_in_rect(cv::Rect(0,0,width,height), integral_flow[t]);
    frame_flows.push_back(f[0]*f[0]+f[1]*f[1]);
  }
  cv::normalize(frame_flows, frame_flows, 1, 0, cv::NORM_L1);

  for (int t = 1; t < T; t ++)
    frame_flows[t] += frame_flows[t-1];    

  // compute 1) the cdf of proposals per frame
  //         2) hog feature for each proposal
  //         3) color hist for each proposal
#pragma omp parallel for
  for (int t = 0; t < T; t ++){
    std::vector<double> tmp_box_flows;
    for (int k = 0; k < pool_size; k ++){     
      cv::Vec2d f = average_flow_in_rect(box2cvrect(boxes[t][k]), integral_flow[t]);      
      tmp_box_flows.push_back(sqrt(f[0]*f[0]+f[1]*f[1]));
    }
    if (!movement){ // flip the polarity
      double mf = median(tmp_box_flows, 1.0/3);
      for (int k = 0; k < pool_size; k ++){
    	tmp_box_flows[k] = MAX(sqrt(mf)-tmp_box_flows[k], 0);
    	tmp_box_flows[k] = pow(tmp_box_flows[k], 5);
      }
    }
    else{
      for (int k = 0; k < pool_size; k ++)
	tmp_box_flows[k] = pow(tmp_box_flows[k], 5);
    }

    if (!movement){
      for (int k = 0; k < pool_size; k ++){
	tmp_box_flows[k] *= color_saliency(cv_frames[t], box2cvrect(boxes[t][k]))
	  * boxes[t][k][4];
      }
    }
  
    // convert to cdf
    cv::normalize(tmp_box_flows, tmp_box_flows, 1, 0, cv::NORM_L1);    
    for (int k = 1; k < pool_size; k ++)
      tmp_box_flows[k] += tmp_box_flows[k-1];
    box_flows[t] = tmp_box_flows;
  }

  //////////////////////////////// sampling ///////////////////////////////
  // tracker pool
  const int functions_n = 3;
  std::unordered_set<int> hash;
  int last_success = -1;
  int step = MIN(top_k, 3);
  assert(top_k <= pool_size);

  // allocate memory for reseleteced boxes
  std::vector<std::vector<cv::Rect> > new_boxes_vector;
  for (int t = 0; t < T; t ++){
    std::vector<cv::Rect> boxes_per_frame(top_k);
    new_boxes_vector.push_back(boxes_per_frame);
  }  

  // WARNING: omp sometimes changes the result due to the scheduling
#pragma omp parallel for
  for (int k = 0; k < top_k; k ++){
    int frame_i, box_i, function_idx;
    cv::Rect origin;
    std::vector<cv::Rect> tube(T);
    
    int attempt = 0;
    int duplicates = 0;
    //// sample a tube until it's desirable
    while (true){
      // first sample the frame
      //frame_i = sample_from_cdf(frame_flows);
      frame_i = rand() % T;
      // second sample the box at that frame
      box_i = sample_from_cdf(box_flows[frame_i]);    
      // randomly select a propagation method
      if (movement)
      	function_idx = 0;
      else
      	function_idx = 1;
   
      int key = frame_i*pool_size*functions_n + box_i*functions_n + function_idx;
      bool exist = false;
#pragma omp critical
      {
	if (hash.find(key) == hash.end())
	  hash.insert(key);
	else {
	  duplicates ++;
	  exist = true;
	}
      }
      if (last_success>=0 && duplicates>500){
      	for (int t = 0; t < T; t ++)
      	  tube[t] = new_boxes_vector[t][last_success];
      	break;
      }
      if (exist) continue;

      origin = box2cvrect(boxes[frame_i][box_i]);
      if (size_ratio_test(origin, height, width)){
	switch(function_idx){		  
	case 0:
	  camshift_propagation(cv_frames_hsv, tube, frame_i, origin);
	  break;
	case 1:
	  meanshift_propagation(cv_frames, tube, frame_i, origin, 1);
	  break;
	case 2:
	  flow_propagation(cv_frames, tube, frame_i, origin, "BOOSTING");
	  break;
	}       
	
	// check whether all the propagated boxes have proper sizes
	int t;
	for (t = 0; t < T; t ++) 
	  if (!size_ratio_test(tube[t],height,width))
	    break;

	if (t == T){
	  // do not change this constant!
	  const int max_per_object = 3;
	  if (k < max_per_object)
	    break;
	  // test overlap with already selected tubes
	  std::vector<double> IoUs;
	  for (int l = 0; l < k; l ++){
	    std::vector<cv::Rect> sel_tube;
	    for (int t_ = 0; t_ < T; t_ ++)
	      sel_tube.push_back(new_boxes_vector[t_][l]);
	    IoUs.push_back(IoU_tubes(tube, sel_tube));
	  }
	  std::sort(IoUs.begin(), IoUs.end());	  
	  if (IoUs[k-max_per_object] < NMS_THRES)
	    break;	 	 
	  if (++attempt > 10)
	    break;
	}
      }
    }

    ////
    std::vector<double> probs(T);
    rotation_probability(cv_frames, tube, probs);
 
    //    std::vector<double> flows;
    for (int t = 0; t < T; t ++){
      new_boxes_vector[t][k] = tube[t];
      cv::Vec2d f = average_flow_in_rect(tube[t], integral_flow[t]);
      flow_scores[t*top_k+k] = sqrt(f[0]*f[0] + f[1]*f[1]);	
      rotation_scores[t*top_k+k] = probs[t]; 
    }

    last_success = k;

    for (int t = 0; t < T; t ++)
      object_scores[t*top_k+k] = log(boxes[frame_i][box_i][4]);

    if (k % (top_k/step) == 0)
      std::cout << "    progress: " 
    		<< MIN(int(double(k)/top_k*100+100.0/step),100) 
    		<< "%" << std::endl;
  }

  cv::normalize(flow_scores, flow_scores, 0, 1, cv::NORM_MINMAX);

  // convert results
  for (int t = 0; t < T; t ++){
    assert(int(new_boxes_vector[t].size()) == top_k);
    for (int i = 0; i < top_k; i ++){
      cv::Rect b = new_boxes_vector[t][i];
      new_boxes[t][i][0] = b.x;
      new_boxes[t][i][1] = b.y;
      new_boxes[t][i][2] = b.x + b.width - 1;
      new_boxes[t][i][3] = b.y + b.height - 1;
      new_boxes[t][i][4] = MAX(-100,log(flow_scores[t*top_k+i])); //flow_scores[t*top_k+i];
      new_boxes[t][i][5] = MAX(-100,rotation_scores[t*top_k+i]);
      new_boxes[t][i][6] = MAX(-100,object_scores[t*top_k+i]);
    }
  }
}

extern "C" int check_similarity_between_videos(char *c_video_dir1, char *c_video_dir2,
					       int T, int top_k, double ****similarities){
  std::string video_dir1(c_video_dir1);
  std::string video_dir2(c_video_dir2);
  std::string root_dir = video_dir1.substr(0, video_dir1.find_last_of("\\/"));
  std::string video1 = video_dir1.substr(video_dir1.find_last_of("\\/")+1, video_dir1.length());
  std::string video2 = video_dir2.substr(video_dir2.find_last_of("\\/")+1, video_dir2.length());  
  std::string simi_dir = root_dir;
  simi_dir.append("/similarity");
  std::string simi_file = simi_dir;
  simi_file.append("/");
  simi_file.append(video1);
  simi_file.append("__");
  simi_file.append(video2);
  simi_file.append(".bin");
  
  // load precomputed similarity
  FILE *fp = fopen(simi_file.c_str(), "rb");
  if (!fp) {
    // reverse the order (just in case)
    simi_file = simi_dir;
    simi_file.append("/");
    simi_file.append(video2);
    simi_file.append("__");
    simi_file.append(video1);
    simi_file.append(".bin");
    fp = fopen(simi_file.c_str(), "rb");
    if (!fp) return 0;
  }

  int num_boxes, I, frames_n;
  fread(&num_boxes, sizeof(int), 1, fp);
  fread(&I, sizeof(int), 1, fp);
  fread(&frames_n, sizeof(int), 1, fp);
  if (num_boxes<top_k || I<n_orientations || frames_n!=T){
    fclose(fp);
    return 0;
  }

  float tmp;
  for (int t = 0; t < T; t ++)
    for (int i = 0; i < I; i ++)
      for (int k = 0; k < num_boxes; k ++)
	for (int l = 0; l < num_boxes; l ++){
	  fread(&tmp, sizeof(float), 1, fp);
	  if (i<n_orientations && k<top_k && l<top_k)
	    similarities[t][i][k][l] = double(tmp);
	}
  fclose(fp);
  return 1;
}

extern "C" void similarity_between_videos(Imlib_Image *frames1, Imlib_Image *frames2,
					  double ***boxes1, double ***boxes2, 
					  char *c_video_dir1, char *c_video_dir2,
					  int T, int top_k,
					  // output
					  double ****similarities){
  // compute features  
  std::vector<float> hog_ders1[T][top_k][n_orientations];
  std::vector<float> hog_ders2[T][top_k][n_orientations];  
  double ars1[T][top_k][n_orientations];
  double ars2[T][top_k][n_orientations];
  cv::MatND colors1[T][top_k][n_orientations];
  cv::MatND colors2[T][top_k][n_orientations];

  for (int t = 0; t < T; t ++){
    cv::Mat frame1 = imlib2cvmat(frames1[t]);
    cv::Mat frame2 = imlib2cvmat(frames2[t]);
    cv::Mat frame_hsv1, frame_hsv2;
    cv::cvtColor(frame1, frame_hsv1, cv::COLOR_BGR2HSV);
    cv::cvtColor(frame2, frame_hsv2, cv::COLOR_BGR2HSV);
    
    for (int k = 0; k < top_k; k ++){
      cv::Rect box1 = box2cvrect(boxes1[t][k]);
      cv::Rect box2 = box2cvrect(boxes2[t][k]);
      box1 = resize_box(box1, frame1.cols, frame1.rows, 1.2); // to include the object boundary
      box2 = resize_box(box2, frame2.cols, frame2.rows, 1.2); // to include the object boundary
      cv::Mat roi1 = frame1(box1).clone();           
      cv::Mat roi2 = frame2(box2).clone();

      // rotate 360/n_orientations degrees each time
      for (int i = 0; i < n_orientations; i ++){
	if (i > 0){
	  cv::Point2f center1(roi1.cols/2.0, roi1.rows/2.0);
	  cv::Mat r1 = cv::getRotationMatrix2D(center1, 360.0/n_orientations, 1);
	  cv::warpAffine(roi1, roi1, r1, cv::Size(roi1.cols,roi1.rows));
	  cv::Point2f center2(roi2.cols/2.0, roi2.rows/2.0);
	  cv::Mat r2 = cv::getRotationMatrix2D(center2, 360.0/n_orientations, 1);
	  cv::warpAffine(roi2, roi2, r2, cv::Size(roi2.cols,roi2.rows));
	}
	hog_descriptor(roi1, hog_ders1[t][k][i]);
	hog_descriptor(roi2, hog_ders2[t][k][i]);
	ars1[t][k][i] = double(roi1.rows) / roi1.cols;
	ars2[t][k][i] = double(roi2.rows) / roi2.cols;
	color_hist(frame_hsv1(box1), colors1[t][k][i]);
	color_hist(frame_hsv2(box2), colors2[t][k][i]);
      }
    }
  }
  
  double hog_diff[T][top_k][top_k][n_orientations];
  double ar_diff[T][top_k][top_k][n_orientations];
  double color_diff[T][top_k][top_k][n_orientations];
  double max_hog_diff = -INFINITY, min_hog_diff = INFINITY;
  double max_ar_diff = -INFINITY, min_ar_diff = INFINITY;
  double max_color_diff = -INFINITY, min_color_diff = INFINITY;

  for (int t = 0; t < T; t ++)
    for (int k = 0; k < top_k; k ++)
      for (int l = 0; l < top_k; l ++)
	for (int i = 0; i < n_orientations; i ++){
	  hog_diff[t][k][l][i] = cv::norm(hog_ders1[t][k][i], hog_ders2[t][l][0]);
	  max_hog_diff = MAX(hog_diff[t][k][l][i], max_hog_diff);
	  min_hog_diff = MIN(hog_diff[t][k][l][i], min_hog_diff);

	  ar_diff[t][k][l][i] = std::fabs(log(ars1[t][k][i] / ars2[t][l][0]));
	  max_ar_diff = MAX(ar_diff[t][k][l][i], max_ar_diff);
	  min_ar_diff = MIN(ar_diff[t][k][l][i], min_ar_diff);

	  color_diff[t][k][l][i] = chisq(colors1[t][k][i], colors2[t][l][0]);
	  max_color_diff = MAX(color_diff[t][k][l][i], max_color_diff);
	  min_color_diff = MIN(color_diff[t][k][l][i], min_color_diff);
	}

  // normalize to [0,1]
  for (int t = 0; t < T; t ++)
    for (int k = 0; k < top_k; k ++)
      for (int l = 0; l < top_k; l ++)
	for (int i = 0; i < n_orientations; i ++){
	  hog_diff[t][k][l][i] = log(1-(hog_diff[t][k][l][i]-min_hog_diff)
				     /(max_hog_diff-min_hog_diff));
	  ar_diff[t][k][l][i] = log(1-(ar_diff[t][k][l][i]-min_ar_diff)
				    /(max_ar_diff-min_ar_diff)); 
	  color_diff[t][k][l][i] = log(1-(color_diff[t][k][l][i]-min_color_diff)
				       /(max_color_diff-min_color_diff));
	}

  // compute similarities
  for (int t = 0; t < T; t ++)
    for (int i = 0; i < n_orientations; i ++)
      for (int k = 0; k < top_k; k ++)
	for (int l = 0; l < top_k; l ++){
	  similarities[t][i][k][l] = (hog_diff[t][k][l][i]
				      + 0.5*ar_diff[t][k][l][i]
				      //				      + 0.2*color_diff[t][k][l][i]
				      );
	}

  // write to disk
  std::string video_dir1(c_video_dir1);
  std::string video_dir2(c_video_dir2);
  std::string root_dir = video_dir1.substr(0, video_dir1.find_last_of("\\/"));
  std::string video1 = video_dir1.substr(video_dir1.find_last_of("\\/")+1, video_dir1.length());
  std::string video2 = video_dir2.substr(video_dir2.find_last_of("\\/")+1, video_dir2.length());  
  std::string simi_dir = root_dir;
  simi_dir.append("/similarity");
  std::string simi_file = simi_dir;
  simi_file.append("/");
  simi_file.append(video1);
  simi_file.append("__");
  simi_file.append(video2);
  simi_file.append(".bin");
  
  FILE *fp = fopen(simi_file.c_str(), "wb");
  int I = n_orientations;
  fwrite(&top_k, sizeof(int), 1, fp);
  fwrite(&I, sizeof(int), 1, fp);
  fwrite(&T, sizeof(int), 1, fp);
  float tmp;
  for (int t = 0; t < T; t ++)
    for (int i = 0; i < n_orientations; i ++)
      for (int k = 0; k < top_k; k ++)
	for (int l = 0; l < top_k; l ++){
	  tmp = float(similarities[t][i][k][l]);
	  fwrite(&tmp, sizeof(float), 1, fp);
	}
  fclose(fp);
}

extern "C" void average_object_appearance(Imlib_Image **frames_menu, double ***boxes_menu, int N, int *Ts){
  const int object_size = 128;
  cv::Mat agg = cv::Mat::zeros(object_size, object_size, CV_64FC3);  
  for (int n = 0; n < N; n ++){
    cv::Mat agg_n = cv::Mat::zeros(object_size, object_size, CV_64FC3);
    for (int t = 0; t < Ts[n]; t ++){
      cv::Mat frame = imlib2cvmat(frames_menu[n][t]);
      cv::Rect box = box2cvrect(boxes_menu[n][t]);
      cv::Mat patch;
      cv::resize(frame(box), patch, cv::Size(object_size,object_size));
      cv::add(agg_n, patch, agg_n, cv::Mat(), CV_64FC3);      
    }
    agg_n *= 1.0/Ts[n];
    agg += agg_n;
  }
  agg *= 1.0/N;
  cv::imwrite("/tmp/buffer/object.png", agg);
}

double **table_from_sparse_matrix(SparseMat& binary, int z1, int z2, int top_k){
  PII key = PII(z1, z2);
  double **table;
  if (binary.find(key) == binary.end()){
    table = new double*[top_k];
    for (int k = 0; k < top_k; k ++){
      table[k] = new double[top_k];
      memset(table[k], 0, top_k*sizeof(double));
    }
    binary[key] = table;
  }
  else{
    table = binary[key];
  }
  return table;
}

double distance_less_than(double x, double threshold){
  return log(sigmoid(x, threshold, -SIGMOID_B));
}

double distance_greater_than(double x, double threshold){
  return log(sigmoid(x, threshold, SIGMOID_B));
}

double predicate_stationary(int sT, int eT, int i, double **f, double ***boxes){
  sT ++;
  assert(eT > sT);
  double score = INFINITY;
  for (int t = sT; t < eT; t ++)
    score = MIN(score, coherence_score(boxes[t-1][i],boxes[t][i],0,0));
  return score;
}

double predicate_moving(int T, int i, double **f, double ***boxes,
			MoveDir direction){
  double score = 0;
  // median
  std::vector<double> f_tmp;
  for (int t = 0; t < T; t ++)
    f_tmp.push_back(f[t][i]);
  score = median(f_tmp, 0.5);

  double y_displace_fraction = 
    (box_y(boxes[T-1][i])-box_y(boxes[0][i])) / IM_H;
  
  double x_displace_fraction = 
    (box_x(boxes[T-1][i])-box_x(boxes[0][i])) / IM_W;

  switch (direction){
  case MOVE_UP:
    score += distance_less_than(y_displace_fraction, -DIST_THRES_LARGE);
    break;
  case MOVE_DOWN:
    score += distance_greater_than(y_displace_fraction, DIST_THRES_LARGE);
    break;
  case MOVE_VERT:
    score += distance_greater_than(fabs(y_displace_fraction), DIST_THRES_LARGE);
    break;
  case MOVE_HORI:
    score += distance_greater_than(fabs(x_displace_fraction), DIST_THRES_LARGE);
    break;  
  case MOVE_LEFT:
    score += distance_less_than(x_displace_fraction, -DIST_THRES_LARGE);
    break;
  case MOVE_RIGHT:
    score += distance_greater_than(x_displace_fraction, DIST_THRES_LARGE);
    break;
  case MOVE:    
    // have some displacement during some time frame
    // but may go back to the initial position    
    break;
  default:
    codetection_error("moving direction error");
  }
  return score;
}

double predicate_rotation(int T, int i, double **u){
  std::vector<double> scores;
  for (int t = 0; t < T; t ++)
    scores.push_back(u[t][i]);  
  // at least 5 out of 100 frames suggest 'rotation'
  double score = median(scores, 0.95);
  return score;
}

double predicate_spatial(int sT, int eT, int T, int i, int k, double ***boxes,
			 SpatialType type){  
  double score;

  double distance_change_fraction =
    2*(box_dist(boxes[T-1][i], boxes[T-1][k])
       -box_dist(boxes[0][i], boxes[0][k]))
    / (IM_W+IM_H);    

  switch (type){
  case CLOSER:
    score = distance_less_than(distance_change_fraction, -DIST_THRES_LARGE);
    break;
  case FURTHER:
    score = distance_greater_than(distance_change_fraction, DIST_THRES_LARGE);
    break;
  default:
    {
      if (sT >= 0){
	score = 0;
	for (int t = sT; t < eT; t ++){
	  double x_fraction = (box_x(boxes[t][i])-box_x(boxes[t][k])) / IM_W;
	    
	  double y_fraction = (box_y(boxes[t][i])-box_y(boxes[t][k])) / IM_H;
	    
	  double distance_fraction = 2*box_dist(boxes[t][i],boxes[t][k]) / (IM_H+IM_W); 

	  switch (type){
	  case TO_THE_LEFT_OF:
	    score += distance_less_than(x_fraction, -DIST_THRES_SMALL*2);
	    break;
	  case TO_THE_RIGHT_OF:
	    score += distance_greater_than(x_fraction, DIST_THRES_SMALL*2);
	    break;
	  case CLOSE:
	    score += distance_less_than(distance_fraction, DIST_THRES_SMALL*2)
	      + log(distance_fraction); // but not completely overlap
	    break;
	  case IN:
	    score += distance_less_than(distance_fraction, DIST_THRES_SMALL) \
	      + MAX(-3,log(box_area(boxes[t][k])>box_area(boxes[t][i])));
	    break;	      
	  case ON_TOP_OF:
	    score += distance_greater_than(y_fraction, -DIST_THRES_LARGE*2) \
	      + distance_less_than(y_fraction, 0)			\
	      + distance_less_than(fabs(x_fraction), DIST_THRES_SMALL*2);
	    break;
	  case BELOW:
	    score += distance_greater_than(y_fraction, DIST_THRES_SMALL);
	    break;
	  case ABOVE:
	    score += distance_less_than(y_fraction, -DIST_THRES_SMALL);
	    break;
	  default:
	    codetection_error("spatial type error");
	  }
	}
	score /= eT-sT;
      }
      else{
	assert(type == ABOVE);
	double scores[T];
	for (int t = 0; t < T; t ++){
	  // the center is above the border
	  double y_fraction = (box_y(boxes[t][i])-box_y(boxes[t][k])) / IM_H;
	  
	  double x_fraction = (box_x(boxes[t][i])-box_x(boxes[t][k])) / IM_W;	  

	  scores[t] = distance_less_than(y_fraction, -DIST_THRES_SMALL) \
	    + distance_less_than(fabs(x_fraction), 4*DIST_THRES_SMALL);
	}
	for (int t = 1; t < T; t ++)
	  scores[t] += scores[t-1];
	score = -INFINITY;
	for (int t = video_fps; t < T; t ++)
	  score = MAX(score, scores[t]-scores[t-video_fps]);
	score /= video_fps;
      }
    }
  }
  return score;
}

/* J - object group number
   f[n][t][k] - proposal score
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
void graphical_model_scores(double ***f, double ***u, double ***h, double ****boxes_menu, 
			    double *****g2, int J, int *Ts, int *Ms, int *Qs, int **predicates, 
			    int W, int *v_ids, int **grouped_objects, int *Ns, int mode, int top_k,
			    // output
			    std::vector<double>& unary,
			    SparseMat& binary){

  int Z = 0; // total number of distinct tracks
  for (int j = 0; j < J; j ++) Z += Ns[j];

  for (int z = 0; z < Z; z ++){
    int n = v_ids[z];
    for (int i = 0; i < top_k; i ++){      
      double score = 0;
      // for (int t = 0; t < Ts[n]; t ++)
      // 	score += h[n][t][i];
      score /= Ts[n];
      unary.push_back(score);
    }
  }

  if (_gamma_ > 0){
    // add similarity scores
    for (int j = 0; j < J; j ++){
      std::vector<int> m1, m2;
      get_pairs(Ns[j], mode, m1, m2);
      assert(size_t(Ms[j]) == m1.size());
      for (int m = 0; m < Ms[j]; m ++){
	int z1 = grouped_objects[j][m1[m]];
	int z2 = grouped_objects[j][m2[m]];
	double **table = table_from_sparse_matrix(binary, z1, z2, top_k);
	for (int i = 0; i < top_k; i ++)
	  for (int k = 0; k < top_k; k ++){
	    // median
	    std::vector<double> g2_tmp;
	    for (int q = 0; q < Qs[j]; q ++)
	      g2_tmp.push_back(g2[j][m][q][i][k]);
	    double score = median(g2_tmp, 0.5);
	    
	    table[i][k] += score;
	  }
      }
    }
  }

  if (sentence_directed < 2){
    // add predicate scores
    for (int w = 0; w < W; w ++){
      int p = predicates[w][0];
      int z1 = predicates[w][1];
      int z2 = predicates[w][2];
      int n1 = (z1==-1?-1:v_ids[z1]);
      int n2 = (z2==-1?-1:v_ids[z2]);
      double **table = 0;
      if (z1!=-1 && z2!=-1){
	assert(n1 == n2); // arguments of a predicate must come from the same video
	table = table_from_sparse_matrix(binary, z1, z2, top_k);
      }

      // defined in parser.sc
      switch(p){
      case 0: // to-the-left-of
      case 1: // to-the-right-of
      case 8: // to-the-left-of-start
      case 9: // to-the-left-of-end
      case 10: // to-the-right-of-start
      case 11: // to-the-right-of-end
      case 12: // on-top-of-start
      case 13: // on-top-of-end
      case 14: // near-start
      case 15: // near-end
      case 16: // in-start
      case 17: // in-end
      case 18: // below-start
      case 19: // below-end
      case 20: // above-start
      case 21: // above-end
      case 24: // above-any

	if (z2 != -1){
	  int sT, eT;
	  if (p==0 || p==1)
	    sT = 0, eT = Ts[n2];
	  else if (p == 24)
	    sT = -1, eT = -1;
	  else if (p%2 == 0)
	    sT = 0, eT = Ts[n2]/VIDEO_START;
	  else
	    sT = Ts[n2]-Ts[n2]/VIDEO_START, eT = Ts[n2];
	
	  // strictly speaking, if there is no sentence, we won't get information
	  // about which objects are moving and which are not
	  // but we want to run a baseline with weak movemnt information
	  // so our two baselines:
	  // a. totally without any sentence information
	  // b. with only binary movement information

	  for (int i = 0; i < top_k; i ++)
	    unary[z2*top_k+i] += predicate_stationary(0,Ts[n2],i,f[n2],boxes_menu[n2]);	  
	
	  if (sentence_directed < 1){
	    if (z1 != -1){
	      SpatialType type;
	      if (p==0 || p==8 || p==9)
		type = TO_THE_LEFT_OF;
	      else if (p==1 || p==10 || p==11)
		type = TO_THE_RIGHT_OF;
	      else if (p == 12 || p == 13)
		type = ON_TOP_OF;
	      else if (p==18 || p==19)
		type = BELOW;
	      else if (p==20 || p==21 || p==24)
		type = ABOVE;
	      else if (p==16 || p==17)
		type = IN;
	      else if (p==14 || p==15)
		type = CLOSE;	  
	      else
		assert(0);

	      for (int i = 0; i < top_k; i ++)
		for (int k = 0; k < top_k; k ++)
		  table[i][k] += predicate_spatial(sT, eT, Ts[n1], i, k, boxes_menu[n1], type);
	    }
	  }
	}
	break;
      
      case 2: // picked-up
      case 3: // put-down
      case 4: // carried
      case 5: // approached 
      case 6: // towards
      case 7: // away-from
      case 22: // moved (only use 'moved' when no other verb is available)
      case 23: // rotated
      case 25: // carried-leftwards
      case 26: // carried-rightwards
      case 27: // vertical

	if ((p>=5&&p<=7) && z1!=-1){
	  for (int i = 0; i < top_k; i ++)
	    unary[z1*top_k+i] += predicate_moving(Ts[n1],i,f[n1],boxes_menu[n1], MOVE_HORI);	
	}
	if (((p>=2&&p<=4) || (p>=22&&p<=27)) && z2!=-1){
	  MoveDir direction;
	  switch (p){
	  case 2:
	    direction = MOVE_UP; break;
	  case 3: 
	    direction = MOVE_DOWN; break;
	  case 4:
	    direction = MOVE_HORI; break;
	  case 25:
	    direction = MOVE_LEFT; break;
	  case 26:
	    direction = MOVE_RIGHT; break;
	  case 27:
	    direction = MOVE_VERT; break;
	  default: // 22 23
	    direction = MOVE;	  
	  }
	  for (int i = 0; i < top_k; i ++){
	    unary[z2*top_k+i] += predicate_moving(Ts[n2],i,f[n2],boxes_menu[n2], direction);
	  
	    if (sentence_directed < 1){
	      if (p == 23)
		unary[z2*top_k+i] += predicate_rotation(Ts[n2],i,u[n2]);
	    }
	  }
	}
	// only assert spatial predicate for approached, towards, and away-from
	if (sentence_directed < 1){
	  if (z1!=-1 && z2!=-1 && p>=5 && p<=7){
	    SpatialType type;
	    if (p==5 || p==6) type = CLOSER;
	    else if (p == 7) type = FURTHER;
	    else
	      assert(0);
	    for (int i = 0; i < top_k; i ++)
	      for (int k = 0; k < top_k; k ++)
		table[i][k] += predicate_spatial(0, Ts[n1], Ts[n1], i, k, boxes_menu[n1], type);
	  }
	}
	break;
	
      default:
	codetection_error("predicate error");
      }
    }
  }
}
