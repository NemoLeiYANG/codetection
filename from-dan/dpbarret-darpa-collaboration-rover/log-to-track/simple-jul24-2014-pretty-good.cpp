#include "opencv2/video/tracking.hpp"
#include "opencv2/highgui/highgui.hpp"

#include <stdio.h>
#include <time.h>
#include "Dstar.h"
#include "cv.h"
#include "mGPSInfo.h"
#include "mNMEAParser.h"
#include <unistd.h>

#define pi (3.14159265359)
#define METERS_PER_DEGREE_LAT (111043)//(111310.4035)
#define METERS_PER_DEGREE_LONG (84857)

// These are the GPS latitude and longitude of the Left,Right,Top,and Bottom edges of the purdue image I use // I got these and the image with google earth
//////Engr fountain
// #define  MAPL (86.91629167)
// #define  MAPR (86.91122778)
// #define  MAPT (40.42976389)
// #define  MAPB (40.42775556)
//////Bogus map
#define  MAPL (86.91649167)
#define  MAPR (86.91610778)
#define  MAPT (40.42999389)
#define  MAPB (40.42960556)


using namespace cv;

// state:
// [x y theta dtheta sl sr dsl dsr]
// x and y position
// orientaion angle and derivative
// left and right wheel speeds
// left and right wheel speed derivatives

// measured values:
// x and y (gps)
// theta (imu)
// dtheta (gyro)
// left and right wheel speeds (encoders)
// acceleration of rover body (accelerometer)

// arbitrarily eyeballed variance estimates which we may want to change:
// I am assuming meters, meters/second, etc for the units

// measurement noise variance:
// there is actually a whole covariance matrix to specify, but i am assuming independence between them
float mXN = 5.0; //  GPS X noise variance
float mYN = 5.0; //  GPS Y noise variance
float mThetaN = 10 * (pi/180); //  orientation noise variance (radians)
float mdThetaN = 1000000000000 * (pi/180); //  orientation derivative noise variance (radians)
float mSLN = .01; //  left wheel speed noise variance
float mSRN = .01; //  right wheel speed noise variance
float mAN  = 100000000; //  acceleration noise variance

// process noise variance
// there is actually a whole covariance matrix to specify, but i am assuming independence between them
float pXN = 1e-6; //  GPS X noise variance
float pYN = 1e-6; //  GPS Y noise variance
float pThetaN = .01 * (pi/180); //  orientation noise variance (radians)
float pdThetaN = .01 * (pi/180); //  orientation derivative noise variance (radians)
float pSLN = 1000000; //  left wheel speed noise variance
float pSRN = 1000000; //  right wheel speed noise variance
float pdSLN = 1000000; //  left wheel speed derivative noise variance
float pdSRN = 1000000; //  right wheel speed derivative noise variance

// parameters for simplified motor physics:
// motor given 0-255 integer input I_m
// assume that force F is linearly proportional to this number by constant a:
// F = a*I_m
// assume there is also a friction force linearly dependent on wheel speed S_m by constant b:
//  F_f = -b*S_m
// assume there is some fixed mass which we bake into the proportionality constants:
// acceleration A = alpha*I_m - beta*S_m
// need to specify alpha and beta (potentially for each motor separately):
// we really should find these by computing stuff from measurements
float alpha = 1; // ????
float beta = 1; // ????
float rover_width = .3; //???? measure/calibrate this

Point2d local_origin;


Point2d GPS_to_pixel(Point2d gps,int width,int height);
Point2d GPS_to_local(Point2d gps,Point2d GPS_of_origin);
Point2d local_to_GPS(Point2d );
Point2d local_to_pixel(Point2d local, Point2d GPS_origin,int width, int height);
Point2d pixel_to_GPS(Point2d pixel, int width, int height);
Point2d pixel_to_local(Point2d pixel,Point2d GPS_of_origin, int width, int height);

