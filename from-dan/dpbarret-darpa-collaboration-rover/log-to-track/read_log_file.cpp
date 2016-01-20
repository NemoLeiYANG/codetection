#include "opencv2/video/tracking.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "cv.h"
#include <stdlib.h>
#include <stdio.h>

using namespace cv;
#define pi (3.14159265359)

int main(int, char**)
{
  char filename[1000] = "/aux/dpbarret/vader-rover/logs/2014-07-23-19:35:13/imu-log.txt";
  FILE* fp = fopen(filename,"r");
  char linebuf[1000];
  double encoder_logtime,imu_logtime,tmp_logtime;
  unsigned long encoder_time,encoder_dt,imu_time,imu_dt;
  float L,R;
  float Yaw,Pitch,Roll,Yawa,MAG_ha,MAG_h,Ax,Ay,Az,Mx,My,Mz,Gx,Gy,Gz;
  Mat measurements[10000];
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
      //printf("encoder items:%d\n",encoder_items);
      if (encoder_items == 5)
	{
	  //printf("interpreted full encoder line: %lf %lu %lu %.3f %.3f\n",encoder_logtime,encoder_time,encoder_dt,L,R);
	  encoder_logtime=tmp_logtime;
	  read_encoder=1;
	}
      //printf("imu items:%d\n",imu_items);
      if (imu_items == 18)
	{
	// printf("interpreted full imu line: %lf %lu %lu"
	//        "%.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f\n",
	//        imu_logtime,imu_time,imu_dt,Yaw,Pitch,Roll,Yawa,MAG_ha,MAG_h,Ax,Ay,Az,Mx,My,Mz,Gx,Gy,Gz);
	  	  imu_logtime=tmp_logtime;
	  read_imu=1;
	}
      // if (correct==0)
      // 	{
      // 	  printf("unable to interpret line:\n%s",linebuf);  
      // 	}

      if (read_imu==1 && read_encoder==1)
	{
	  //printf("timing difference: :%f\n",fabs(encoder_logtime-imu_logtime));

	  if (fabs(encoder_logtime-imu_logtime)>.02)
	    {
	      printf("timing misaligned by: :%f\n",fabs(encoder_logtime-imu_logtime));
	      //read_encoder=0;
	      read_imu=0;
	      read_encoder=0;
	    }
	  else
	    {
	  Measurement.at<float>(0) = 0; //no gps for now
	  Measurement.at<float>(1) = 0; //no gps for now
	  Measurement.at<float>(2) = (-Yaw-90)*pi/180 ; //degrees north is 0 east is positive->(radians east 0 north positive)
	  Measurement.at<float>(3) = Gz*pi/180; // rotation around z in degrees/sec ->(radians/sec)
	  Measurement.at<float>(4) = L/100.0/(encoder_dt/1000.0); // cm traveled in last time period -> (meters/sec)
	  Measurement.at<float>(5) = R/100.0/(encoder_dt/1000.0); // cm traveled in last time period -> (meters/sec)
	  Measurement.at<float>(6) = Ax/100; // cm/s^2 -> (m/s^2)       // x forward y right
	  

	  measurements[n_measurements] = Measurement;
	  n_measurements++;
	  read_imu=0;
	  read_encoder=0;
	    }
	}

    }
  printf("n_measurements:%d\n",n_measurements);
  return 0;
}