int read_log_file(char* filename, Mat measurements[])
{
// char filename[1000] = "/aux/dpbarret/vader-rover/logs/2014-07-23-19:35:13/imu-log.txt";
  FILE* fp = fopen(filename,"r");
  char linebuf[1000];
  double encoder_logtime,imu_logtime,tmp_logtime;
  unsigned long encoder_time,encoder_dt,imu_time,imu_dt;
  float L,R;
  float Yaw,Pitch,Roll,Yawa,MAG_ha,MAG_h,Ax,Ay,Az,Mx,My,Mz,Gx,Gy,Gz;
//Mat measurements[10000];
  Mat Measurement = Mat::zeros(7,1,CV_32F);
  int read_encoder=0,read_imu=0;
  int n_measurements =0;
  printf("starting loop\n");
  while (fgets(linebuf,1000,fp)!=NULL)
    {
      int correct =0;
      //printf("read a line:\n%s",linebuf);
      int  encoder_items = sscanf(linebuf,"%lf: ENC:time:%u:dt:%u:L:%f:R:%f",&tmp_logtime,&encoder_time,&encoder_dt,&L,&R);
      int imu_items = sscanf(linebuf,"%lf: IMU:time:%u:dt:%u:"
			     "Yaw:%f:Pitch:%f:Roll:%f:"
			     "Yaw(a):%f:MAG_h(a):%f:MAG_h:%f:"
			     "Ax:%f:Ay:%f:Az:%f:Mx:%f:My:%f:Mz:%f:"
			     "Gx:%f:Gy:%f:Gz:%f",
			     &tmp_logtime,&imu_time,&imu_dt,
			     &Yaw,&Pitch,&Roll,
			     &Yawa,&MAG_ha,&MAG_h,
			     &Ax,&Ay,&Az,
			     &Mx,&My,&Mz,
			     &Gx,&Gy,&Gz);

      int combined_items = sscanf(linebuf,
				  "%lf: EIS:IMU:time:%u:dt:%u:"
				  "Y:%f:P:%f:R:%f:"
				  "Y(a):%f:M_h(a):%f:M_h:%f:"
				  "Ax:%f:Ay:%f:Az:%f:"
				  "Mx:%f:My:%f:Mz:%f:"
				  "Gx:%f:Gy:%f:Gz:%f:"
				  "ENC:time:%u:dt:%u:"
				  "L:%f:R:%f",
				  &tmp_logtime, &imu_time,&imu_dt,
				  &Yaw,&Pitch,&Roll,
				  &Yawa,&MAG_ha,&MAG_h,
				  &Ax,&Ay,&Az,
				  &Mx,&My,&Mz,
				  &Gx,&Gy,&Gz,
				  &encoder_time,&encoder_dt,
				  &L,&R);

      //printf("encoder items:%d\n",encoder_items);
      // if (encoder_items == 5)
      // 	{
      // 	  //printf("interpreted full encoder line: %lf %lu %lu %.3f %.3f\n",encoder_logtime,encoder_time,encoder_dt,L,R);
      // 	  encoder_logtime=tmp_logtime;
      // 	  read_encoder=1;
      // 	}
      // //printf("imu items:%d\n",imu_items);
      // if (imu_items == 18)
      // 	{
      // 	// printf("interpreted full imu line: %lf %lu %lu"
      // 	//        "%.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f\n",
      // 	//        imu_logtime,imu_time,imu_dt,Yaw,Pitch,Roll,Yawa,MAG_ha,MAG_h,Ax,Ay,Az,Mx,My,Mz,Gx,Gy,Gz);
	  
      // 	  	  imu_logtime=tmp_logtime;
		  
      // 	  read_imu=1;
      // 	}
      // if (correct==0)
      // 	{
      // 	  printf("unable to interpret line:\n%s",linebuf);  
      // 	}
      if (combined_items==22)
	//	  printf("great success\n");
	//      if (read_imu==1 && read_encoder==1)
	{
	  //printf("timing difference: :%f\n",fabs(encoder_logtime-imu_logtime));

	  // if (fabs(encoder_logtime-imu_logtime)>.02)
	  //   {
	  //     // printf("timing misaligned by: :%f\n",fabs(encoder_logtime-imu_logtime));
	  //     //read_encoder=0;
	  //     read_imu=0;
	  //     read_encoder=0;
	  //   }
	  // else
	  //   {
	      //printf("L R encoder_dt: %f %f %u\n",L,R,encoder_dt);
	  Measurement.at<float>(0) = 0; //no gps for now
	  Measurement.at<float>(1) = 0; //no gps for now
	  Measurement.at<float>(2) = (-Yaw+90)*pi/180 ; //degrees north is 0 east is positive->(radians east 0 north positive)
	  Measurement.at<float>(3) = -Gz*pi/180; // rotation around z in degrees/sec ->(radians/sec)
	  Measurement.at<float>(4) = L/100.0/(((float)((int)encoder_dt))/1000.0); // cm traveled in last time period -> (meters/sec)
	  Measurement.at<float>(5) = R/100.0/(((float)((int)encoder_dt))/1000.0); // cm traveled in last time period -> (meters/sec)

	  Measurement.at<float>(6) = -(Ax-1)/100; // cm/s^2 -> (m/s^2)       // x forward y right
	  
	  //printf("dt = %u R/100=%f denom=%f R(m/s)=%f\n",encoder_dt,R/100.0,((float)((int)encoder_dt))/1000.0,Measurement.at<float>(5));
	  printf("L R: %f %f\n", Measurement.at<float>(4), Measurement.at<float>(5));
	  measurements[n_measurements] = Measurement.clone();
	  n_measurements++;
	  read_imu=0;
	  read_encoder=0;
	  //}
	}

    }
  printf("n_measurements:%d\n",n_measurements);
  return n_measurements;
}

KalmanFilter updatesimulatedState(KalmanFilter RealState, float dt, float ul, float ur,float w)
{
  // you don't need this function. its just for testing with a simulated robot
  Mat Realcontrol = *(Mat_<float>(2,1) << ul,ur);
  RealState.predict(Realcontrol);
  RealState.statePost = RealState.statePre;
  RealState.transitionMatrix.at<float>(0,4) = .5*cos( RealState.statePre.at<float>(2))*dt;
  RealState.transitionMatrix.at<float>(0,5) = .5*cos( RealState.statePre.at<float>(2))*dt;
  RealState.transitionMatrix.at<float>(1,4) = .5*sin( RealState.statePre.at<float>(2))*dt;
  RealState.transitionMatrix.at<float>(1,5) = .5*sin( RealState.statePre.at<float>(2))*dt;

  Mat Xm,Ym,Thetam,dThetam,slm,srm,alm,arm;
  Mat ProcessNoise = Mat::zeros(8,1,CV_32F);
  Xm = Mat::zeros(1, 1, CV_32F);
  Ym = Mat::zeros(1, 1, CV_32F);
  Thetam = Mat::zeros(1, 1, CV_32F);
  dThetam = Mat::zeros(1, 1, CV_32F);
  slm = Mat::zeros(1, 1, CV_32F);
  srm = Mat::zeros(1, 1, CV_32F);
  alm = Mat::zeros(1,1, CV_32F);
  arm = Mat::zeros(1,1, CV_32F);
    
  randn(Xm,0.0,pXN);
  randn(Ym,0,pYN);
  randn(Thetam,0,pThetaN);
  randn(dThetam,0,pdThetaN);
  randn(slm,0,pSLN);
  randn(srm,0,pSRN);
  randn(alm, 0,pdSLN);
  randn(arm, 0,pdSRN);

  ProcessNoise.at<float>(0)=Xm.at<float>(0);
  ProcessNoise.at<float>(1)=Ym.at<float>(0);
  ProcessNoise.at<float>(2)=Thetam.at<float>(0);
  ProcessNoise.at<float>(3)=dThetam.at<float>(0);
  ProcessNoise.at<float>(4)=slm.at<float>(0);
  ProcessNoise.at<float>(5)=srm.at<float>(0);
  ProcessNoise.at<float>(6)=alm.at<float>(0);
  ProcessNoise.at<float>(7)=arm.at<float>(0);
  //printf("process noise: x y theta dtheta sl sr asl asr = \n(%f %f %f %f %f %f %f %f)\n",ProcessNoise.at<float>(0),ProcessNoise.at<float>(1),ProcessNoise.at<float>(2),ProcessNoise.at<float>(3),ProcessNoise.at<float>(4),ProcessNoise.at<float>(5),ProcessNoise.at<float>(6),ProcessNoise.at<float>(7));

   RealState.statePost= RealState.statePost + ProcessNoise;
  
   //printf("transition row 4: %f %f %f %f %f %f %f %f\n",RealState.transitionMatrix.at<float>(4,0),RealState.transitionMatrix.at<float>(4,1),RealState.transitionMatrix.at<float>(4,2),RealState.transitionMatrix.at<float>(4,3),RealState.transitionMatrix.at<float>(4,4),RealState.transitionMatrix.at<float>(4,5),RealState.transitionMatrix.at<float>(4,6),RealState.transitionMatrix.at<float>(4,7));


   //printf("x y theta dtheta sl sr asl asr = \n(%f %f %f %f %f %f %f %f)\n",RealState.statePost.at<float>(0),RealState.statePost.at<float>(1),RealState.statePost.at<float>(2),RealState.statePost.at<float>(3),RealState.statePost.at<float>(4),RealState.statePost.at<float>(5),RealState.statePost.at<float>(6),RealState.statePost.at<float>(7));
  //exit(1);
  return RealState;
}

Mat generate_noisy_signals(Mat state,
			   float XN,
			   float YN,
			   float ThetaN,
			   float dThetaN,
			   float slN, 
			   float srN,
			   float aN)
{
  // you don't need this function. its just for testing with a simulated robot
    Mat Xm,Ym,Thetam,dThetam,slm,srm,am;
    Mat Measurements = Mat::zeros(7,1,CV_32F);
    Xm = Mat::zeros(1, 1, CV_32F);
    Ym = Mat::zeros(1, 1, CV_32F);
    Thetam = Mat::zeros(1, 1, CV_32F);
    dThetam = Mat::zeros(1, 1, CV_32F);
    slm = Mat::zeros(1, 1, CV_32F);
    srm = Mat::zeros(1, 1, CV_32F);
    am = Mat::zeros(1,1, CV_32F);

    randn(Xm,state.at<float>(0),XN);
    randn(Ym,state.at<float>(1),YN);
    randn(Thetam,state.at<float>(2),ThetaN);
    randn(dThetam,state.at<float>(3),dThetaN);
    randn(slm,state.at<float>(4),slN);
    randn(srm,state.at<float>(5),srN);
    randn(am, .5*(state.at<float>(6)+state.at<float>(7)),aN);

    Measurements.at<float>(0)=Xm.at<float>(0);
    Measurements.at<float>(1)=Ym.at<float>(0);
    Measurements.at<float>(2)=Thetam.at<float>(0);
    Measurements.at<float>(3)=dThetam.at<float>(0);
    Measurements.at<float>(4)=slm.at<float>(0);
    Measurements.at<float>(5)=srm.at<float>(0);
    Measurements.at<float>(6)=am.at<float>(0);

    NMEAParser parser = NMEAParser();
    char gpsbuf[500] = "$GPRMC,194555.000,A,4025.7231,N,08654.7045,W,1.12,86.33,230714,,,A*47\r\n";
    char gpsbuf2[500] = "$GPGGA,194556.000,4025.7225,N,08654.7040,W,1,05,7.9,201.0,M,-33.8,M,,0000*64\r\n";
    printf("strlen:%d\n",strlen(gpsbuf2));
    parser.Parse(gpsbuf,strlen(gpsbuf));
    parser.Parse(gpsbuf2,strlen(gpsbuf2));
    struct GPSInfo info = parser.GetActualGPSInfo();
    float lat = info.m_latitude;
    float lon = info.m_longitude;
    Point2d GPSpt(fabs(lon),lat);
    Point2d localpt = GPS_to_local(GPSpt,local_origin);
    

    printf("gps (lat long) = (%f %f)\n",lat,lon);
    Measurements.at<float>(0)=localpt.x;//Xm.at<float>(0);
    Measurements.at<float>(1)=localpt.y;//Ym.at<float>(0);

    if (0)
      {
     printf("simulated x: %f measured %f\n simulated y: %f measured %f\n simulated Theta %f measured %f\n simulated dTheta %f measured %f\n simulated sl %f measured %f\n simulated sr %f measured %f\n simulated accel %f measured %f\n",
            state.at<float>(0),
            Measurements.at<float>(0),
            state.at<float>(1),
            Measurements.at<float>(1),
            state.at<float>(2),
            Measurements.at<float>(2),
            state.at<float>(3),
            Measurements.at<float>(3),
            state.at<float>(4),
            Measurements.at<float>(4),
            state.at<float>(5),
            Measurements.at<float>(5),
            .5*(state.at<float>(6)+state.at<float>(7)),
            Measurements.at<float>(6));
      }
    return Measurements;
}

Point2d GPS_to_pixel(Point2d point, int width, int height)
{
    Point2d pixelPoint;
    double GPSx,GPSy,Pixelx,Pixely;
    double dLat,dLong;
    GPSx = point.x;
    GPSy = point.y;
    dLat = MAPT-MAPB;
    dLong = MAPR-MAPL;
    Pixelx = (GPSx-MAPL)/dLong*width;
    Pixely = height-(GPSy-MAPB)/dLat*height;
    pixelPoint.x=Pixelx;
    pixelPoint.y=Pixely;
    return pixelPoint;
}
Point2d GPS_to_local(Point2d GPS,Point2d GPS_of_origin)
{
    double dx = GPS_of_origin.x-GPS.x;
    double dy = GPS.y-GPS_of_origin.y;
    Point2d coord;
    coord.x = dx*METERS_PER_DEGREE_LONG;
    coord.y = dy*METERS_PER_DEGREE_LAT;
    return coord;
}
Point2d local_to_GPS(Point2d local, Point2d GPS_of_origin)
{
    Point2d coord;

    coord.x = GPS_of_origin.x - local.x/METERS_PER_DEGREE_LONG;
    coord.y = GPS_of_origin.y + local.y/METERS_PER_DEGREE_LAT;
    return coord;
}
Point2d local_to_pixel(Point2d local,Point2d GPS_of_origin,int width, int height)
{
    Point2d gps = local_to_GPS(local,GPS_of_origin);
    Point2d pixel = GPS_to_pixel(gps,width,height);
    return pixel;
}

Point2d pixel_to_local(Point2d pixel,Point2d GPS_of_origin, int width, int height)
{
    Point2d gps = pixel_to_GPS(pixel, width, height);
    Point2d local = GPS_to_local(gps,GPS_of_origin);
    return local;
}

Point2d pixel_to_GPS(Point2d pixel, int width, int height)
{
    double dLat = MAPT-MAPB;
    double dLong = MAPR-MAPL;
    Point2d gps;
    gps.x =pixel.x*dLong/width+MAPL;
    gps.y= -pixel.y*dLat/height+dLat+MAPB;
    return gps;
}

Mat ComputeTransitionMatrix(Mat state,float dt)
{
  
  float theta = state.at<float>(2);
  float sl =  state.at<float>(4);
  float sr =  state.at<float>(5);
  float r,dtheta_term;
  Mat TransitionModel = Mat(8,8,CV_32F);
  // if (sl==sr)
  //   dtheta_term=0;
  // else
  //   {
  //     if (sl==0 | sr==0)
  // 	r=rover_width;
  //     else
  // 	if (fabs(sr)>fabs(sl))
  // 	  {
  // 	    r = rover_width/sr/(1/sl - 1/sr); // check this to make sure it is always right
  // 	    dtheta_term = .5*sl/(2*r) + .5*sr/(2*(r+rover_width));
  // 	    //printf("rl rr = %f %f\n",sl/(2*pi*r),sr/(2*pi*(r+rover_width)));
  // 	  }
  // 	else
  // 	  {
  // 	    r = rover_width/sl/(1/sr - 1/sl); // check this to make sure it is always right
  // 	    dtheta_term = .5*sl/(2*(r+rover_width)) + .5*sr/(2*(r));
  // 	    //printf("rl rr = %f %f\n",sl/(2*pi*(r+rover_width)),sr/(2*pi*(r)));
  // 	  }
  //   }
  
  //printf("r = %f, dtheta_term = %f\n",r,dtheta_term);


  TransitionModel = *(Mat_<float>(8,8) <<
		      1, 0, 0, 0,  .5*cos(theta)*dt, .5*cos(theta)*dt, 0,  0,
		      0, 1, 0, 0,  .5*sin(theta)*dt, .5*sin(theta)*dt, 0,  0,
		      0, 0, 1, dt, 0,                0,                0,  0,
		      0, 0, 0, 0,  -1/rover_width,   1/rover_width,    0,  0,
		      0, 0, 0, 0,  1,                0,                dt, 0,
		      0, 0, 0, 0,  0,                1,                0,  dt,
		      0, 0, 0, 0, -beta,             0,                0,  0,
		      0, 0, 0, 0,  0,               -beta,             0,  0);
  return TransitionModel;
}


KalmanFilter execute_time_step(KalmanFilter KF,
			      Mat TransitionModel,
			      Mat MeasurementModel,
			      Mat ControlModel,
			      Mat measurement,
			      Mat control)
{
  KF.transitionMatrix = TransitionModel;
  KF.measurementMatrix = MeasurementModel;
  KF.controlMatrix = ControlModel;
  KF.predict(control);
  KF.correct(measurement);
  return KF;  
}


int main(int, char**)
{
  namedWindow( "Kalman", 1 );
  // things happen in a local coordinate system in meters x,y
  // this coordinate system can be placed anywhere you want with respect to the world GPS system
  // I centered it on the middle of the map

  local_origin.x = (MAPL+MAPR)/2.0;
  local_origin.y = (MAPT+MAPB)/2.0;


  Mat img0 = Mat(800, 800, CV_8UC3);//imread("googleearth_campus_zoomed_in_engineering_mall.bmp");
  Size2i size = img0.size();
  int mapwidth = size.width;
  int mapheight = size.height;
  Mat trackimage = img0.clone();
  Mat displayimage = img0.clone();

  //char filename[1000] = "/aux/dpbarret/vader-rover/logs/2014-07-23-19:35:13/imu-log.txt";
  //char filename[1000] = "/aux/dpbarret/vader-rover/logs/2014-06-24-21:03:16/log.txt";
  char filename[1000] = "/aux/dpbarret/vader-rover/logs/2014-07-24-18:16:58/imu-log.txt";
  Mat measurements[10000];
  //  int nmeasurements = read_log_file("/net/mohio//aux/dpbarret/vader-rover/logs/2014-07-23-19\:43\:35/imu-log.txt", measurements);
  int nmeasurements = read_log_file(filename, measurements);


  Mat measurement = Mat::zeros(7,1,CV_32F);
  Mat control = Mat::zeros(2,1,CV_32F);
  Mat MeasurementModel = Mat::zeros(7,8,CV_32F);
  Mat MeasurementModel_noGPS = Mat::zeros(7,8,CV_32F);
  Mat TransitionModel =  Mat::zeros(8,8,CV_32F);

  KalmanFilter KF(8, 7, 2); // 8 state variables, 7 measurements, 2 inputs
  KalmanFilter simulation(8,7,2);

  KF.measurementNoiseCov = *(Mat_<float>(7,7) <<
                             mXN, 0,   0,       0,        0,    0,    0,     
                             0,   mYN, 0,       0,        0,    0,    0,     
                             0,   0,   mThetaN, 0,        0,    0,    0,     
                             0,   0,   0,       mdThetaN, 0,    0,    0,     
                             0,   0,   0,       0,        mSLN, 0,    0,     
                             0,   0,   0,       0,        0,    mSRN, 0,     
                             0,   0,   0,       0,        0,    0,    mAN);

  KF.processNoiseCov = *(Mat_<float>(8,8) <<
			 pXN, 0,   0,       0,        0,    0,    0,     0,     
			 0,   pYN, 0,       0,        0,    0,    0,     0,     
			 0,   0,   pThetaN, 0,        0,    0,    0,     0,    
			 0,   0,   0,       pdThetaN, 0,    0,    0,     0,     
			 0,   0,   0,       0,        pSLN, 0,    0,     0,     
			 0,   0,   0,       0,        0,    pSRN, 0,     0,    
			 0,   0,   0,       0,        0,    0,    pdSLN, 0,
			 0,   0,   0,       0,        0,    0,    0,     pdSRN);

  KF.controlMatrix = *(Mat_<float>(8,2) <<
		       0,     0,
		       0,     0,
		       0,     0,
		       0,     0,
		       0,     0,
		       0,     0,
		       alpha, 0,
		       0,     alpha);

  // measure x,y,theta,dtheta,sl,sr, and acceleration, which is avg of wheel accelerations
  MeasurementModel = *(Mat_<float>(7,8) <<
			 1, 0, 0, 0, 0, 0,  0,   0,
			 0, 1, 0, 0, 0, 0,  0,   0,
			 0, 0, 1, 0, 0, 0,  0,   0,
			 0, 0, 0, 1, 0, 0,  0,   0,
			 0, 0, 0, 0, 1, 0,  0,   0,
			 0, 0, 0, 0, 0, 1,  0,   0,
			 0, 0, 0, 0, 0, 0,  .5,  .5);

 // measure theta,dtheta,sl,sr, and acceleration, which is avg of wheel accelerations		       
  MeasurementModel_noGPS = *(Mat_<float>(7,8) <<
			       0, 0, 0, 0, 0, 0,  0,   0,
			       0, 0, 0, 0, 0, 0,  0,   0,
			       0, 0, 1, 0, 0, 0,  0,   0,
			       0, 0, 0, 1, 0, 0,  0,   0,
			       0, 0, 0, 0, 1, 0,  0,   0,
			       0, 0, 0, 0, 0, 1,  0,   0,
			       0, 0, 0, 0, 0, 0,  .5,   .5);

  simulation.measurementNoiseCov = KF.measurementNoiseCov.clone();
  simulation.processNoiseCov = KF.processNoiseCov.clone();
  simulation.controlMatrix = KF.controlMatrix.clone();
  simulation.measurementMatrix = MeasurementModel_noGPS.clone();

  KF.statePre.at<float>(2) = measurements[0].at<float>(2);
  KF.statePost.at<float>(2) = measurements[0].at<float>(2);
  int timestep=0;
  for(timestep=0;timestep<nmeasurements;timestep++)
    {
      
      float dt = 1.0/50.0;

      TransitionModel = ComputeTransitionMatrix(KF.statePost,dt);
      //simulation.transitionMatrix = ComputeTransitionMatrix(simulation.statePost,dt);
      
      // arbitrary input to make it turn in a circle replace with whatever we are sending to the robot now
      float CL = 0;//3.0;
      float CR = 0;//2.98;
      control = *(Mat_<float>(2,1) << CL,CR);
      //simulation = updatesimulatedState(simulation, dt, CL, CR, rover_width); // you don't need this

      // this line is replaced by reading actual measurements
      measurement = measurements[timestep];//generate_noisy_signals(simulation.statePost, mXN,mYN,mThetaN, mdThetaN, mSLN, mSRN,mAN);

      float mtheta = measurement.at<float>(2);
      float stheta = KF.statePost.at<float>(2);
      while (mtheta<=stheta-pi)
	mtheta+=2*pi;
      while (mtheta>=stheta+pi)
	mtheta-=2*pi;
      
      // printf("measured x %f\n measured y: %f\n measured Theta %f\n measured dTheta %f\n measured sl %f\n measured sr %f\n measured accel %f\n",
      // 	     measurement.at<float>(0),
      // 	     measurement.at<float>(1),
      // 	     measurement.at<float>(2),
      // 	     measurement.at<float>(3),
      // 	     measurement.at<float>(4),
      // 	     measurement.at<float>(5),
      // 	     measurement.at<float>(6));
      if (1)//measurement.at<float>(3) * measurement.at<float>(4) < 0)
	{
	  printf("wheel speeds: %f %f\n",measurement.at<float>(4), measurement.at<float>(5));
	}
   
      if (timestep%50==0) // every 50th time step we get a gps measurement
	{
	  KF = execute_time_step(KF, TransitionModel,MeasurementModel_noGPS, KF.controlMatrix, measurement,control);
	  // draw the gps measurement
	  Point2d gpspoint(measurement.at<float>(0),measurement.at<float>(1));
	  circle( displayimage,local_to_pixel(gpspoint,local_origin,mapwidth,mapheight),1,Scalar(0,0,255));
	}
      else // otherwise we get a noGPS measurement
	{
	  KF = execute_time_step(KF, TransitionModel,MeasurementModel_noGPS, KF.controlMatrix, measurement,control);
	}
        
      // draw current estimated position onto the map
      // if you got your position from a GPS it should be placed properly on the map
	Point2d position(KF.statePost.at<float>(0),KF.statePost.at<float>(1));
	printf("%f %f\n",position.x,position.y);
	circle( trackimage,local_to_pixel(position,local_origin,mapwidth,mapheight),1,Scalar(255,255,255));
	displayimage = trackimage.clone();
	circle( displayimage,local_to_pixel(position,local_origin,mapwidth,mapheight),3,Scalar(0,255,255));
	 Point2d pospt = local_to_pixel(position,local_origin,mapwidth,mapheight);
	Point2d dirlinept = position;
	dirlinept.x += 1*cos(KF.statePost.at<float>(2));
	dirlinept.y += 1*sin(KF.statePost.at<float>(2));
	Point2d dirlinepx = local_to_pixel(dirlinept,local_origin,mapwidth,mapheight);
	line(displayimage,pospt,dirlinepx,Scalar(0,0,255),1,CV_AA,0);
	//draw simulated position onto the map
	Point2d sim(simulation.statePost.at<float>(0),simulation.statePost.at<float>(1));
		circle( displayimage,local_to_pixel(sim,local_origin,mapwidth,mapheight),1,Scalar(255,0,0));
	if (timestep%1==0)
	  {
	    imshow("Kalman",displayimage);
	    waitKey(1);
	  }

    }
  while (1)
    {
      
    }
    return 0;
}
