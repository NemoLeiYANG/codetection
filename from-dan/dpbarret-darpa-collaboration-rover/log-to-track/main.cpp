#include "opencv2/video/tracking.hpp"
#include "opencv2/highgui/highgui.hpp"

#include <stdio.h>
#include <time.h>
#include "Dstar.h"
#include "cv.h"
#include "mGPSInfo.h"
#include "mNMEAParser.h"


#define TEST


#define drawCross( center, color, d )                                 \
                line( img, Point( center.x - d, center.y - d ),                \
                             Point( center.x + d, center.y + d ), color, 1, CV_AA, 0); \
                line( img, Point( center.x + d, center.y - d ),                \
                             Point( center.x - d, center.y + d ), color, 1, CV_AA, 0 )

#define pi (3.14159)
#define METERS_PER_DEGREE (111310.4035)

//////Zoomed out
// #define  MAPL (86.93213056)
// #define  MAPR (86.90999167)
// #define  MAPT (40.43241667)
// #define  MAPB (40.42354722)
//////Engr fountain
// #define  MAPL (86.91629167)
// #define  MAPR (86.91122778)
// #define  MAPT (40.42976389)
// #define  MAPB (40.42775556)
//////Bogus map
#define  MAPL (86.91620167)
#define  MAPR (86.91610778)
#define  MAPT (40.42970389)
#define  MAPB (40.42960556)

//////Hilltop
//#define  MAPL (86+55.0/60+39.87/3600)
//#define  MAPR (86+55.0/60+15.52/3600)
//#define  MAPT (40+26.0/60+1.59/3600)
//#define  MAPB (40+25.0/60+51.89/3600)

//-------------------------------------------------------
using namespace cv;

static inline Point calcPoint(Point2f center, float R, float angle)
{
    return center + Point2f((float)cos(angle), (float)-sin(angle))*(float)R;
}
typedef struct Waypoint
{
    float x;
    float y;
    struct Waypoint* next;
    struct Waypoint* prev;
    struct Waypoint* head;

} Waypoint;

typedef struct Control_Vector
{
    float ul;
    float ur;
    float theta_err;
    float dist_err;

} Control_Vector;

typedef struct Intersection
{
    int exists;
    float x;
    float y;
} Intersection;

typedef struct Obstacle
{
    float P1x;
    float P1y;
    float P2x;
    float P2y;
    struct Obstacle* next;
    struct Obstacle* prev;
    struct Obstacle* head;

} Obstacle;

typedef struct Known_Obstacle
{
    float x;
    float y;
    struct Known_Obstacle* next;
    struct Known_Obstacle* prev;
    struct Known_Obstacle* head;

} Known_Obstacle;


typedef struct Detection_line
{
    float P1x;
    float P1y;
    float P2x;
    float P2y;
    struct Detection_line* next;
    struct Detection_line* prev;
    struct Detection_line* head;

} Detection_line;


Waypoint* init_waypoints();
float set_control(Control_Vector lastcontrol, Mat State, Waypoint* nextwaypoint,float w);

KalmanFilter kalmaninit(float theta,float ml, float mr, float dt);
Mat generate_noisy_signals(Mat state, float XN,float YN, float ThetaN, float dThetaN, float slN, float srN, float aN);
KalmanFilter updateRealstate(KalmanFilter RealState, float dt, float ul, float ur, float w);
Intersection find_intersection(float P1x1, float P1y1, float P1x2, float P1y2,  float P2x1, float P2y1, float P2x2, float P2y2);
Obstacle* Obstaclesinit(Dstar *dstar);

void display_real_obstacles(Obstacle* head, Mat *img, Point2d origin, int width, int height);
void display_detection_lines(Detection_line* obstaclelist,Mat *img, int onoff, Point2d origin, int width, int height);
void display_known_obstacles(Known_Obstacle* knownlist,Mat *img, Point2d origin, int width, int height);
void display_path(list<state>,Mat*,int c, Point2d origin, int width, int height);
void display_waypoints(Waypoint* head, Mat &img,Point2d GPS_of_origin,int width,int height);

Detection_line* create_detection_lines(Mat State);
Known_Obstacle* detect_obstacles(Obstacle* obstaclelist, Mat State,Dstar* dstar);
void init_graph(Dstar *dstar, float x1, float y1, float x2, float y2);

Point2d GPS_to_pixel(Point2d gps,int width,int height);
Point2d GPS_to_local(Point2d gps,Point2d GPS_of_origin);
Point2d local_to_GPS(Point2d );
Point2d local_to_pixel(Point2d local, Point2d GPS_origin,int width, int height);
Point2d pixel_to_GPS(Point2d pixel, int width, int height);
Point2d pixel_to_local(Point2d pixel,Point2d GPS_of_origin, int width, int height);

void insert_Back(Waypoint* newwaypoint);
void insert_Front(Waypoint* newwaypoint);

int generate_fake_range_data(Obstacle* obstaclelist, Mat State,Dstar* dstar);
void camera_on_mouse( int event, int x, int y, int flags, void* param );

int int_round(double r)
{
    return (r > 0.0) ? floor(r + 0.5) : ceil(r - 0.5);
}

float convert_encoder_to_speed(int wheel_encoder);
float convert_acceleration(int acceleration);

int camera_track(int scan);
void camera_on_mouse( int event, int x, int y, int flags, void* param );
void initialize_camera();

#ifdef WINDOWS 
extern HANDLE cam_hSerial;
#endif

//--------------Global Variables-----------------------
static Waypoint* waypointlist;
Waypoint* waypoint;
static Point2d local_origin;
static int mapwidth;
static int mapheight;
static Dstar *dstar;
//-------------------------------------------------------
class Atom_board_module;

void onMouse( int event, int ix, int iy, int flags, void* param )
{
    if( event == CV_EVENT_RBUTTONDOWN )
    {
        //int key = waitKey(1);
        Point2d pixpt(ix,iy);
        printf("pixpt = (%d,%d)\n",ix,iy);
        Point2d localpt = pixel_to_local(pixpt,local_origin,mapwidth,mapheight);
        printf("localpt = (%f,%f)\n",localpt.x,localpt.y);
        Waypoint* newwaypoint = (Waypoint*)malloc(sizeof(Waypoint));
        newwaypoint->x = localpt.x;
        newwaypoint->y = localpt.y;

        if (flags == 18)//	CV_EVENT_FLAG_SHIFTKEY )
        {
            printf("Right-shift click\n");
            //printf("waypointlist=%p (%f,%f)\n",waypoint,waypoint->x,waypoint->y);
            insert_Back(newwaypoint);
            // printf("waypointlist=%p (%f,%f)\n",waypoint,waypoint->x,waypoint->y);
        }
        else
        {
            printf("Right-click: %d\n",flags);
            insert_Front(newwaypoint);

        }
        dstar->updateGoal(int_round(waypoint->x*4.0), int_round(waypoint->y*4.0));
    }
}

class Kalman_Module
{
public:
    Mat control;
    Mat Rmeasurement;
    Mat Rprediction;
    Mat Rcorrection;
    Mat Realprediction;
    Mat Realcontrol;

    float dt;
    float real_dt;
    // constants
    float w;
    float mr;
    float ml;

    // intitialization
    float x;
    float y;
    float theta;
    float realsl,realsr;
    float sl;
    float sr;
    float a;

    float XN;
    float YN;
    float ThetaN;
    float dThetaN;
    float slN;
    float srN;
    float aN;

    KalmanFilter RKF;
    KalmanFilter RealState;
    Mat MeasurementMAT_noGPS;
    Mat MeasurementMAT_noaccel;
    Mat MeasurementMAT_noaccel_or_compass;
    Mat MeasurementMAT_noGPS_or_accel;
    Mat MeasurementMAT_nosensors;
    Mat MeasurementMAT;

    void KalmanUpdate();
};

class Display_Module
{
public:
};

class UI_Module
{
public:
    Atom_board_module* atom;
    float xerr,yerr,rerr;
    Mat img;
    Mat obstacleimg;
    float GPSavgx,GPSavgy;
    float nGPS;
    Point2d GPSavg,pixpoint;
    void Display();

};

class Navigation_Module
{
public:
    Obstacle* obstaclelist;
    Detection_line* detection_lines;
    Known_Obstacle* knownlist;
    list<state> mypath;
    Control_Vector control_vec;
    Waypoint dummy;
    Waypoint* subwaypoint;

    float ul;
    float ur;
    float x,y;
    float distance;
    Atom_board_module* atom;
    float obstaclex, obstacley;
    unsigned char LPWM,RPWM,DIR,leftdir,rightdir;


    void Navigate();
    void find_obstacle_location();
    void clear_line_of_sight();
    void add_obstacle();
};

class Coordinate_System_Module
{
public:

};

class Communication_Module
{
public:
    NMEAParser *parser;
    Atom_board_module *atom;
    GPSInfo info;
    float latitude,longitude;
    unsigned char outpacket[26];
    unsigned char inmicro1buf[26];
    unsigned char inmicro2buf[26];
    unsigned char inGPSbuf[400];
#ifdef WINDOWS
  HANDLE hSerial_Micro1,hSerial_Micro2,hSerial_GPS,hSerial_CAM;
#endif
    float time_since_sync;


    int Initialize_Com(int ComNum, int type);
    int Receive_Packet(int type);
};

class Fake_Measurement_Module
{
public:
    int GPS_count;
    Detection_line* detection_lines;
    Known_Obstacle* knownlist;
};

class Atom_board_module
{
    //Variables

public:



    int new_micro1_data,new_micro2_data,new_gps_data;
    int accelerometerx, accelerometery,accelerometerz;
    short int compassx,compassy,compassz;
    int wheel_encoderL, wheel_encoderR;
    int SONIC, IR1, IR2, CAM_PWM;
    int dev1_open,dev2_open,dev3_open;
    float Rspeed,Lspeed;
    int ldir,rdir; //just 1 or -1 to tell which way the wheel should be turning
    float CAM_Theta,NAV_Theta;
    double seconds,prev_seconds, dt,seconds_since_last_GPS;
    unsigned char WHEEL_ENCODER_INDIR;
    unsigned char SYNCH1_IN,SYNCH2_IN;
    unsigned char SYNCH1_OUT,SYNCH2_OUT;
    int Camera_Tracking;
    int scan;
    //unsigned char leftdir,rightdir,DIR,LPWM,RPWM;
    float left_error,right_error,delta_error_left,delta_error_right,left_error_prev,right_error_prev;
    int tLPWM,tRPWM, incr, incl;

    class Kalman_Module kalman_module;
    class Display_Module display_module;
    class UI_Module ui_module;
    class Navigation_Module navigation_module;
    class Coordinate_System_Module coordinate_system_module;
    class Fake_Measurement_Module fake_measurement_module;
    class Communication_Module communication_module;
    //Methods
    // float convert_encoder_to_speed(int wheel_encoder); //crashes
    // Does everything
    void Run();

    void wheel_control(float speedleft, float speedright);
    void Initialize();
    // void Initialize_Map_View();

    // Communication methods
    //void Initialize_Com(int ComNum, int type);
  #ifdef WINDOWS
    void Send_Packet(int type,unsigned char* data,int len);
  #endif
    void Get_Sensor_Data();
    void Get_Fake_Sensor_Data();
    void Get_Fake_Packets();
    // Kalman filter methods
    // this is a kalman_module function void KalmanUpdate();

    // Obstacle Detection and mapping
    void Update_Obstacle_Map();

    // Control System and Pathfinder
    // this is a navigation_module function void Navigate();



    // Draw everything on the screen and display it
    void Display();

};

void Navigation_Module::find_obstacle_location()
{
    float distance = atom->SONIC; //---- units sre cm?
    float theta = atom->kalman_module.RKF.statePost.at<float>(2) - atom->CAM_Theta*2*pi/360;
    float x = atom->kalman_module.RKF.statePost.at<float>(0);
    float y = atom->kalman_module.RKF.statePost.at<float>(1);

    float dx = 1.0/100*distance*cos(theta);  //in meters
    float dy = 1.0/100*distance*sin(theta);

    obstaclex = x+dx;
    obstacley = y+dy;
}

void Navigation_Module::clear_line_of_sight()
{
    float distance = atom->SONIC; //---- units sre cm?
    float theta = atom->kalman_module.RKF.statePost.at<float>(2) - atom->CAM_Theta*2*pi/360;
    float x = atom->kalman_module.RKF.statePost.at<float>(0);
    float y = atom->kalman_module.RKF.statePost.at<float>(1);
    float d = 0;
    float x0=x,y0=y;
    float dtheta=0;
    if (distance>150) distance=150;
    for (dtheta=-pi/8; dtheta<pi/8; dtheta+=pi/28)
    {

        d=0;
        while (d<distance/100.0)
        {
            x0 = x+d*cos(theta+dtheta);
            y0 = y+d*sin(theta+dtheta);
            d += .05;
            dstar->updateCell_increment(int_round(x0*4.0),int_round(y0*4.0),-5);
            Point2d pt(x0,y0);
            Point2d pixpt = local_to_pixel(pt,local_origin,mapwidth,mapheight);
            circle(atom->ui_module.obstacleimg,pixpt,4,Scalar(0,0,0));

        }
    }
}
void Navigation_Module::add_obstacle()
{
    float distance = atom->SONIC; //---- units sre cm?
    float theta = atom->kalman_module.RKF.statePost.at<float>(2) - atom->CAM_Theta*2*pi/360;
    float x = atom->kalman_module.RKF.statePost.at<float>(0);
    float y = atom->kalman_module.RKF.statePost.at<float>(1);
    float x0=x,y0=y;
    float dtheta;
    for (dtheta=-pi/8; dtheta<pi/8; dtheta+=pi/48)
    {


        x0 = x+distance*cos(theta+dtheta)/100;
        y0 = y+distance*sin(theta+dtheta)/100;
        dstar->updateCell(int_round(x0*4.0),int_round(y0*4.0),55);
        Point2d pt(x0,y0);
        Point2d pixpt = local_to_pixel(pt,local_origin,mapwidth,mapheight);
        circle(atom->ui_module.obstacleimg,pixpt,2,Scalar(0,255,0));


        x0 = x+distance*cos(theta+dtheta)/130;
        y0 = y+distance*sin(theta+dtheta)/130;
        dstar->updateCell(int_round(x0*4.0),int_round(y0*4.0),55);
        pt.x=x0;
        pt.y=y0;
        pixpt = local_to_pixel(pt,local_origin,mapwidth,mapheight);
        circle(atom->ui_module.obstacleimg,pixpt,2,Scalar(0,150,0));

        /*x0 = x+distance*cos(theta+dtheta)/80;
        y0 = y+distance*sin(theta+dtheta)/80;
        dstar->updateCell(x0,y0,55);
        pt.x=x0;
        pt.y=y0;
        pixpt = local_to_pixel(pt,local_origin,mapwidth,mapheight);
        circle(atom->ui_module.obstacleimg,pixpt,2,Scalar(0,150,0));*/

        //printf("obstacle=(%f,%f) which is pixel (%f,%f)\n",pt.x,pt.y,pixpt.x,pixpt.y);

    }

}

void Atom_board_module::Get_Fake_Sensor_Data()
{
    kalman_module.Rmeasurement = generate_noisy_signals(kalman_module.RealState.statePre, kalman_module.XN,kalman_module.YN, kalman_module.ThetaN, kalman_module.dThetaN, kalman_module.slN, kalman_module.srN,kalman_module.aN);
    fake_measurement_module.detection_lines = create_detection_lines(kalman_module.RealState.statePost);
    //display_detection_lines(detection_lines,&img,1);
    fake_measurement_module.knownlist = detect_obstacles(navigation_module.obstaclelist, kalman_module.RealState.statePost,dstar);

    SONIC = 100*generate_fake_range_data(navigation_module.obstaclelist, kalman_module.RealState.statePost,dstar);
   // printf("SONIC=%d\n",SONIC);
    display_known_obstacles(fake_measurement_module.knownlist,&ui_module.img,local_origin,mapwidth,mapheight);
}
void Atom_board_module::Get_Fake_Packets()
{
    Mat tempfake = generate_noisy_signals(kalman_module.RealState.statePre, kalman_module.XN,kalman_module.YN, kalman_module.ThetaN, kalman_module.dThetaN, kalman_module.slN, kalman_module.srN,kalman_module.aN);

    // need a function to generate fake rangefinder data

    int x = rand()%100;
   // printf("rand=%d\n",x);
    communication_module.inmicro1buf[0]=0xFF; //start
    communication_module.inmicro1buf[1]=0x01; //type 1
    communication_module.inmicro1buf[2]=0xFF; // accel xmsb
    communication_module.inmicro1buf[3]=0xFF; // accel xmsb
    communication_module.inmicro1buf[4]=0xFF; // accel xmsb
    communication_module.inmicro1buf[5]=0xFF; // accel xmsb
    communication_module.inmicro1buf[6]=0xFF; // accel xmsb
    communication_module.inmicro1buf[7]=0xFF; // accel xmsb
    communication_module.inmicro1buf[8]=0xFF; // L wheel msb
    communication_module.inmicro1buf[9]=0xFF; // L wheel lsb
    communication_module.inmicro1buf[10]=0xFF;//IR
    communication_module.inmicro1buf[11]=0xFE;//IR
    communication_module.inmicro1buf[12]=0xFF;//SONIC
    communication_module.inmicro1buf[13]=0xFE;//stop byte

    communication_module.inmicro1buf[0]=0xFF; //start
    communication_module.inmicro2buf[1]=0x01; //type 1
    communication_module.inmicro2buf[2]=0xFF; // compass xmsb
    communication_module.inmicro2buf[3]=0xFF; // compass xmsb
    communication_module.inmicro2buf[4]=0xFF; // compass xmsb
    communication_module.inmicro2buf[5]=0xFF; // compass xmsb
    communication_module.inmicro2buf[6]=0xFF; // compass xmsb
    communication_module.inmicro2buf[7]=0xFF; // compass xmsb
    communication_module.inmicro2buf[8]=0xFF; // R wheel msb
    communication_module.inmicro2buf[9]=0xFF; // R wheel lsb
    communication_module.inmicro2buf[10]=0xFE; // stop byte

    //stop



}

void UI_Module::Display()
{
    //printf("1\n");
    Point2d statePt(atom->kalman_module.Rcorrection.at<float>(0),atom->kalman_module.Rcorrection.at<float>(1));

    Point2d pixstatePt = local_to_pixel(statePt,local_origin,mapwidth,mapheight);
    // printf("2\n");
    Point2d realPt(atom->kalman_module.RealState.statePre.at<float>(0),atom->kalman_module.RealState.statePre.at<float>(1));
    Point2d pixrealPt = local_to_pixel(realPt,local_origin,mapwidth,mapheight);
    //printf("3\n");
    Point2d measurePt(atom->kalman_module.Rmeasurement.at<float>(0),atom->kalman_module.Rmeasurement.at<float>(1));
    // printf("31\n");
    Point2d pixmeasurePt = local_to_pixel(measurePt,local_origin,mapwidth,mapheight);
    //statePt= statePt+center;

    //------- clear the map to all black-------//
    //obstacleimg = Scalar::all(0);
    img = obstacleimg.clone();//Scalar::all(0);
    // printf("4\n");

    drawCross( pixstatePt, Scalar(255,0,0), .25 );
    drawCross( pixrealPt, Scalar(255,255,255), .25 );
    drawCross( pixmeasurePt, Scalar(0,0,255), 5);

    // draw a triangle representing the robot
    Point2d frontpoint=statePt;
    Point2d backrightpoint=statePt;
    Point2d backleftpoint=statePt;
    if ((&atom->navigation_module.mypath) != NULL)
    display_path(atom->navigation_module.mypath,&atom->ui_module.img,255,local_origin,mapwidth,mapheight);


    if (waypoint!=NULL)
    {
        //printf("waypoint is not NULL!\n");

    Point2d waypointpt;
    waypointpt.x = waypoint->x;
    waypointpt.y=waypoint->y;
    Point2d pixwaypoint = local_to_pixel(waypointpt,local_origin,mapwidth,mapheight);
    drawCross( pixwaypoint, Scalar(255,255,255), 5);
    }
    float theta = atom->kalman_module.Rcorrection.at<float>(2);
    frontpoint.x = frontpoint.x + .2*cos(theta);
    frontpoint.y = frontpoint.y + .2*sin(theta);

    backrightpoint.x = backrightpoint.x + .1*cos(theta-pi/2.5);
    backrightpoint.y = backrightpoint.y + .1*sin(theta-pi/2.5);

    backleftpoint.x = backleftpoint.x + .1*cos(theta+pi/2.5);
    backleftpoint.y = backleftpoint.y + .1*sin(theta+pi/2.5);

    Point2d pixfront = local_to_pixel(frontpoint,local_origin,mapwidth,mapheight);
    Point2d pixbackleft = local_to_pixel(backleftpoint,local_origin,mapwidth,mapheight);
    Point2d pixbackright = local_to_pixel(backrightpoint,local_origin,mapwidth,mapheight);

    line( img, pixfront,pixbackleft, Scalar(255,255,255), 1, CV_AA, 0);
    line( img, pixfront,pixbackright, Scalar(255,255,255), 1, CV_AA, 0);
    line( img, pixbackright,pixbackleft, Scalar(255,255,255), 1, CV_AA, 0);

    line( img, pixfront,pixstatePt, Scalar(255,255,255), 1, CV_AA, 0);
    //-------------------- end of triangle section------------------

    Point2d camlinept = statePt;
    camlinept.x += cos(-atom->CAM_Theta*2*pi/360+theta);
    camlinept.y += sin(-atom->CAM_Theta*2*pi/360+theta);

    Point2d pixcamlinept = local_to_pixel(camlinept,local_origin,mapwidth,mapheight);
    line( img, pixcamlinept,pixstatePt, Scalar(0,255,255), 1, CV_AA, 0);




//printf("5\n");
    //printf("error matrix[0,0]=%f, [1,1]=%f\n",RKF.errorCovPost.at<float>(0,0),RKF.errorCovPost.at<float>(1,1));
    //-------------------- draw a circle representing the position uncertainty
    xerr = atom->kalman_module.RKF.errorCovPost.at<float>(0,0);
    yerr = atom->kalman_module.RKF.errorCovPost.at<float>(0,0);

    rerr = sqrt(xerr*xerr+yerr*yerr);
    printf("rerr:%f\n",rerr);
    circle(img,pixstatePt,rerr,Scalar(255,0,0));

    //display_real_obstacles(navigation_module.obstaclelist,&(img),local_origin,mapwidth,mapheight);

    //--------------------  end of circle section ----------------
    //drawCross( GPSavgPt, Scalar(0,255,0), 0);
    imshow("Kalman",img);
    //printf("7\n");
}

void Navigation_Module::Navigate()
{
    float x,y;
    float speedright=0, speedleft = 0;
    x = atom->kalman_module.RKF.statePost.at<float>(0);
    y = atom->kalman_module.RKF.statePost.at<float>(1);
    float distance;
    //printf("x=%f y=%f\n",x,y);

    if (waypoint!=NULL)
    {


        distance = sqrt((waypoint->x-x)*(waypoint->x-x) + (waypoint->y-y)*(waypoint->y-y));
        //  printf("distance to waypoint: %f\n",distance);
        //  printf("x=%f, y=%f\n",x,y);


        if ( distance < 1 && waypoint->next!=NULL)
        {
            waypoint=waypoint->next;
            dstar->updateGoal(int_round(waypoint->x*4.0), int_round(waypoint->y*4.0));
            if(dstar->replan())
            {
                //display_path(mypath,&atom->ui_module.img,0,local_origin,mapwidth,mapheight);
                mypath = dstar->getPath();
               // display_path(mypath,&atom->ui_module.img,255,local_origin,mapwidth,mapheight);
            }
            printf("\n\nmade it to WAYPOINT\n\n");
        }

        if (sqrt((x-mypath.front().x/4.0)*(x-mypath.front().x/4.0)+(y-mypath.front().y/4.0)*(y-mypath.front().y/4.0))<.8)
        {

            mypath.pop_front();
            if (!mypath.empty())
            {
                subwaypoint->x=mypath.front().x/4.0;
                subwaypoint->y=mypath.front().y/4.0;
            }
            else
            {
                subwaypoint->x=waypoint->x;
                subwaypoint->y=waypoint->y;
                //  printf("getting closer: (%f,%f)\n",x,y);
            }
            // printf("moving to next sub-waypoint: (%f,%f)\n",subwaypoint->x,subwaypoint->y);
        }
        atom->fake_measurement_module.GPS_count++;
        if (atom->fake_measurement_module.GPS_count==5)
        {
            atom->fake_measurement_module.GPS_count=0;
            //atom->kalman_module.RKF.measurementMatrix = atom->kalman_module.MeasurementMAT;//MeasurementMAT_noGPS;//
            dstar->updateStart(int_round(x*4.0), int_round(y*4.0));
            if(dstar->replan())
            {
               // display_path(mypath,&atom->ui_module.img,0,local_origin,mapwidth,mapheight);
                mypath = dstar->getPath();
                //display_path(mypath,&atom->ui_module.img,255,local_origin,mapwidth,mapheight);
            }
            // imshow( "Kalman", atom->ui_module.img );
            // Sleep((int)5*dt);
            //waitKey(1);

        }
      //  else
      //  {
            // atom->kalman_module.RKF.measurementMatrix = atom->kalman_module.MeasurementMAT_noGPS;
            // atom->kalman_module.Rmeasurement.at<float>(0) = 0;
            // atom->kalman_module.Rmeasurement.at<float>(1) = 0;
            //imshow( "Kalman", img );
            //Sleep((int)5*dt);
            // waitKey(1);
      //  }

      atom->NAV_Theta = -1*set_control(control_vec, atom->kalman_module.RKF.statePost, subwaypoint,atom->kalman_module.w);
      printf("navtheta=%f\n",atom->NAV_Theta);
     //atom->scan=1;
      if (distance<.3)
      {
          printf("made it to waypoint\n");
          waypoint=NULL;
      }
    }


    if (atom->Camera_Tracking==0)
    {
      if (atom->scan==0)
      {
         atom->scan=1;
      }
      if (atom->CAM_Theta>60)
      {
          atom->scan=2;
      }
      if (atom->CAM_Theta<-60)
      {
          atom->scan=1; //left scan
      }

    }
    else
    {
       atom->scan=0;
    }

    //control_vec = set_control(control_vec, atom->kalman_module.RKF.statePost, subwaypoint,atom->kalman_module.w);
    // ul = control_vec.ul;
    // ur = control_vec.ur;



    /* if (ul>0.0)
     {
         atom->ldir=1;
         if (atom->Lspeed>=0)
             leftdir=0b001;
         else
             leftdir=0b100;
     }
     else if (ul<0)
     {
         atom->ldir=-1;
       //  printf("left trying to go backwards or break\n");
         if (atom->Lspeed<=0)
             leftdir=0b010;
         else
             leftdir=0b100;
     }
     else
     {
         leftdir=0b100;
     }
     if (ur>0.0)
     {
         atom->rdir=1;
         if (atom->Rspeed>=0)
             rightdir=0b001;
         else
             rightdir=0b100;
     }
     else if (ur<0)
     {
         atom->rdir=-1;
         //printf("right trying to go backwards or break\n");
         if (atom->Rspeed<=0)
             rightdir=0b010;
         else
             rightdir=0b100;
     }
     else
     {
         rightdir=0b100;
     }
     //leftdir=0b100;
     // rightdir=0b001;
     LPWM=ul*255;
     RPWM=ur*255;
     DIR = leftdir << 4 | rightdir;

     if (atom->IR2<45)
     {
         LPWM=0xFF;
         RPWM=0xFF;
         DIR=0x44;
         printf("stop too close ir2=%d\n",atom->IR2);
         control_vec.ul=0;
         control_vec.ur=0;
     }
     else if (atom->IR1>43 )
     {
         LPWM=0xFF;
         RPWM=0xFF;
         DIR=0x44;
         printf("stop drop ir1=%d\n",atom->IR1);
         control_vec.ul=0;
         control_vec.ur=0;
     }
     else if (atom->IR1<30)
     {
         LPWM=0xFF;
         RPWM=0xFF;
         DIR=0x44;
         printf("stop bump ir1=%d\n",atom->IR1);
         control_vec.ul=0;
         control_vec.ur=0;
     }*/

    int forward_backward;
    float rwheel=0, lwheel=0;
    float control_Theta;
    if (waypoint!=NULL)
    {
        control_Theta=atom->NAV_Theta;
    }
    else
    {
        control_Theta=atom->CAM_Theta;
    }

    //int Camera_Tracking=1;
    if (atom->Camera_Tracking>0 | waypoint!=NULL)
    {

        if (atom->SONIC>40 && atom->SONIC< 70)
        {
            forward_backward=0;
           // printf("stay put\n");
        }
        else if (atom->SONIC>=70)
        {
            // printf("forward\n");
            forward_backward=1;
        }
        else if (atom->SONIC<=40)
        {
            // printf("bakward\n");
            forward_backward=-1;
        }

        //printf("-------Theta = %f\n",atom->CAM_Theta);
        if (control_Theta < -20.0) // turn left
        {
            //printf("left\n");

            // LPWM=(unsigned int)(-atom->CAM_Theta*4);
            //RPWM=(unsigned int)(-atom->CAM_Theta*4);
            // lwheel = (atom->CAM_Theta)/90.0;
            // rwheel = (-atom->CAM_Theta)/90.0;
            // printf("lwheel = %f, rwheel = %f \n", lwheel, rwheel);
            //  atom->wheel_control(lwheel, rwheel );
//

            //LPWM=(unsigned int)(-atom->CAM_Theta*3);
            //RPWM=(unsigned int)(-atom->CAM_Theta*3);
            // if (forward_backward==0)
            //     DIR=0x21;
             if (forward_backward==0)
             {
                 //DIR=0x21;
                 //RPWM = 255;
                 //LPWM=255;

                 lwheel = (control_Theta)/90.0;
                 rwheel = (-control_Theta)/90.0;
                 //printf("lwheel = %f, rwheel = %f \n", lwheel, rwheel);
                 atom->wheel_control(lwheel, rwheel );

             }
             else if (forward_backward ==1)
            {
                //DIR=0x21;
                //RPWM = 255;
                //LPWM=255;
                lwheel = 0;
                rwheel = (-control_Theta)/90.0;
                //printf("lwheel = %f, rwheel = %f \n", lwheel, rwheel);
                atom->wheel_control(lwheel, rwheel );
            }
            else if (forward_backward==-1)
            {

                lwheel = (control_Theta)/90.0;
                rwheel = 0;
                //printf("lwheel = %f, rwheel = %f \n", lwheel, rwheel);
                atom->wheel_control(lwheel, rwheel );
                // DIR=0x24;
                //LPWM=255;
                //RPWM=255;
            }
        }
        else if (control_Theta > 20.0) // turn right
        {
            //printf("right\n");
            /* if (atom->CAM_Theta*4 <=255)
             {
                 LPWM=(unsigned int)(atom->CAM_Theta*4);
                 RPWM=(unsigned int)(atom->CAM_Theta*4);
                 printf("DONT\n\n\n\n");
                // atom->wheel_control((atom->CAM_Theta*4)/90,(atom->CAM_Theta*4)/90 );
             }
             else
             {
                 LPWM=255;
                 RPWM=255;
             }
             DIR=0x12;*/
            // if (forward_backward==0)
            //{
            //    DIR=0x12;

            // }

            if (forward_backward == 0)
            {
                lwheel = (control_Theta)/90.0;
                rwheel = (-control_Theta)/90.0;
                //printf("lwheel = %f, rwheel = %f \n", lwheel, rwheel);
                atom->wheel_control(lwheel, rwheel );

            }
            else if (forward_backward==1)
            {
                // DIR=0x14;
                // LPWM=255;
                // RPWM=255;
                lwheel = (control_Theta)/90.0;
                rwheel = 0;
                //printf("lwheel = %f, rwheel = %f \n", lwheel, rwheel);
                atom->wheel_control(lwheel, rwheel );
            }

            else if (forward_backward==-1)
            {
                // DIR=0x42;
                //LPWM=255;
                //RPWM=255;
                lwheel = 0;
                rwheel = -(control_Theta)/90.0;
                //printf("lwheel = %f, rwheel = %f \n", lwheel, rwheel);
                atom->wheel_control(lwheel, rwheel );
            }
        }
        else // go forward/backward/do nothing
        {
            LPWM = 0x80;
            RPWM = 0x80;
	    lwheel = .5;
	    rwheel = .5;

            if (forward_backward==0)
                DIR=0x44;
            else if (forward_backward==1)
            {
                DIR=0x11;
                atom->wheel_control(atom->SONIC/500.0, atom->SONIC/500.0);
                if (waypoint!=NULL)
                {
                    float distance_speed = (distance+1)/5;
                    if (distance_speed>.5) distance_speed=.5;
                    atom->wheel_control(distance_speed, distance_speed);
                }

                if (atom->IR2<65)
                {
                    LPWM=0xFF;
                    RPWM=0xFF;
                    DIR=0x44;
                   // printf("stop too close ir2=%d\n",atom->IR2);
                    control_vec.ul=0;
                    control_vec.ur=0;
                }
                else if (atom->IR1>43 )
                {
                    LPWM=0xFF;
                    RPWM=0xFF;
                    DIR=0x44;
                    //printf("stop drop ir1=%d\n",atom->IR1);
                    control_vec.ul=0;
                    control_vec.ur=0;
                }
                else if (atom->IR1<30)
                {
                    LPWM=0xFF;
                    RPWM=0xFF;
                    DIR=0x44;
                    //printf("stop bump ir1=%d\n",atom->IR1);
                    control_vec.ul=0;
                    control_vec.ur=0;
                }
            }

            else if (forward_backward==-1)
            {
                DIR=0x22;
                atom->wheel_control(-(55 - atom->SONIC)/50.0, -(55 - atom->SONIC)/50.0);
                control_vec.ul=-1;
                control_vec.ur=-1;
            }


        }
    }
    else
    {
        LPWM=0xFF;
        RPWM=0xFF;
        speedleft = 0;
        speedright = 0;
        DIR=0x44;
    }




    //speedright= 0.2;
    //speedleft = 0.2;
    //DIR=0x11;
    //atom->wheel_control(speedleft, speedright);

    //printf("MICRO SENDING \n\nsul=%f ur=%f,LPWM=%x RPWM=%x DIR=%x ldir=%x, rdir=%x\n",ul,ur,LPWM,RPWM,DIR ,leftdir,rightdir);
   // printf("SONIC=%d\n",atom->SONIC);
    unsigned char micropacket[20];
    micropacket[0] = 0xFF;
    micropacket[1] = 0x4;
    micropacket[2] = RPWM;
    micropacket[3] = LPWM;
    micropacket[4] = DIR;
    // micropacket[5] = atom->SYNCH2_OUT;
    micropacket[5] = 0xFE;
    #ifdef WINDOWS
    atom->Send_Packet(2,micropacket,6);
    #endif

    printf("ul=%f ur=%f\n",speedleft,speedright);
    atom->kalman_module.control =   *(Mat_<float>(8,1) << 0, 0, 0, atom->dt*atan((atom->kalman_module.sr-atom->kalman_module.sl)/atom->kalman_module.w),0,0,lwheel*3,rwheel*3);//control_vec.ul,control_vec.ur);
    //printf("control matrix(3) = %f\n",atom->kalman_module.control.at<float>(3));
}
void Kalman_Module::KalmanUpdate()
{
    //printf("kamanupdate1\n");
     for (int i=0; i<50; i++)
      RealState = updateRealstate(RealState,dt/50.0, control.at<float>(6), control.at<float>(7), w);
    //printf("kamanupdate2\n");
    Rprediction = RKF.predict(control);
    Rcorrection = RKF.correct(Rmeasurement);

    Rcorrection.at<float>(2)=Rmeasurement.at<float>(2);

    /* printf("transition: %f, %f, %f, %f,%f,%f\n",RKF.transitionMatrix.at<float>(0,0),
            RKF.transitionMatrix.at<float>(0,1),
            RKF.transitionMatrix.at<float>(0,2),
            RKF.transitionMatrix.at<float>(0,3),
            RKF.transitionMatrix.at<float>(0,4),
            RKF.transitionMatrix.at<float>(0,5));
    */
    RKF.transitionMatrix.at<float>(0,4) = .5*cos( Rcorrection.at<float>(2))*dt;
    RKF.transitionMatrix.at<float>(0,5) = .5*cos( Rcorrection.at<float>(2))*dt;

    RKF.transitionMatrix.at<float>(1,4) = .5*sin( Rcorrection.at<float>(2))*dt;
    RKF.transitionMatrix.at<float>(1,5) = .5*sin( Rcorrection.at<float>(2))*dt;

    RKF.transitionMatrix.at<float>(2,3) =dt;
    RKF.transitionMatrix.at<float>(4,6) =dt;
    RKF.transitionMatrix.at<float>(5,7) =dt;


    sl = Rcorrection.at<float>(4);
    sr = Rcorrection.at<float>(5);
}

float extract_theta_from_PWM(unsigned int CAM_PWM)
{
    //0x0708(1800) is straight = 0 degrees
    //-------------
    //0x0280(640) is left = 90 degrees
    //0x0b2c(2860) is right = -90 degrees
    // range is 2220
    float theta = ((int)CAM_PWM-1800)*180.0/2220.0;
    //printf("theta=%f(degrees)\n",theta);
    return theta;


}

#ifdef WINDOWS
void Atom_board_module::Get_Sensor_Data()
{
    /*    int accelerometerx, accelerometery,accelerometerz;
    int compassx,compassy,compassz;
    int wheel_encoderL, wheel_encoderR;
    int SONIC, IR1, IR2;*/
    unsigned int  xMSB, xLSB, yMSB, yLSB, zMSB, zLSB;
    unsigned int wMSB,wLSB, CAM_PWM_MSB, CAM_PWM_LSB, SONIC_LSB,SONIC_MSB;
    float theta;
    int latitude, longitude;
    int valid1=0,valid2=0,GPSchars=0;
    char compass_flag;
    // printf("about to try to get packets\n");
    if (dev1_open==1)
    {
        valid1 = communication_module.Receive_Packet(1);
        // printf("read frmo 1, valid=%d\n",valid1);

    }
    if (dev2_open==1)
    {
        valid2 = communication_module.Receive_Packet(2);
        // printf("read frmo 2 valid=%d\n",valid2);
    }
    if (dev3_open==1 && seconds_since_last_GPS>1)
    {
        GPSchars = communication_module.Receive_Packet(3);
        //  printf("read frmo 3v alid=%d\n",GPSchars);
    }
    // printf("finished a series of attempted packet reads, the returned values are %d %d %d\n",valid1,valid2,GPSchars);
    if (valid1!=-1) // if the read was successful
    {
        // accelerometer: xMSB xLSB yMSB yLSB zMSB zLSB
        // wheel encoder: MSB LSB
        // 3 rangefinders: IR IR SONIC
        xMSB = communication_module.inmicro1buf[2];
        xLSB = communication_module.inmicro1buf[3];
        yMSB = communication_module.inmicro1buf[4];
        yLSB = communication_module.inmicro1buf[5];
        zMSB = communication_module.inmicro1buf[6];
        zLSB = communication_module.inmicro1buf[7];

        accelerometerx = (xMSB<<8) | xLSB;
        accelerometery = (yMSB<<8) | yLSB;
        accelerometerz = (zMSB<<8) | zLSB;

        wMSB = communication_module.inmicro1buf[8];
        wLSB = communication_module.inmicro1buf[9];
        // printf("wheelmsb=%x wheellsb=%x\n",wMSB,wLSB);
        wheel_encoderR = (wMSB<<8) | wLSB;   // ------------------------L or R?


        IR1 = communication_module.inmicro1buf[10];
        IR2 = communication_module.inmicro1buf[11];
        SONIC_MSB = communication_module.inmicro1buf[12];
        SONIC_LSB = communication_module.inmicro1buf[13];
        //printf("sonicmsb=%d soniclsb=%d\n",SONIC_MSB,SONIC_LSB);
        SONIC = /*(SONIC_MSB<<8) |*/ SONIC_LSB;

        CAM_PWM_MSB = communication_module.inmicro1buf[14];
        CAM_PWM_LSB = communication_module.inmicro1buf[15];

        SYNCH1_IN = communication_module.inmicro1buf[16];

        CAM_PWM = CAM_PWM_MSB<<8 | CAM_PWM_LSB;
        //    printf("\nPWM=%x\n\n",CAM_PWM);
        CAM_Theta = extract_theta_from_PWM(CAM_PWM);

        Rspeed = rdir*convert_encoder_to_speed(wheel_encoderR);
        //printf("received %f speed for right wheel\n");

        kalman_module.Rmeasurement.at<float>(5) =Rspeed;
        kalman_module.Rmeasurement.at<float>(7) = convert_acceleration(accelerometerx);

        //printf("received and parsed micro1 packet:\n");
        // printf("encoderR: %d IR1=%d(cm) IR2=%d(cm) SONIC=%d(cm)",wheel_encoderR,IR1,IR2,SONIC);


        new_micro1_data =1;
    }
    else
    {
        printf("INVALID or no new micro 1 packet\n");
        new_micro1_data=0;
    }
    if (valid2!=-1)
    {
        // printf("hasn't crashed yet1\n");

        //magnetometer:  xMSB xLSB yMSB yLSB zMSB zLSB
        //wheel encoder: MSB LSB
        compass_flag = communication_module.inmicro2buf[2];

        xMSB = communication_module.inmicro2buf[3];
        xLSB = communication_module.inmicro2buf[4];
        yMSB = communication_module.inmicro2buf[5];
        yLSB = communication_module.inmicro2buf[6];
        zMSB = communication_module.inmicro2buf[7];
        zLSB = communication_module.inmicro2buf[8];
        //  printf("hasn't crashed yet 2\n");
        compassx = (xMSB<<8) | xLSB;
        compassy = (yMSB<<8) | yLSB;
        compassz = (zMSB<<8) | zLSB;

        wMSB = communication_module.inmicro2buf[9];
        wLSB = communication_module.inmicro2buf[10];
        wheel_encoderL = (wMSB<<8) | wLSB;   // ------------------------L or R?

        WHEEL_ENCODER_INDIR = communication_module.inmicro2buf[11];
       // printf("motor input direction=%x\n",WHEEL_ENCODER_INDIR);
        if ((WHEEL_ENCODER_INDIR & 0x0F)==0x01)
            rdir = 1;
        else if ((WHEEL_ENCODER_INDIR & 0x0F)==0x02)
            rdir = -1;
        else
        {
            //printf("should not be printing this now!\n");
            // let it stay what it already is
        }
        if ((WHEEL_ENCODER_INDIR >> 4) ==0x01)
            ldir = 1;
        else if ((WHEEL_ENCODER_INDIR >> 4)==0x02)
            ldir = -1;
        else
        {
            // let it stay what it already is
        }



        SYNCH2_IN =  communication_module.inmicro2buf[12];



        //  printf("hasn't crashed yet 3\n");
        //----------------------------------------------------------

//--------------------------------------------------MAY need to do a conversion on the compass data first
        //   printf("compassx=%d compassy=%d\n",compassx,compassy);
        if (compassx==0 && compassy>0)
            theta = pi/2;
        else if (compassx==0 && compassy<=0)
            theta = 3*pi/2;
        else
        {
            theta = atan((float)compassy/(float)compassx); // good for Q1 and Q4
            if (compassx < 0 && compassy > 0) // Q2
            {
                theta+=pi;
            }
            else if (compassx < 0 && compassy < 0 )
            {
                theta+=pi;
            }
        }
        theta = atan2(-compassy,-compassx);

        theta-=pi/2;
        if(theta<0) theta+=2*pi;
        if (theta>pi*2) theta-=2*pi;
        // printf("theta = %f encoderL=%d\n",theta*360/(2*pi),wheel_encoderL);
        kalman_module.Rmeasurement.at<float>(2) = theta;
        kalman_module.Rmeasurement.at<float>(3) = 0; // we are not measuring dtheta
        //printf("hasn't crashed yet5\n");

        Lspeed = ldir*convert_encoder_to_speed(wheel_encoderL); ///---------- what exactly is this? do I need to convert it to speed?
        kalman_module.Rmeasurement.at<float>(4) = Lspeed;
        //0//  kalman_module.XN = 7.0/2;
        //1//  kalman_module.YN = 7.0/2;
        //2//  kalman_module.ThetaN = .0087;
        //3//  kalman_module.dThetaN = 0;
        //4//  kalman_module.slN = .01;
        //5//  kalman_module.srN = .01;
        //6//  kalman_module.aN = .01;

        // printf("hasn't crashed yet6\n");

        new_micro2_data=1;
    }
    else
    {
        printf("INVALID or no new micro 2 packet\n");
        new_micro2_data=0;
    }

    if (GPSchars!=0)
    {


        communication_module.parser->Parse((const char*)communication_module.inGPSbuf,GPSchars);
        communication_module.info = communication_module.parser->GetActualGPSInfo();
        //printf("latitude=%f longitude=%f\n",communication_module.info.m_latitude,communication_module.info.m_longitude);
        if (communication_module.info.m_latitude !=0 && communication_module.info.m_longitude!=0 )
        {
            communication_module.latitude = communication_module.info.m_latitude;
            communication_module.longitude = communication_module.info.m_longitude;
            //printf("SUCCESSFULLY PARSED GPS DATA\n");
            Point2d GPSpt(fabs(communication_module.info.m_longitude),communication_module.info.m_latitude);
            Point2d localpt = GPS_to_local(GPSpt,local_origin);
            Point2d pix = local_to_pixel(local_origin,localpt,mapwidth,mapheight);
            //circle();
            circle(ui_module.img,pix,15,Scalar(0,0,255));
            kalman_module.Rmeasurement.at<float>(0) = localpt.x;
            kalman_module.Rmeasurement.at<float>(1) = localpt.y;
            new_gps_data=1;
            seconds_since_last_GPS=0;

        }

    }
    else
    {
        new_gps_data=0;
    }

    // printf("setting the measurement matrix type\n");

    if (new_micro1_data==0 || new_micro2_data==0)
    {
        //printf("no sensors\n");
        kalman_module.RKF.measurementMatrix = kalman_module.MeasurementMAT_nosensors;
        kalman_module.RKF.measurementNoiseCov.at<float>(0,0)=1000;//kalman_module.XN;
        kalman_module.RKF.measurementNoiseCov.at<float>(1,1)=1000;//kalman_module.YN;
        kalman_module.RKF.measurementNoiseCov.at<float>(2,2)=1000;//kalman_module.ThetaN;
        kalman_module.RKF.measurementNoiseCov.at<float>(3,3)=1000;//100;
        kalman_module.RKF.measurementNoiseCov.at<float>(4,4)=1000;//kalman_module.slN;
        kalman_module.RKF.measurementNoiseCov.at<float>(5,5)=1000;//kalman_module.srN;
        kalman_module.RKF.measurementNoiseCov.at<float>(6,6)=1000;//kalman_module.aN;
    }
    else if (new_gps_data==0)
    {
        //printf("no gps no accel\n");
        kalman_module.RKF.measurementMatrix = kalman_module.MeasurementMAT_noGPS_or_accel;
        kalman_module.RKF.measurementNoiseCov.at<float>(0,0)=1000;//kalman_module.XN;
        kalman_module.RKF.measurementNoiseCov.at<float>(1,1)=1000;//kalman_module.YN;
        kalman_module.RKF.measurementNoiseCov.at<float>(2,2)=100000;//kalman_module.ThetaN;
        kalman_module.RKF.measurementNoiseCov.at<float>(3,3)=1000;//100;
        kalman_module.RKF.measurementNoiseCov.at<float>(4,4)=kalman_module.slN;
        kalman_module.RKF.measurementNoiseCov.at<float>(5,5)=kalman_module.srN;
        kalman_module.RKF.measurementNoiseCov.at<float>(6,6)=1000;//kalman_module.aN;

    }
    else
    {
        // if (compass_flag==1)
        // {
        //printf("no accel\m");
        kalman_module.RKF.measurementMatrix = kalman_module.MeasurementMAT_noaccel;
        kalman_module.RKF.measurementNoiseCov.at<float>(0,0)=kalman_module.XN;
        kalman_module.RKF.measurementNoiseCov.at<float>(1,1)=kalman_module.YN;
        kalman_module.RKF.measurementNoiseCov.at<float>(2,2)=kalman_module.ThetaN;
        kalman_module.RKF.measurementNoiseCov.at<float>(3,3)=1000;//100;
        kalman_module.RKF.measurementNoiseCov.at<float>(4,4)=kalman_module.slN;
        kalman_module.RKF.measurementNoiseCov.at<float>(5,5)=kalman_module.srN;
        kalman_module.RKF.measurementNoiseCov.at<float>(6,6)=1000;//kalman_module.aN;
        //  }
        /* {
             printf("no compass no accel\n");
             kalman_module.RKF.measurementMatrix = kalman_module.MeasurementMAT_noaccel_or_compass;
             kalman_module.RKF.measurementNoiseCov.at<float>(0,0)=kalman_module.XN;
             kalman_module.RKF.measurementNoiseCov.at<float>(1,1)=kalman_module.YN;
             kalman_module.RKF.measurementNoiseCov.at<float>(2,2)=100000;//kalman_module.ThetaN;
             kalman_module.RKF.measurementNoiseCov.at<float>(3,3)=100000;//100;
             kalman_module.RKF.measurementNoiseCov.at<float>(4,4)=kalman_module.slN;
             kalman_module.RKF.measurementNoiseCov.at<float>(5,5)=kalman_module.srN;
             kalman_module.RKF.measurementNoiseCov.at<float>(6,6)=100000;//kalman_module.aN;
         }*/

    }





}
#endif

void Atom_board_module::wheel_control(float speedleft, float speedright)
{
  printf("speedleft speedright: %f %f\n",speedleft,speedright);
    delta_error_left = left_error - left_error_prev;
    left_error_prev = left_error;
    left_error = 0.4*left_error_prev + 255.0*(speedleft-Lspeed) - 0.2*delta_error_left;

    //printf("ON CALL\nspeedriht=%f Rspeed=%f right error=%f \n",speedright,Rspeed,right_error);
    delta_error_right = right_error - right_error_prev;
    right_error_prev = right_error;
    right_error = 0.4*right_error_prev + 255.0*(speedright-Rspeed) - 0.2*delta_error_right;
    incl += 30*(speedleft-Lspeed);
    incr += 30*(speedright-Rspeed);


    if (incr > 50) incr = 50;
    if (incl > 50) incl = 50;

    if (incr < -50) incr = -50;
    if (incl < -50) incl = -50;
    //printf("incr %d, incl %d \n", incr, incl);
    //printf("speedriht=%f Rspeed=%f right error=%f\n",speedright,Rspeed,right_error);
    //printf("**********************************");
    //printf("speedleft=%f Lspeed=%f left error=%f\n",speedleft,Lspeed,left_error);

    unsigned char DIRr,DIRl;
    if (speedright*right_error>0) // go faster
        if (speedright>0) DIRr=1;
        else DIRr=2;
    else if (speedright*right_error<0)
        DIRr = 4;
    else
        DIRr=4;

    if (speedleft*left_error>0) // go faster
        if (speedleft>0) DIRl=1;
        else
            DIRl=2;

    else if (speedleft*left_error<0)
        DIRl = 4;
    else
        DIRl=4;

    if (speedleft == 0) DIRl = 4;
    if (speedright == 0) DIRr = 4;

    navigation_module.DIR = DIRl <<4 | DIRr;


    // int tLPWM=LPWM,tRPWM=RPWM;
    if (DIRl == 0x01)
        tLPWM = (left_error) + incl;
    else if (DIRl == 0x02)
        tLPWM = -(left_error) - incl;
    //else

    if (DIRr == 0x01)
        tRPWM = (right_error) + incr;
    else if (DIRr == 0x02)
        tRPWM = -(right_error) - incr;
    //else



    navigation_module.LPWM = (unsigned char)(tLPWM);
    navigation_module.RPWM = (unsigned char)(tRPWM);



    if (speedleft != speedright)
    {
        tLPWM=205 + incl;
        tRPWM=205 + incr;
    }
    navigation_module.LPWM = tLPWM;
    navigation_module.RPWM = tRPWM;

    if (tLPWM>255) navigation_module.LPWM=255;
    if (tLPWM<0) navigation_module.LPWM=0;
    if (tRPWM>255) navigation_module.RPWM=255;
    if (tRPWM<0) navigation_module.RPWM=0;

    printf("tRPWM=%d, RPWM=%d\n", tRPWM, navigation_module.RPWM);
    printf("tLPWM=%d, LPWM=%d\n", tLPWM, navigation_module.LPWM);
}

float convert_encoder_to_speed(int wheel_encoder)   //Atom_board_module::
{
    // convert to change in value if necessary
    // convert the change in value to change in position
    // then use some kind of time measurement to turn that into speed
    // 5ms is the sample time
    // 30:1 gear reduction (encoder revoluations per wheel revolution)
    // 120 (or maybe 100) cycles per encoder revolution
    // diameter= 4.75 inches = 0.12065 meters
    // circumference = 2*pi*d = .379033 meters
    // circumference of wheel = .379033 meters per wheel revolution
    float distance = wheel_encoder/120.0/30*.379033;
    float speed = distance/0.005;
    return speed;
}
float convert_acceleration(int acceleration)
{
    // this number is an integer in which the value is encoded
    // will need to convert this to a float in meters per second squared
    return acceleration;
}

#ifdef WINDOWS
int Communication_Module::Receive_Packet(int type)
{
    unsigned char* buffer;
    unsigned char dummybuffer[10000];
    int datalen,i;
    HANDLE hSerial;
    DWORD dwBytesRead=0;
    int valid=0;

    int x=0,extra=0;
    //communication_module.outpacket[0]=0xFF;
    //  printf("in the packet recieve funtion\n");
    if (type==1)//receive from to micro1
    {
        //  printf("packet type 1\n");
        //need to send: X, Y pixel coordinates:  xMSB xLSB yMSB yLSB
        datalen = 17;
        hSerial = hSerial_Micro1;
        buffer = inmicro1buf;
        extra = atom->SYNCH1_IN;

    }
    else if (type==2)// receive from to micro2
    {
        //    printf("packet type 2\n");
        // Left PWM
        // Right PWM
        // Direction: 1 byte
        datalen=13;
        hSerial = hSerial_Micro2;
        buffer = inmicro2buf;
        extra = atom->SYNCH2_IN;
    }
    else if (type==3)// receive from GPS
    {
        //    printf("packet type 3\n");
        datalen=200;
        hSerial = hSerial_GPS;
        buffer = inGPSbuf;

    }
    else if (type==4)// should never send to Camera
    {
        printf("CAMERA doesn't use packets\n");
        return -1;
    }
    else
    {
        printf("BAD SEND PACKET TYPE\n");
        return -1;
    }

    for (int i=0; i<datalen+3; i++) buffer[i]=0;


    if (type==3)
    {
        if(!ReadFile(hSerial, buffer, datalen, &dwBytesRead, NULL))
        {
            printf("unable to read byte\n");//error occurred. Report to user.
        }
        //printf("read %d bytes from GPS\n",dwBytesRead);
        for (int i=0; i<dwBytesRead; i++) printf("%c",buffer[i]);
    }
    else
    {

        //   printf("reading bytes from one of the micros\n");
        x=0;
        int foundstart=0;
        for (i=0; i<datalen+3; i++)
        {
            //   printf("reading a single byte\n");
            if(!ReadFile(hSerial, buffer+x, 1, &dwBytesRead, NULL))
            {
                printf("unable to read byte\n");//error occurred. Report to user.
                return -1;
            }
            else
            {
                if (x==1)
                {
                    //        printf(" potential packet type: read: %x\n",*(buffer+x));
                    if (buffer[1]!=type)
                    {
                        //            printf("found start but tpye is bad, looking for new start\n");
                        x=0;
                        buffer[0]=0;
                    }
                }

            }
            if (buffer[0]==0xFF)
            {
                // if (x==0) printf("found start byte\n");
                if (x==1 && buffer[1]==type)
                {
                    foundstart=1;
                    //printf("found start byte and type byte\n");
                    if(!ReadFile(hSerial, buffer+2, datalen-1, &dwBytesRead, NULL))
                    {
                        printf("unable to read byte\n");//error occurred. Report to user.
                    }
                    //printf("read %d bytes from micro %d\n",dwBytesRead,type);
                    //for (int j=0;j<dwBytesRead+2;j++) printf("byte %d: %x\n",j,buffer[j]);
                    if (buffer[datalen]==0xFE)
                    {
                        valid=1;
                        //if (time_since_sync>.005)
                        // {
                        //printf("\n\n\n\n\n_____________________\n\n\n\n\n");
                        //ReadFile(hSerial, dummybuffer, extra*datalen, &dwBytesRead, NULL);
                        time_since_sync=0;
                        // }
                        return 1;
                    }

                    else
                        printf("invalid packet: no stop byte\n");

                }
                x=1;

            }
        }

        if (valid==0)
        {
            printf("unable to find valid packet from micro%d\b",type);
            return -1;
        }
    }

    //  printf("returning number of gps packets\n");
    return dwBytesRead;
}
#endif

#ifdef WINDOWS
void Atom_board_module::Send_Packet(int type,unsigned char* data,int len)
{
    int datalen,i;
    HANDLE hSerial;
    DWORD dwBytesRead;
    communication_module.outpacket[0]=0xFF;

    if (type==1)//send to micro1
    {
        //need to send: X, Y pixel coordinates:  xMSB xLSB yMSB yLSB
        datalen = 4;
        communication_module.outpacket[1] = 3;
        hSerial = communication_module.hSerial_Micro1;

    }
    else if (type==2)// send to micro2
    {
        // Left PWM
        // Right PWM
        // Direction: 1 byte
        datalen=3;
        communication_module.outpacket[1] = 4;
        hSerial = communication_module.hSerial_Micro2;
    }
    else if (type==3)// should never send to GPS
    {
        printf("CANT SEND TO GPS\n");
        return;
    }
    else if (type==4)// should never send to Camera
    {
        printf("CANT SEND TO CAMERA\n");
        return;
    }
    else
    {
        printf("BAD SEND PACKET TYPE\n");
        return;
    }
    if (len<datalen+3)
    {
        printf("data too small\n");
    }

    for (i=0; i<datalen; i++)
    {
        communication_module.outpacket[i+2] = data[i+2];
    }
    communication_module.outpacket[i+2]=0xFE;

    if(!WriteFile(hSerial, communication_module.outpacket, datalen+3, &dwBytesRead, NULL))
    {
        printf("unable to read byte\n");//error occurred. Report to user.
    }
    // printf("sent %d bytes\n",dwBytesRead);
}
#endif
void Atom_board_module::Initialize()
{
    prev_seconds = clock()/(double)CLOCKS_PER_SEC;
    ui_module.atom = this;
    communication_module.atom=this;
    local_origin.x = (MAPL+MAPR)/2.0;//86.91304444;
    local_origin.y = (MAPT+MAPB)/2.0;//40.42911111;
    // creation of the window
    namedWindow( "Kalman", 1 );
    namedWindow( "LkDemo", 0 );
    setMouseCallback( "Kalman", onMouse, 0 );
    #ifdef WINDOWS
    setMouseCallback( "LkDemo", camera_on_mouse, 0 );
    #endif
    #ifdef WINDOWS
    initialize_camera();
    #endif
//void camera_on_mouse( int event, int x, int y, int flags, void* param )

    //Mat img0 = imread("googleearth_campus_zoomed_in_hilltop.bmp");
    Mat img0 = imread("googleearth_campus_zoomed_in_engineering_mall.bmp");

    Size2i size = img0.size();
    size.height = 2*size.height/3;
    size.width = 2*size.width/3;
    mapwidth = size.width;
    mapheight = size.height;
    resize(img0, ui_module.img, size);
    ui_module.obstacleimg = ui_module.img.clone();
    Point2d pixel1,pixel2;
    pixel1.x=0;
    pixel1.y=0;
    pixel2.x=400;
    pixel2.y=400;
    //ui_module.obstacleimg = Scalar::all(0);
    //line( ui_module.obstacleimg, pixel1,pixel2, Scalar(255,255,255), 1, CV_AA, 0);

    navigation_module.subwaypoint=&(navigation_module.dummy);

    navigation_module.obstaclelist = Obstaclesinit(dstar);

    dstar = new Dstar();
    dstar->init(0,0,20,20);
    dstar->replan();               // plan a path
    navigation_module.mypath = dstar->getPath();     // retrieve path

    // setting up the control system
    waypointlist = NULL;//init_waypoints();
    waypoint = waypointlist;

    navigation_module.control_vec.dist_err=0;
    navigation_module.control_vec.theta_err=0;
    navigation_module.control_vec.ul = 0;
    navigation_module.control_vec.ur = 0;

    // setting simulation parameters
    kalman_module.real_dt= .001;
    kalman_module.dt = .05;
    // related to fake measurements
    fake_measurement_module.GPS_count=0;

    display_real_obstacles(navigation_module.obstaclelist,&(ui_module.img),local_origin,mapwidth,mapheight);

    kalman_module.w = .15;
    kalman_module.mr =1;
    kalman_module.ml =1;

    // intitialization
    kalman_module.x=0;
    kalman_module.y=0;
    kalman_module.theta = -pi/2;
    kalman_module.realsl=0,kalman_module.realsr=0;

    kalman_module.sl = kalman_module.realsl;
    kalman_module.sr = kalman_module.realsr;

    kalman_module.a= 0;




    kalman_module.XN = .5;
    kalman_module.YN = .5;
    kalman_module.ThetaN = 0.00087;//.0087;
    kalman_module.dThetaN = 0;
    kalman_module.slN = .01;
    kalman_module.srN = .01;
    kalman_module.aN = .01;

    ui_module.GPSavgx=0,ui_module.GPSavgy=0;
    ui_module.nGPS=0;

    // related to control output
    navigation_module.ul=0;
    navigation_module.ur=0;
    // kalman initialization

    printf("hello scott\n");

    kalman_module.RKF = kalmaninit(kalman_module.theta,kalman_module.ml,kalman_module.mr,kalman_module.dt);
    kalman_module.RealState = kalmaninit(kalman_module.theta,kalman_module.ml,kalman_module.mr,kalman_module.real_dt);

    kalman_module.RKF.measurementNoiseCov.at<float>(0,0)=kalman_module.XN;
    kalman_module.RKF.measurementNoiseCov.at<float>(1,1)=kalman_module.YN;
    kalman_module.RKF.measurementNoiseCov.at<float>(2,2)=kalman_module.ThetaN;
    kalman_module.RKF.measurementNoiseCov.at<float>(3,3)=100;
    kalman_module.RKF.measurementNoiseCov.at<float>(4,4)=kalman_module.slN;
    kalman_module.RKF.measurementNoiseCov.at<float>(5,5)=kalman_module.srN;
    kalman_module.RKF.measurementNoiseCov.at<float>(6,6)=kalman_module.aN;


    kalman_module.RKF.processNoiseCov.at<float>(4,4)=kalman_module.slN;
    kalman_module.RKF.processNoiseCov.at<float>(5,5)=kalman_module.srN;
    kalman_module.RKF.processNoiseCov.at<float>(6,6)=kalman_module.aN;


    kalman_module.RealState.measurementNoiseCov.at<float>(0,0)=kalman_module.XN;
    kalman_module.RealState.measurementNoiseCov.at<float>(1,1)=kalman_module.YN;
    kalman_module.RealState.measurementNoiseCov.at<float>(2,2)=kalman_module.ThetaN;
    kalman_module.RealState.measurementNoiseCov.at<float>(3,3)=100;
    kalman_module.RealState.measurementNoiseCov.at<float>(4,4)=kalman_module.slN;
    kalman_module.RealState.measurementNoiseCov.at<float>(5,5)=kalman_module.srN;
    kalman_module.RealState.measurementNoiseCov.at<float>(6,6)=kalman_module.aN;

    kalman_module.RealState.processNoiseCov.at<float>(4,4)=kalman_module.slN;
    kalman_module.RealState.processNoiseCov.at<float>(5,5)=kalman_module.srN;
    kalman_module.RealState.processNoiseCov.at<float>(6,6)=kalman_module.aN;

    printf("finished setting noise cov\n");


    kalman_module.MeasurementMAT_noGPS = *(Mat_<float>(8,8) <<
                                           0, 0, 0, 0, 0, 0,  0,   0,
                                           0, 0, 0, 0, 0, 0,  0,   0,
                                           0, 0, 1, 0, 0, 0,  0,   0,
                                           0, 0, 0, 0, 0, 0,  0,   0,
                                           0, 0, 0, 0, 1, 0,  0,   0,
                                           0, 0, 0, 0, 0, 1,  0,   0,
                                           0, 0, 0, 0, 0, 0,  0,   0,
                                           0, 0, 0, 0, 0, 0,  0,   0);

    kalman_module.MeasurementMAT = *(Mat_<float>(8,8) <<
                                     1, 0, 0, 0, 0, 0,  0,   0,
                                     0, 1, 0, 0, 0, 0,  0,   0,
                                     0, 0, 1, 0, 0, 0,  0,   0,
                                     0, 0, 0, 0, 0, 0,  0,   0,
                                     0, 0, 0, 0, 1, 0,  0,   0,
                                     0, 0, 0, 0, 0, 1,  0,   0,
                                     0, 0, 0, 0, 0, 0,  0,  0,
                                     0, 0, 0, 0, 0, 0,  0,   0);

    kalman_module.MeasurementMAT_noaccel = *(Mat_<float>(8,8) <<
                                           1, 0, 0, 0, 0, 0,  0,   0,
                                           0, 1, 0, 0, 0, 0,  0,   0,
                                           0, 0, 1, 0, 0, 0,  0,   0,
                                           0, 0, 0, 0, 0, 0,  0,   0,
                                           0, 0, 0, 0, 1, 0,  0,   0,
                                           0, 0, 0, 0, 0, 1,  0,   0,
                                           0, 0, 0, 0, 0, 0,  0,   0,
                                           0, 0, 0, 0, 0, 0,  0,   0);
    kalman_module.MeasurementMAT_noaccel_or_compass = *(Mat_<float>(8,8) <<
            1, 0, 0, 0, 0, 0,  0,   0,
            0, 1, 0, 0, 0, 0,  0,   0,
            0, 0, 0, 0, 0, 0,  0,   0,
            0, 0, 0, 0, 0, 0,  0,   0,
            0, 0, 0, 0, 1, 0,  0,   0,
            0, 0, 0, 0, 0, 1,  0,   0,
            0, 0, 0, 0, 0, 0,  0,   0,
            0, 0, 0, 0, 0, 0,  0,   0);


    kalman_module.MeasurementMAT_noGPS_or_accel = *(Mat_<float>(8,8) <<
            0, 0, 0, 0, 0, 0,  0,   0,
            0, 0, 0, 0, 0, 0,  0,   0,
            0, 0, 1, 0, 0, 0,  0,   0,
            0, 0, 0, 0, 0, 0,  0,   0,
            0, 0, 0, 0, 1, 0,  0,   0,
            0, 0, 0, 0, 0, 1,  0,   0,
            0, 0, 0, 0, 0, 0,  0,   0,
            0, 0, 0, 0, 0, 0,  0,   0);

    kalman_module.MeasurementMAT_nosensors = *(Mat_<float>(8,8) <<
            0, 0, 0, 0, 0, 0,  0,   0,
            0, 0, 0, 0, 0, 0,  0,   0,
            0, 0, 0, 0, 0, 0,  0,   0,
            0, 0, 0, 0, 0, 0,  0,   0,
            0, 0, 0, 0, 0, 0,  0,   0,
            0, 0, 0, 0, 0, 0,  0,   0,
            0, 0, 0, 0, 0, 0,  0,   0,
            0, 0, 0, 0, 0, 0,  0,   0);


    kalman_module.Rmeasurement = Mat::zeros(8,1,CV_32F);



    // Navigation
    if (waypoint!=NULL)
        dstar->updateGoal(int_round(waypoint->x*4.0),int_round(waypoint->y*4.0));
    if(dstar->replan())
    {
        //display_path(navigation_module.mypath,&(ui_module.img),0,local_origin,mapwidth,mapheight);
        navigation_module.mypath = dstar->getPath();
        //display_path(navigation_module.mypath,&(ui_module.img),255,local_origin,mapwidth,mapheight);
    }

    ui_module.pixpoint = GPS_to_pixel(local_origin,mapwidth,mapheight);
//    drawCross( ui_module.pixpoint, Scalar(0,0,255), 10 ); //---------------------need to make a UI_module display function

    communication_module.parser = new NMEAParser();
    #ifdef WINDOWS
    dev1_open=communication_module.Initialize_Com(3,1);
    dev2_open=communication_module.Initialize_Com(5,2);
    dev3_open=communication_module.Initialize_Com(4,3);
    #endif
    // communication_module.Initialize_Com(5,4);



    new_micro1_data = 0;
    new_micro2_data = 0;
    new_gps_data = 0;
    seconds_since_last_GPS=0;

    communication_module.time_since_sync=0;

    navigation_module.atom = this;


    #ifdef WINDOWS
    Get_Sensor_Data();
    #endif
    kalman_module.x = kalman_module.Rmeasurement.at<float>(0);
    kalman_module.y = kalman_module.Rmeasurement.at<float>(1);

    kalman_module.RKF.statePost = *(Mat_<float>(8,1) << kalman_module.x, kalman_module.y, kalman_module.theta, 0, kalman_module.sl, kalman_module.sr, kalman_module.a,kalman_module.a);
    // kalman_module.RealState.statePost = *(Mat_<float>(8,1) << kalman_module.x, kalman_module.y, kalman_module.theta, 0, kalman_module.sl, kalman_module.sr, kalman_module.a,kalman_module.a);

    kalman_module.RKF.errorCovPre.at<float>(1,1)=200;
    kalman_module.RKF.errorCovPre.at<float>(2,2)=200;
    kalman_module.RKF.errorCovPre.at<float>(3,3)=200;
    kalman_module.RKF.errorCovPre.at<float>(4,4)=200;
    kalman_module.RKF.errorCovPre.at<float>(5,5)=200;
    kalman_module.RKF.errorCovPre.at<float>(6,6)=200;
    kalman_module.RKF.errorCovPre.at<float>(7,7)=200;
    kalman_module.RKF.errorCovPre.at<float>(8,8)=200;

    kalman_module.RKF.errorCovPost.at<float>(1,1)=200;
    kalman_module.RKF.errorCovPost.at<float>(2,2)=200;
    kalman_module.RKF.errorCovPost.at<float>(3,3)=200;
    kalman_module.RKF.errorCovPost.at<float>(4,4)=200;
    kalman_module.RKF.errorCovPost.at<float>(5,5)=200;
    kalman_module.RKF.errorCovPost.at<float>(6,6)=200;
    kalman_module.RKF.errorCovPost.at<float>(7,7)=200;
    kalman_module.RKF.errorCovPost.at<float>(8,8)=200;

    left_error=0;
    right_error=0;
    left_error_prev=0;
    right_error_prev=0;

    tLPWM=0;
    tRPWM=0;
    incr = 0;
    incl = 0;
    scan=0;

}

#ifdef WINDOWS
int Communication_Module::Initialize_Com(int ComNum, int type)
{
    HANDLE hSerial;
    DCB dcbSerialParams = {0};
    DCB dcbSerial;
    DWORD dwBytesRead = 0;

    char comstr[5]="COM1";
    comstr[3] = ComNum+48;


    hSerial = CreateFile(comstr,GENERIC_READ | GENERIC_WRITE,0,	0,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,0);
    if(hSerial==INVALID_HANDLE_VALUE)
    {
        if(GetLastError()==ERROR_FILE_NOT_FOUND)
        {
            printf("failed to open serial port %d\n",ComNum);
            return -1;
            //serial port does not exist. Inform user.
        }
        //some other error occurred. Inform user.
    }

    dcbSerial.DCBlength=sizeof(dcbSerialParams);
    if (!GetCommState(hSerial, &dcbSerialParams))
    {
        printf("error getting state\n");
        return -1;
        //error getting state
    }
    if (type==3) dcbSerialParams.BaudRate=CBR_4800;
    else dcbSerialParams.BaudRate=CBR_38400; //GPS is 4800

    dcbSerialParams.ByteSize=8;
    dcbSerialParams.StopBits=ONESTOPBIT;
    dcbSerialParams.Parity=NOPARITY;
    if(!SetCommState(hSerial, &dcbSerialParams))
    {

        printf("error setting serial port state\n");
        return -1;
    }


    COMMTIMEOUTS timeouts= {0};
    timeouts.ReadIntervalTimeout=10;
    timeouts.ReadTotalTimeoutConstant=10;
    timeouts.ReadTotalTimeoutMultiplier=1;
    timeouts.WriteTotalTimeoutConstant=10;
    timeouts.WriteTotalTimeoutMultiplier=0;
    if(!SetCommTimeouts(hSerial, &timeouts))
//error occureed. Inform user
    {
        printf("unable to set timeout\n");
        return -1;
    }

    if (type==1)
    {
        cam_hSerial = hSerial;
        hSerial_Micro1 = hSerial;
    }
    else if (type==2)
    {
        hSerial_Micro2 = hSerial;
    }
    else if (type==3)
    {
        hSerial_GPS = hSerial;
    }
    else if (type==4)
    {
        hSerial_CAM = hSerial;
    }
    else
    {
        return -2;
    }
    printf("returning 1 in com_initialize function\n");
    return 1;

}
#endif





int main(int, char**)
{

    double avgtime=0;
    double iterations=0;
    double total_time=0;
    char LPWM=0xFF,RPWM=0xFF,DIR=0x11;
    clock_t start_time;
    class Atom_board_module Atom = Atom_board_module();
    Atom.Initialize();
    imshow("Kalman",Atom.ui_module.img);
    start_time=clock();
    Atom.SYNCH1_IN=0;
    Atom.SYNCH2_IN=0;
   /* while(waypoint==NULL)
    {
        Sleep(10);
        waitKey(1);
    }*/
    while(1)
    {
      Atom.Camera_Tracking = 0;
#ifdef WINDOWS
      Atom.Camera_Tracking = camera_track(Atom.scan);
#endif
        iterations= iterations+1;
        //printf("\n\n-------------\n\n");
        //Atom.SYNCH1_IN=255;
        waitKey(6);
	#ifdef WINDOWS
        Atom.Get_Sensor_Data();
	#endif
	Atom.Get_Fake_Sensor_Data();
        printf("Measurements: Theta = %f(degrees) Lspeed = %f(m/s) Rspeed = %f (m/s)\n",Atom.kalman_module.Rmeasurement.at<float>(2)*360/(2*pi),Atom.kalman_module.Rmeasurement.at<float>(4),Atom.kalman_module.Rmeasurement.at<float>(5));
        //printf("-------SYNCH1=%d  SYNCH2=%d-------",Atom.SYNCH1_IN,Atom.SYNCH2_IN);
        //--------- Timing stuff------//
        Atom.seconds = clock()/(double)CLOCKS_PER_SEC;//-Atom.start_time;
        Atom.dt = Atom.seconds - Atom.prev_seconds;

        Atom.seconds_since_last_GPS+=Atom.dt;
        Atom.communication_module.time_since_sync+=Atom.dt;
        Atom.prev_seconds = Atom.seconds;
        total_time= total_time+Atom.dt;
        avgtime = total_time/iterations;
        //printf("steps_per_sec=%f average fps=%lf \n",1/Atom.dt,1.0/avgtime);

        Atom.kalman_module.dt = Atom.dt;

        //--------------------------------



        /*   if (Atom.IR2<45)
           {
              LPWM=0xFF;
              RPWM=0xFF;
              DIR=0x44;
              printf("stop too close ir2=%d\n",Atom.IR2);
           }
           else if (Atom.IR1>43 )
           {
               LPWM=0xFF;
               RPWM=0xFF;
               DIR=0x44;
               printf("stop drop ir1=%d\n",Atom.IR1);
           }
           else if (Atom.IR1<30)
           {
               LPWM=0xFF;
               RPWM=0xFF;
               DIR=0x44;
               printf("stop bump ir1=%d\n",Atom.IR1);
           }
           else
           {*/
        //    LPWM=0x40;
        //    RPWM=0x40;
        //    DIR=0x11;
        //   printf("Go!\n");
        // }


        //----temporary test code--------


        //-----------------------------------

          // Atom.Get_Fake_Sensor_Data();
          //Atom.Get_Fake_Packets();
         if(Atom.SONIC<120)
         {


          Atom.navigation_module.find_obstacle_location();
           Atom.navigation_module.clear_line_of_sight();
           Atom.navigation_module.add_obstacle();
          }
          else
          {
              //Atom.SONIC=120;
             Atom.navigation_module.find_obstacle_location();
             Atom.navigation_module.clear_line_of_sight();
          }
        // printf("Sonic reads %d(cm)\n",Atom.SONIC);
        //printf("1\n");
        Atom.navigation_module.Navigate();
        //printf("2\n");

        //Atom.navigation_module.control_vec.ul=1;//LPWM/256.0;
        // Atom.navigation_module.control_vec.ur=1;//RPWM/256.0;

        /*Atom.kalman_module.Rmeasurement.at<float>(0) = 0;
        Atom.kalman_module.Rmeasurement.at<float>(1) = 0;
        Atom.kalman_module.Rmeasurement.at<float>(2) = (pi/2);
        Atom.kalman_module.Rmeasurement.at<float>(3) = 0;
        Atom.kalman_module.Rmeasurement.at<float>(4) = .7;
        Atom.kalman_module.Rmeasurement.at<float>(5) = .7;
        Atom.kalman_module.Rmeasurement.at<float>(6) = 0;
        Atom.kalman_module.Rmeasurement.at<float>(7) = 0;*/
        //printf("3\n");
        Atom.kalman_module.KalmanUpdate();
        //printf("4\n");
        float x,y,theta,dtheta,sl,sr;
        x = Atom.kalman_module.RKF.statePost.at<float>(0);
        y = Atom.kalman_module.RKF.statePost.at<float>(1);
        theta = Atom.kalman_module.RKF.statePost.at<float>(2);
        dtheta = Atom.kalman_module.RKF.statePost.at<float>(3);
        sl = Atom.kalman_module.RKF.statePost.at<float>(4);
        sr = Atom.kalman_module.RKF.statePost.at<float>(5);
        //printf("Estimated state: x=%f y=%f theta=%f, dtheta=%f sl=%f, sr=%f\n",x,y,theta*360/2/pi,dtheta*360/2/pi,sl,sr);

        //printf("5\n");
        Atom.ui_module.Display();
       // printf("6\n");
        //Sleep(1000);
        waitKey(1);
    }
    /*  //used for displaying the error circle
          float xzerr,yzerr;
      //possibly unneccessary
          Point2d localpoint;
      // a point in front of MSEE, this is a global variable
          local_origin.x = (MAPL+MAPR)/2.0;//86.91304444;
          local_origin.y = (MAPT+MAPB)/2.0;//40.42911111;

      // creation of the window
          namedWindow( "Kalman", 1 );
          setMouseCallback( "Kalman", onMouse, 0 );

     // Mat img0 = imread("googleearth_campus_zoomed_out.bmp");
     // Mat img0 = imread("googleearth_campus_zoomed_in_engineering_mall.bmp");
      // setting the background
          Mat img0 = imread("googleearth_campus_zoomed_in_hilltop.bmp");
          Size2i size = img0.size();
          // printf("img has %d rows, %d cols\n",size.width,size.height);
          size.height = 2*size.height/3;
          size.width = 2*size.width/3;
          // printf("img has %d rows, %d cols\n",size.width,size.height);
          Mat img;

          mapwidth = size.width;
          mapheight = size.height;

          resize(img0, img, size);//, double fx=0, double fy=0, int interpolation=INTER_LINEAR)
          //img = Scalar::all(0);
      // setting up the obstacles
          Obstacle* obstaclelist = Obstaclesinit(dstar);
          // display_real_obstacles(obstaclelist,&img);
          Detection_line* detection_lines;
          Known_Obstacle* knownlist;
      // setting up the pathfinder
          dstar = new Dstar();
          dstar->init(0,0,20,20);
          list<state> mypath;
          dstar->replan();               // plan a path
          mypath = dstar->getPath();     // retrieve path

      // setting up the control system
          Control_Vector control_vec;
          waypointlist = NULL;//init_waypoints();
          waypoint = waypointlist;
          Waypoint* subwaypoint;
          Waypoint dummy;
          subwaypoint=&dummy;

          control_vec.dist_err=0;
          control_vec.theta_err=0;
          control_vec.ul = 0;
          control_vec.ur = 0;

      // some kkind of error check
          if (waypoint!=NULL)
              if (waypoint->next==NULL)
              {
                  printf("FAIL!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
              }
      // setting simulation parameters
          float real_dt= .001;
          float dt = .05;
      // related to fake measurements
          int GPS_count=0;
      // related to UI
          display_real_obstacles(obstaclelist,&img,local_origin,mapwidth,mapheight);
          // display_path(mypath,&img);
      // Kalman filter
          Mat control;
          Mat Rmeasurement;
          Mat Rprediction;
          Mat Rcorrection;

          Mat Realprediction;
          Mat Realcontrol;

          // constants
          float w = .15;
          float mr =1;
          float ml =1;

          // intitialization
          float x=0;
          float y=0;
          float theta = -pi/2;
          float realsl=0,realsr=0;

          float sl = realsl;
          float sr = realsr;

          float a= 0;

          float XN = 7.0/2;
          float YN = 7.0/2;
          float ThetaN = .0087;
          float dThetaN = 0;
          float slN = .01;
          float srN = .01;
          float aN = .01;

      // relate to UI
          float GPSavgx=0,GPSavgy=0;
          float nGPS=0;
          //float t=0;

      // related to control output
          float ul=0;
          float ur=0;
      // kalman initialization
          KalmanFilter RKF = kalmaninit(theta,ml,mr,dt);
          KalmanFilter RealState = kalmaninit(theta,ml,mr,real_dt);

          RKF.measurementNoiseCov.at<float>(0,0)=XN;
          RKF.measurementNoiseCov.at<float>(1,1)=YN;
          RKF.measurementNoiseCov.at<float>(2,2)=ThetaN;
          RKF.measurementNoiseCov.at<float>(3,3)=100;
          RKF.measurementNoiseCov.at<float>(4,4)=slN;
          RKF.measurementNoiseCov.at<float>(5,5)=srN;
          RKF.measurementNoiseCov.at<float>(6,6)=aN;

          RKF.processNoiseCov.at<float>(4,4)=slN;
          RKF.processNoiseCov.at<float>(5,5)=srN;
          RKF.processNoiseCov.at<float>(6,6)=aN;

          Mat MeasurementMAT_noGPS = *(Mat_<float>(8,8) <<
                                   0, 0, 0, 0, 0, 0,  0,   0,
                                   0, 0, 0, 0, 0, 0,  0,   0,
                                   0, 0, 1, 0, 0, 0,  0,   0,
                                   0, 0, 0, 0, 0, 0,  0,   0,
                                   0, 0, 0, 0, 1, 0,  0,   0,
                                   0, 0, 0, 0, 0, 1,  0,   0,
                                   0, 0, 0, 0, 0, 0, .5,  .5,
                                   0, 0, 0, 0, 0, 0,  0,   0);

          Mat MeasurementMAT = *(Mat_<float>(8,8) <<
                             1, 0, 0, 0, 0, 0,  0,   0,
                             0, 1, 0, 0, 0, 0,  0,   0,
                             0, 0, 1, 0, 0, 0,  0,   0,
                             0, 0, 0, 0, 0, 0,  0,   0,
                             0, 0, 0, 0, 1, 0,  0,   0,
                             0, 0, 0, 0, 0, 1,  0,   0,
                             0, 0, 0, 0, 0, 0, .5,  .5,
                             0, 0, 0, 0, 0, 0,  0,   0);


          RKF.statePost = *(Mat_<float>(8,1) << x, y, theta, 0, sl, sr, a,a);
          RealState.statePost = *(Mat_<float>(8,1) << x, y, theta, 0, sl, sr, a,a);

      // Navigation
          if (waypoint!=NULL)
          dstar->updateGoal(waypoint->x,waypoint->y);
              if(dstar->replan())
              {
                  display_path(mypath,&img,0,local_origin,mapwidth,mapheight);
                  mypath = dstar->getPath();
                  display_path(mypath,&img,255,local_origin,mapwidth,mapheight);
              }

      // related to UI and GPS, possibly unneccessary
          Point2d coord;
          coord.x = 86.912622;
          coord.y = 40.428738;
          Point2d pixcoord;
          pixcoord = GPS_to_pixel(coord,mapwidth,mapheight);
          Point pixpoint;
          pixpoint.x = pixcoord.x;
          pixpoint.y = pixcoord.y;

          imshow( "Kalman", img );

      pixpoint = GPS_to_pixel(local_origin,mapwidth,mapheight);
      drawCross( pixpoint, Scalar(0,0,255), 10 );
      localpoint = GPS_to_local(coord,local_origin);

      float latitude,longitude; // in degrees
      NMEAParser *parser = new NMEAParser();
      GPSInfo info;
      char *bytes = (char*)malloc(sizeof(char)*1000);

    ////-----------------------------------------------------------------------------------
      HANDLE hSerial;
    DCB dcbSerialParams = {0};
    DCB dcbSerial;
    DWORD dwBytesRead = 0;

    hSerial = CreateFile("COM5",GENERIC_READ | GENERIC_WRITE,0,	0,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,0);
    if(hSerial==INVALID_HANDLE_VALUE)
    {
    	if(GetLastError()==ERROR_FILE_NOT_FOUND)
    	{
    		printf("failed to open serial port\n");
    	//serial port does not exist. Inform user.
    	}
    //some other error occurred. Inform user.
    }

    dcbSerial.DCBlength=sizeof(dcbSerialParams);
    if (!GetCommState(hSerial, &dcbSerialParams))
    {
    	printf("error getting state\n");
    	//error getting state
    }
    dcbSerialParams.BaudRate=CBR_9600; //GPS is 4800
    dcbSerialParams.ByteSize=8;
    dcbSerialParams.StopBits=ONESTOPBIT;
    dcbSerialParams.Parity=NOPARITY;
    if(!SetCommState(hSerial, &dcbSerialParams))
    {

    	printf("error setting serial port state\n");
    }


    COMMTIMEOUTS timeouts={0};
    timeouts.ReadIntervalTimeout=50;
    timeouts.ReadTotalTimeoutConstant=50;
    timeouts.ReadTotalTimeoutMultiplier=10;
    timeouts.WriteTotalTimeoutConstant=50;
    timeouts.WriteTotalTimeoutMultiplier=10;
    if(!SetCommTimeouts(hSerial, &timeouts))
    //error occureed. Inform user
    {
      printf("unable to set timeout\n");
    }

      int i=0;
      Point2d GPSavg(0,0);
      int num=0;


      while(waypoint==NULL)
      {
          Sleep(10);
          waitKey(1);
      }
      while(1) //for (t=0; t<5000; t+=dt)
      {
          GPS_count++;

          Rmeasurement = generate_noisy_signals(RealState.statePre, XN,YN, ThetaN, dThetaN, slN, srN, aN);
          detection_lines = create_detection_lines(RealState.statePost);
          //display_detection_lines(detection_lines,&img,1);
          knownlist = detect_obstacles(obstaclelist, RealState.statePost,dstar);
          display_known_obstacles(knownlist,&img,local_origin,mapwidth,mapheight);

          float x,y;
          x = RKF.statePost.at<float>(0);
          y = RKF.statePost.at<float>(1);

          float distance = sqrt((waypoint->x-x)*(waypoint->x-x) + (waypoint->y-y)*(waypoint->y-y));
        //  printf("distance to waypoint: %f\n",distance);

          if ( distance < 1 && waypoint->next!=NULL)
          {
              waypoint=waypoint->next;
              dstar->updateGoal((int)waypoint->x, (int)waypoint->y);
              if(dstar->replan())
              {
                  display_path(mypath,&img,0,local_origin,mapwidth,mapheight);
                  mypath = dstar->getPath();
                  display_path(mypath,&img,255,local_origin,mapwidth,mapheight);
              }
              printf("\n\nmade it to WAYPOINT\n\n");
          }


              if (sqrt((x-mypath.front().x)*(x-mypath.front().x)+(y-mypath.front().y)*(y-mypath.front().y))<3)
              {

                  mypath.pop_front();
                  if (!mypath.empty())
                  {


                  subwaypoint->x=mypath.front().x;
                  subwaypoint->y=mypath.front().y;
                  }
                  else
                  {
                      subwaypoint->x=waypoint->x;
                      subwaypoint->y=waypoint->y;
                    //  printf("getting closer: (%f,%f)\n",x,y);
                  }
                 // printf("moving to next sub-waypoint: (%f,%f)\n",subwaypoint->x,subwaypoint->y);
              }



          control_vec = set_control(control_vec, RKF.statePost, subwaypoint,w);
          ul = control_vec.ul;
          ur = control_vec.ur;




          control =   *(Mat_<float>(8,1) << 0, 0, 0, atan((sr-sl)/w),0,0,control_vec.ul,control_vec.ur);







          if (GPS_count==20)
          {
              GPS_count=0;
              RKF.measurementMatrix = MeasurementMAT;//MeasurementMAT_noGPS;//
              dstar->updateStart(int_round(x), int_round(y));
              if(dstar->replan())
              {
                  display_path(mypath,&img,0,local_origin,mapwidth,mapheight);
                  mypath = dstar->getPath();
                  display_path(mypath,&img,255,local_origin,mapwidth,mapheight);
              }
              imshow( "Kalman", img );
              Sleep((int)5*dt);
              waitKey(1);

          }
          else
          {
              RKF.measurementMatrix = MeasurementMAT_noGPS;
              Rmeasurement.at<float>(0) = 0;
              Rmeasurement.at<float>(1) = 0;
              //imshow( "Kalman", img );
              //Sleep((int)5*dt);
             // waitKey(1);
          }


          GPSavgx = (GPSavgx*nGPS + Rmeasurement.at<float>(0))/(nGPS+1);
          GPSavgy = (GPSavgy*nGPS + Rmeasurement.at<float>(1))/(nGPS+1);
          nGPS++;

          for (int i=0; i<50; i++) RealState = updateRealstate(RealState,real_dt, control_vec.ul, control_vec.ur, w);
          Rprediction = RKF.predict(control);
          Rcorrection = RKF.correct(Rmeasurement);




          RKF.transitionMatrix.at<float>(0,4) = .5*cos( Rcorrection.at<float>(2))*dt;
          RKF.transitionMatrix.at<float>(0,5) = .5*cos( Rcorrection.at<float>(2))*dt;

          RKF.transitionMatrix.at<float>(1,4) = .5*sin( Rcorrection.at<float>(2))*dt;
          RKF.transitionMatrix.at<float>(1,5) = .5*sin( Rcorrection.at<float>(2))*dt;


          sl = Rcorrection.at<float>(4);
          sr = Rcorrection.at<float>(5);


         // printf("\ntime %f estimated speed %f real speed %f\n",t,(sl+sr)/2,(RealState.statePost.at<float>(4)+RealState.statePost.at<float>(5))/2);

         // printf("waypoint: x=%f y=%f distance=%f, ul=%f, ur=%f next=%p\n",waypoint->x,waypoint->y,distance,ul,ur,waypoint->next);

          // Point2f center(img.cols*0.5f, img.rows*0.5f);



          Point2d statePt(Rcorrection.at<float>(0),Rcorrection.at<float>(1));
          Point2d pixstatePt = local_to_pixel(statePt,local_origin,mapwidth,mapheight);

          Point2d realPt(RealState.statePre.at<float>(0),RealState.statePre.at<float>(1));
          Point2d pixrealPt = local_to_pixel(realPt,local_origin,mapwidth,mapheight);

          Point2d measurePt(Rmeasurement.at<float>(0),Rmeasurement.at<float>(1));
          Point2d pixmeasurePt = local_to_pixel(measurePt,local_origin,mapwidth,mapheight);
          //statePt= statePt+center;
          //img = Scalar::all(0);
          drawCross( pixstatePt, Scalar(255,0,0), .25 );
          drawCross( pixrealPt, Scalar(255,255,255), .25 );
          drawCross( pixmeasurePt, Scalar(0,0,255), .25);

         //printf("error matrix[0,0]=%f, [1,1]=%f\n",RKF.errorCovPost.at<float>(0,0),RKF.errorCovPost.at<float>(1,1));
          xzerr = RKF.errorCovPost.at<float>(0,0);
          yzerr = RKF.errorCovPost.at<float>(0,0);

          float rerr = sqrt(xzerr*xzerr+yzerr*yzerr);

         circle(img,pixstatePt,rerr,Scalar(0,0,0));
          //drawCross( GPSavgPt, Scalar(0,255,0), 0);

         // imshow( "Kalman", img );
        //  Sleep((int)5*dt);
         // waitKey(1);
          //printf("\ntime1 %f\n",t);

         // printf("\ntime2 %f\n",t);

          //display_detection_lines(detection_lines,&img,0);




      }*/


    return 0;
}

KalmanFilter kalmaninit(float theta,float ml, float mr, float dt)
{


    KalmanFilter KF(8, 8, 8); // 8 state variables,7 measurements, 8 inputs

    //A
    KF.transitionMatrix = *(Mat_<float>(8,8) <<
                            1, 0, 0,                0, .5*cos(theta)*dt, .5*cos(theta)*dt,    0, 0,
                            0, 1, 0,                0, .5*sin(theta)*dt, .5*sin(theta)*dt,    0, 0,
                            0, 0, 1,               dt,                0,                0,    0, 0,
                            0, 0, 0,                0,                0,                0,    0, 0,
                            0, 0, 0,                0,                1,                0,   dt, 0,
                            0, 0, 0,                0,                0,                1,    0, dt,
                            0, 0, 0,                0,              -ml,                0,    0, 0,
                            0, 0, 0,                0,                0,              -mr,    0, 0);



    //B
    KF.controlMatrix = *(Mat_<float>(8,8) <<
                         0, 0, 0, 0,  0,  0,    0, 0,
                         0, 0, 0, 0,  0,  0,    0, 0,
                         0, 0, 0, 0,  0,  0,    0, 0,
                         0, 0, 0, 1,  0,  0,    0, 0,
                         0, 0, 0, 0,  0,  0,    0, 0,
                         0, 0, 0, 0,  0,  0,    0, 0,
                         0, 0, 0, 0,  0,  0,    1, 0,
                         0, 0, 0, 0,  0,  0,    0, 1);

    //H
    KF.measurementMatrix = *(Mat_<float>(8,8) <<
                             1, 0, 0, 0, 0, 0,  0,   0,
                             0, 1, 0, 0, 0, 0,  0,   0,
                             0, 0, 1, 0, 0, 0,  0,   0,
                             0, 0, 0, 0, 0, 0,  0,   0,
                             0, 0, 0, 0, 1, 0,  0,   0,
                             0, 0, 0, 0, 0, 1,  0,   0,
                             0, 0, 0, 0, 0, 0,  0,   0,
                             0, 0, 0, 0, 0, 0,  0,   0);

    //setIdentity(KF.measurementMatrix);
    setIdentity(KF.processNoiseCov, Scalar::all(1e-4));
    
    //    setIdentity(KF.measurementNoiseCov, Scalar::all(7));
    KF.measurementNoiseCov = *(Mat_<float>(8,8) <<
                             7, 0, 0, 0, 0, 0,  0,   0,
                             0, 7, 0, 0, 0, 0,  0,   0,
                             0, 0, .01, 0, 0, 0,  0,   0,
                             0, 0, 0, 1, 0, 0,  0,   0,
                             0, 0, 0, 0, .001, 0,  0,   0,
                             0, 0, 0, 0, 0, .001,  0,   0,
                             0, 0, 0, 0, 0, 0,  1,   0,
                             0, 0, 0, 0, 0, 0,  0,   1);

    setIdentity(KF.errorCovPost, Scalar::all(1e-3));
    printf("finished kalmaninit\n");


    return KF;
}

Mat generate_noisy_signals(Mat state, float XN,float YN, float ThetaN, float dThetaN, float slN, float srN, float aN)
{
    Mat Xm,Ym,Thetam,dThetam,slm,srm,am;
    Mat Measurements = Mat::zeros(8,1,CV_32F);


    Xm = Mat::zeros(1, 1, CV_32F);
    Ym = Mat::zeros(1, 1, CV_32F);
    Thetam = Mat::zeros(1, 1, CV_32F);
    dThetam = Mat::zeros(1, 1, CV_32F);
    slm = Mat::zeros(1, 1, CV_32F);
    srm = Mat::zeros(1, 1, CV_32F);
    am = Mat::zeros(1,1, CV_32F);

    for (int i=0; i<19; i++) randn(Ym,0,0);

    //printf("RealState: %f %f %f",state.at<float>(0),state.at<float>(1),state.at<float>(2));
    printf("XN YN: %f %f\n",XN, YN);

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
    Measurements.at<float>(3)=0;//dThetam.at<float>(0);
    Measurements.at<float>(4)=slm.at<float>(0);
    Measurements.at<float>(5)=srm.at<float>(0);
    Measurements.at<float>(6)=am.at<float>(0);
    Measurements.at<float>(7)=0;

    /* printf("real x: %f measured %f\n real y: %f measured %f\n real Theta %f measured %f\n real dTheta %f measured %f\n real sl %f measured %f\n real sr %f measured %f\n real accel %f measured %f\n",
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
            Measurements.at<float>(6));*/



    return Measurements;

}

KalmanFilter updateRealstate(KalmanFilter RealState, float dt, float ul, float ur,float w)
{
    //printf("realstate1\n");
    float realsr, realsl;

    realsl = RealState.statePost.at<float>(4);
    realsr = RealState.statePost.at<float>(5);

    //printf("realstate2\n");
    Mat Realcontrol = *(Mat_<float>(8,1) << 0, 0, 0, atan((realsr-realsl)/w),0,0,ul,ur);
    RealState.predict(Realcontrol);
    RealState.statePost = RealState.statePre;

    // printf("realstate3\n");

    RealState.transitionMatrix.at<float>(0,4) = .5*cos( RealState.statePre.at<float>(2))*dt;
    RealState.transitionMatrix.at<float>(0,5) = .5*cos( RealState.statePre.at<float>(2))*dt;

    RealState.transitionMatrix.at<float>(1,4) = .5*sin( RealState.statePre.at<float>(2))*dt;
    RealState.transitionMatrix.at<float>(1,5) = .5*sin( RealState.statePre.at<float>(2))*dt;
    // printf("realstate4\n");
    return RealState;
}


float set_control(Control_Vector lastcontrol, Mat State, Waypoint* nextwaypoint,float w)
{

    float ur;
    float ul;
    float theta_err;
    float dist_err;
    float x,y,rx,ry,lx,ly;
    float dtheta,theta,sl,sr,s;
    float delta_angle, perfect_angle;
    float distance,control_ratio;

    x = State.at<float>(0);
    y = State.at<float>(1);
    theta = State.at<float>(2);
    dtheta = State.at<float>(3);
    sl = State.at<float>(4);
    sr = State.at<float>(5);
    s = (sl+sr)/2;
    while (theta > 2*pi) theta-=2*pi;
    while (theta < 0) theta += 2*pi;

    theta_err = .2*lastcontrol.theta_err;
    dist_err = .2*lastcontrol.dist_err;


    rx = x + w/2*cos(theta-pi/2);
    ry = y + w/2*sin(theta-pi/2);

    lx = x + w/2*cos(theta+pi/2);
    ly = y + w/x*sin(theta+pi/2);

    perfect_angle = atan((nextwaypoint->y-y)/(nextwaypoint->x-x));
    if (nextwaypoint->x-x < 0)
    {
        perfect_angle = perfect_angle+pi;
    }
    if (perfect_angle<0)
    {
        perfect_angle+=2*pi;
    }
    if (theta < 0)
    {
        theta+=2*pi;
    }
    if (theta > 2*pi)
    {
        theta-=2*pi;
    }
    if ((perfect_angle<(pi/2)) && theta>(3*pi/2) ) //Q1-Q4
    {
        theta-=2*pi;
    }
    if (perfect_angle>(3*pi/2) && theta<(pi/2) )
    {
        theta+=2*pi;
    }

    delta_angle = (perfect_angle-theta)/(2*pi);
    if (delta_angle>.5)
    {
        delta_angle= -(delta_angle-.5);
    }
    if (delta_angle<-.5)
    {
        delta_angle= -(delta_angle+.5);
    }

    return delta_angle*360;

    //printf("theta = %f, perfecttheta=%f, delta angle=%f\n",theta*360/(2*pi),perfect_angle*360/(2*pi) ,delta_angle*360);
    //printf("dx=%f dy=%f\n",(nextwaypoint->y-y),(nextwaypoint->x-x));
    /*if (fabs(delta_angle)>.20 )
    {
        //printf("\ndist_err=%f control_ratio=%f theta error = %f\n",dist_err,control_ratio,delta_angle);

        if ((sl + sr)/2 > .02)
        {
            ul=-.50;
            ur=-.50;
        }
        if ((sl + sr)/2 < -.02)
        {
            ul=.50;
            ur=.50;
        }

        else
        {
            if (delta_angle>0)
            {
                ul=-.3;
                ur=.3;
            }
            else
            {
                ul=.3;
                ur=-.3;
            }
        }

    }
    else
    {


        distance = sqrt((nextwaypoint->x-x)*(nextwaypoint->x-x) + (nextwaypoint->y-y)*(nextwaypoint->y-y) );
        if (distance>5)
        {
            distance=5;
        }

        // if (delta_angle<pi)
        // {
        theta_err =  .1*theta_err +4.5*delta_angle - .35*dtheta;
        // }
        // else
        // {
        //     theta_err =  -.3*theta_err -.8*delta_angle + .15*dtheta;
        // }

        dist_err =   .35*distance - .1*s/distance;
        if (dist_err<0) dist_err=0;

        //printf("perfect theta is %f theta is %f theta_err is %f\n",perfect_angle,theta,delta_angle);
        ul = 1-theta_err;
        ur = 1+theta_err;

        if (ul<0) ul=0.001;
        if (ur<0) ur=0.001;

        control_ratio = fabs(ul/ur);
        //  if (control_ratio > 1.5) control_ratio=1.5;
        if (dist_err > 1)
        {
            dist_err = 1;
        }
        else if (dist_err<0)
        {
            dist_err=0;
        }

        // printf("\ndist_err=%f control_ratio=%f theta error = %f\n",dist_err,control_ratio,delta_angle);

        if (control_ratio > 1) //turning more right
        {
            ul = dist_err;
            ur = dist_err/control_ratio;
        }
        else
        {
            ul=dist_err*control_ratio;
            ur = dist_err;
        }

    }

    // ul = (ul -.5)*2;
    // ur = (ur -.5)*2;


    lastcontrol.dist_err = dist_err;
    lastcontrol.theta_err = theta_err;
    lastcontrol.ul = ul;
    lastcontrol.ur = ur;

    return lastcontrol;*/
}

Waypoint* init_waypoints()
{
    Waypoint* head = (Waypoint*)malloc(sizeof(Waypoint));
    Waypoint* current;
    head->head = head;
    head->prev=NULL;
    head->x=10;
    head->y=10;
    head->next = (Waypoint*)malloc(sizeof(Waypoint));

    if (head->next==NULL)
    {
        printf("FAIL!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
    }

    current=head->next;
    current->head=head;
    current->prev = head;
    current->x=-20;
    current->y=10;
    current->next = (Waypoint*)malloc(sizeof(Waypoint));

    current = current->next;
    current->head=head;
    current->prev = head;
    current->x=-20;
    current->y=-20;
    current->next = (Waypoint*)malloc(sizeof(Waypoint));

    current = current->next;
    current->head=head;
    current->prev = head;
    current->x=20;
    current->y=-20;
    current->next = NULL;

    if (head->next==NULL)
    {
        printf("FAIL!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
    }

    return head;
}

Intersection find_intersection(float L1x1, float L1y1, float L1x2, float L1y2,  float L2x1, float L2y1, float L2x2, float L2y2)
{
    float x,y,s,t,sn,sd,tn,td;
    int exists;
    Intersection intersection;
    // float x0,x1,x2,x3,y0,y1,y2,y3;
    /*  x0=P1x1;
      x1=P1x2;
      x2=P2x1;
      x3=P2x2;

      y0=P1y1;
      y1=P1y2;
      y2=P2y1;
      y3=P2y2;*/

//-(-L2x1*L2y2+L2y2*L1x1-L2y1*L1x1+L2x2*L2y1-L2x2*L1y1+L2x1*L1y1)/(L2y2*L1x2-L2y2*L1x1-L2y1*L1x2+L2y1*L1x1+L2x2*L1y1-L2x2*L1y2-L2x1*L1y1+L2x1*L1y2)
//(-L1x1*L1y2+L2x1*L1y2-L2y1*L1x2-L2x1*L1y1+L1x2*L1y1+L2y1*L1x1)/(L2y2*L1x2-L2y2*L1x1-L2y1*L1x2+L2y1*L1x1+L2x2*L1y1-L2x2*L1y2-L2x1*L1y1+L2x1*L1y2)

    tn = -(-L2x1*L2y2+L2y2*L1x1-L2y1*L1x1+L2x2*L2y1-L2x2*L1y1+L2x1*L1y1);
    td = (L2y2*L1x2-L2y2*L1x1-L2y1*L1x2+L2y1*L1x1+L2x2*L1y1-L2x2*L1y2-L2x1*L1y1+L2x1*L1y2);
    sn = (-L1x1*L1y2+L2x1*L1y2-L2y1*L1x2-L2x1*L1y1+L1x2*L1y1+L2y1*L1x1);//(-y2*x1+y2*x0+y0*x1+y1*x2-y1*x0-y0*x2);
    sd = (L2y2*L1x2-L2y2*L1x1-L2y1*L1x2+L2y1*L1x1+L2x2*L1y1-L2x2*L1y2-L2x1*L1y1+L2x1*L1y2);//(y3*x1-y3*x0-y2*x1+y2*x0+y1*x2-y1*x3-y0*x2+y0*x3);

    if (sd==0 | td==0)
    {
        exists=0;
        intersection.exists=exists;
        return intersection;

    }
    else
    {
        t = tn/td;
        s= sn/sd;
    }
    if ((t<=1 && t>=0) && (s<=1 && s>=0) )
    {
        exists=1;
        x = L1x1+(L1x2-L1x1)*t;
        y = L1y1+(L1y2-L1y1)*t;
        intersection.exists=exists;
        intersection.x=x;
        intersection.y=y;
        return intersection;

    }
    else
    {
        intersection.exists=0;
        return intersection;
    }

}

Obstacle* Obstaclesinit(Dstar *dstar)
{
    Obstacle* head = (Obstacle*) malloc(sizeof(Obstacle));
    Obstacle* current;
    head->P1x = -42;
    head->P1y = 45;
    head->P2x = -45;
    head->P2y = -35;
    head->prev=NULL;
    head->head = head;
    head->next = (Obstacle*)malloc(sizeof(Obstacle));

    //init_graph(dstar,head->P1x,head->P1y,head->P2x,head->P2y);
    //printf("wwwww\n");
    current = head->next;
    current->P1x = 25;
    current->P1y = -25;
    current->P2x = 25;
    current->P2y = 55;
    current->prev=NULL;
    current->head = head;
    current->next = (Obstacle*)malloc(sizeof(Obstacle));

    //    init_graph(dstar,current->P1x,current->P1y,current->P2x,current->P2y);

    current = current->next;
    current->P1x = -45;
    current->P1y = -15;
    current->P2x = -60;
    current->P2y = 43;
    current->prev=NULL;
    current->head = head;
    current->next = (Obstacle*)malloc(sizeof(Obstacle));

    //init_graph(dstar,current->P1x,current->P1y,current->P2x,current->P2y);

    current = current->next;
    current->P1x = -37;
    current->P1y = -39;
    current->P2x = -42;
    current->P2y = -58;
    current->prev=NULL;
    current->head = head;
    current->next = (Obstacle*)malloc(sizeof(Obstacle));

    //init_graph(dstar,current->P1x,current->P1y,current->P2x,current->P2y);
    current = current->next;
    current->P1x = 50;
    current->P1y = -50;
    current->P2x = 50;
    current->P2y = 50;
    current->prev=NULL;
    current->head = head;
    current->next = (Obstacle*)malloc(sizeof(Obstacle));

    current = current->next;
    current->P1x = 1;
    current->P1y = -50;
    current->P2x = 1;
    current->P2y = 50;
    current->prev=NULL;
    current->head = head;
    current->next = (Obstacle*)malloc(sizeof(Obstacle));

    current = current->next;
    current->P1x = -42;
    current->P1y = -48;
    current->P2x = -60;
    current->P2y = -70;
    current->prev=NULL;
    current->head = head;
    current->next = NULL;

    //init_graph(dstar,current->P1x,current->P1y,current->P2x,current->P2y);

    return head;

}

//Known_Obstacle* detect_obstacles(Mat State,Obstacle* Obstaclelist)

void display_real_obstacles(Obstacle* head, Mat *img, Point2d origin, int width, int height)
{
    while (head!=NULL)
    {
        Point2d local1,pixel1;
        Point2d local2,pixel2;
        local1.x = head->P1x;
        local1.y = head->P1y;
        local2.x = head->P2x;
        local2.y = head->P2y;
        pixel1 = local_to_pixel(local1,origin,width,height);
        pixel2 = local_to_pixel(local2,origin,width,height);
        line( *img, pixel1,pixel2, Scalar(255,255,255), 1, CV_AA, 0);
        head=head->next;
    }


}


void display_detection_lines(Detection_line* head, Mat *img,int onoff)
{
    while (head!=NULL)
    {
        if (onoff==1)
        {
            line( *img, Point(img->cols*0.5f + 5*head->P1x, img->rows*0.5f - 5*head->P1y ),Point(img->cols*0.5f + 5*head->P2x, img->rows*0.5f - 5*head->P2y ), Scalar(255,255,255), 1, CV_AA, 0);
        }
        else
        {
            line( *img, Point(img->cols*0.5f + 5*head->P1x, img->rows*0.5f - 5*head->P1y ),Point(img->cols*0.5f + 5*head->P2x, img->rows*0.5f - 5*head->P2y ), Scalar(0,0,0), 1, CV_AA, 0);
        }
        head=head->next;
    }


}


void display_known_obstacles(Known_Obstacle* head,Mat *img, Point2d origin, int width, int height)
{
    //assert(head != NULL);

    while (head!=NULL)
    {
        Point2d local1,pixel1;
        Point2d local2,pixel2;
        local1.x = head->x;
        local1.y = head->y;
        local2.x = head->x+1;
        local2.y = head->y;
        pixel1 = local_to_pixel(local1,origin,width,height);
        pixel2 = local_to_pixel(local2,origin,width,height);
        line( *img, pixel1,pixel2, Scalar(0,255,255), 1, CV_AA, 0);
        head=head->next;
    }


}


Known_Obstacle* detect_obstacles(Obstacle* obstaclelist, Mat State,Dstar* dstar)
{
    Known_Obstacle* knownlist = (Known_Obstacle*)malloc(sizeof(Known_Obstacle));
    Detection_line* currentline;
    Obstacle* currentobstacle;
    Known_Obstacle* currentknown=knownlist;
    Intersection intersection;
    int n=0;
    Detection_line* linelist = create_detection_lines(State);
    // display_detection_lines(linelist,&img,1);
    Detection_line* prevline;
    currentline=linelist;
    do
    {
        currentobstacle=obstaclelist;
        do
        {
            intersection = find_intersection(currentline->P1x, currentline->P1y, currentline->P2x, currentline->P2y,  currentobstacle->P1x, currentobstacle->P1y, currentobstacle->P2x, currentobstacle->P2y);
            if (intersection.exists)
            {
                // printf("found somthing\n");

                currentknown->next=(Known_Obstacle*)malloc(sizeof(Known_Obstacle));
                if (n==0)
                {
                    knownlist=currentknown->next;
                    n=1;
                } //this is a memory leak if we dont recover the original pointer and free it
                currentknown=currentknown->next;

                currentknown->x = intersection.x;
                currentknown->y = intersection.y;
                float x=currentknown->x;
                float y=currentknown->y;
                dstar->updateCell(x,y,100);
                dstar->updateCell(x+1,y,75);
                dstar->updateCell(x-1,y,75);
                dstar->updateCell(x,y+1,75);
                dstar->updateCell(x,y-1,75);
                dstar->updateCell(x+1,y+1,75);
                dstar->updateCell(x+1,y-1,75);
                dstar->updateCell(x-1,y+1,75);
                dstar->updateCell(x-1,y-1,75);

                dstar->updateCell(x+2,y,25);
                dstar->updateCell(x-2,y,25);
                dstar->updateCell(x,y+2,25);
                dstar->updateCell(x,y-2,25);
                dstar->updateCell(x+2,y+2,25);
                dstar->updateCell(x+2,y-2,25);
                dstar->updateCell(x-2,y+2,25);
                dstar->updateCell(x-2,y-2,25);

                currentknown->next = NULL;
            }
            currentobstacle=currentobstacle->next;
        }
        while (currentobstacle!=NULL);

        //if (n==0) return NULL;

        prevline=currentline;
        currentline=currentline->next;
        free(prevline);
    }
    while (currentline!=NULL);

    if (n==0) return NULL;
    return knownlist;




}

int generate_fake_range_data(Obstacle* obstaclelist, Mat State,Dstar* dstar)
{
    Known_Obstacle* knownlist = (Known_Obstacle*)malloc(sizeof(Known_Obstacle));
    Detection_line* currentline;
    Obstacle* currentobstacle;
    Known_Obstacle* currentknown=knownlist;
    Intersection intersection;
    int n=0;
    Detection_line* linelist = create_detection_lines(State);
    // display_detection_lines(linelist,&img,1);
    Detection_line* prevline;
    currentline=linelist;
    float closest = 9999;
    float distance=9999;
    do
    {
        currentobstacle=obstaclelist;
        do
        {
            intersection = find_intersection(currentline->P1x, currentline->P1y, currentline->P2x, currentline->P2y,  currentobstacle->P1x, currentobstacle->P1y, currentobstacle->P2x, currentobstacle->P2y);
            if (intersection.exists)
            {
                // printf("found somthing\n");

                // currentknown->next=(Known_Obstacle*)malloc(sizeof(Known_Obstacle));
                if (n==0)
                {
                    // knownlist=currentknown->next;
                    n=1;
                } //this is a memory leak if we dont recover the original pointer and free it
                // currentknown=currentknown->next;

                // currentknown->x = intersection.x;
                // currentknown->y = intersection.y;
                float x = State.at<float>(0);
                float y = State.at<float>(1);
                distance = sqrt((x-intersection.x)*(x-intersection.x) + (y-intersection.y)*(y-intersection.y));
                if (distance<closest) closest = distance;

                // float x=currentknown->x;
                // float y=currentknown->y;
                /* dstar->updateCell(x,y,100);
                 dstar->updateCell(x+1,y,75);
                 dstar->updateCell(x-1,y,75);
                 dstar->updateCell(x,y+1,75);
                 dstar->updateCell(x,y-1,75);
                 dstar->updateCell(x+1,y+1,75);
                 dstar->updateCell(x+1,y-1,75);
                 dstar->updateCell(x-1,y+1,75);
                 dstar->updateCell(x-1,y-1,75);

                 dstar->updateCell(x+2,y,25);
                 dstar->updateCell(x-2,y,25);
                 dstar->updateCell(x,y+2,25);
                 dstar->updateCell(x,y-2,25);
                 dstar->updateCell(x+2,y+2,25);
                 dstar->updateCell(x+2,y-2,25);
                 dstar->updateCell(x-2,y+2,25);
                 dstar->updateCell(x-2,y-2,25);

                 currentknown->next = NULL;*/
            }
            currentobstacle=currentobstacle->next;
        }
        while (currentobstacle!=NULL);

        //if (n==0) return NULL;

        prevline=currentline;
        currentline=currentline->next;
        free(prevline);
    }
    while (currentline!=NULL);
    printf("n=%d, closest=%f\n",n,closest);
    if (n==0) return 9999;
    return closest;




}

Detection_line* create_detection_lines(Mat State)
{
    float tiny=.001;
    float field_of_view = pi/8;
    int num_lines=7;
    float dtheta=field_of_view/(num_lines-1);

    float theta = State.at<float>(2);
    float mintheta=theta-field_of_view/2;
    float maxtheta=theta+field_of_view/2;

    float x=State.at<float>(0);
    float y=State.at<float>(1);

    float angle;

    Detection_line *head = (Detection_line*)malloc(sizeof(Detection_line));
    Detection_line *current = head;
    Detection_line *prev = NULL;

    for(angle=mintheta; angle<=(maxtheta+tiny); angle+=dtheta)
    {
        current->P1x=x;
        current->P1y=y;
        current->P2x=x+12*cos(angle);
        current->P2y=y+12*sin(angle);
        current->next=(Detection_line*)malloc(sizeof(Detection_line));
        current->prev=prev;
        prev = current;
        current=current->next;
    }
    current=prev;
    free(current->next);
    current->next=NULL;

    return head;

}

void display_path(list<state> mypath, Mat *img,int c,Point2d origin, int width, int height)
{
    float x1,y1,x2,y2;
    int n=0;
    Point2d local1,pixel1;
    Point2d local2,pixel2;


    list<state>::iterator it;
    it = mypath.begin();

    while (it != mypath.end()/*!mypath.empty()*/)
    {
        //printf("loop ");
        if (n==0)
        {
            // x1 =
            //y1 =
            local1.x =  it->x/4.0;//mypath.front().x/4.0;
            local1.y =  it->y/4.0;//mypath.front().y/4.0;
            n=1;
            continue;
        }
        else if (n==1)
        {
            x2 = local1.x;
            y2 = local1.y;
            local2.x = local1.x;
            local2.y = local1.y;
            local1.x = it->x/4.0;//mypath.front().x/4.0;
            local1.y = it->y/4.0;//mypath.front().y/4.0;
        }
        // printf("line from (%f,%f) to (%f,%f)\n",x1,y1,x2,y2);
        pixel1 = local_to_pixel(local1,origin,width,height);
        pixel2 = local_to_pixel(local2,origin,width,height);
        line( *img, pixel1,pixel2, Scalar(0,c,0), 1, CV_AA, 0);
        //mypath.pop_front();
        it++;
    }
    return;

}

void init_graph(Dstar *dstar,float x1,float y1,float x2, float y2)
{

    float fx,fy;
    float m;// = (y2-y1)/(x2-x1);
    int y;//=y1;
    int lasty;//=y1;
    float dy;
    dstar->updateCell(x1,y1,100);
    float tempx,tempy;
    if (x2<x1)
    {
        tempx=x1;
        x1=x2;
        x2=tempx;
        tempy=y1;
        y1=y2;
        y2=tempy;
    }
    m = (y2-y1)/(x2-x1);
    y=y1;
    lasty=y;

    //printf("barrier from (%f,%f) to %f,%f), m=%f\n",x1,y1,x2,y2,m);
    if (x1==x2)
    {
        if (y2<=y1)
        {
            tempy=y1;
            y1=y2;
            y2=tempy;
        }
        for(y=y1; y<=y2; y++)
        {
            //printf("(%f,%d) is impassable\n",x1,y);
            dstar->updateCell(x1,y,100);
        }
    }
    else
    {


        for (int x=x1; x<=x2; x++)
        {
            // printf("x is %d\n",x );
            fy = y1 + m*(x-x1);
            y = fy;
            dstar->updateCell(x,y,100);
            dy = y-lasty;
            // printf("real y is %f, dy=%f\n",fy,dy);
            for (y=(int)lasty-1; y<=fy; y++)
            {
                dstar->updateCell(x,y,100);
                // printf("(%d,%d) is impassable\n",x,y);
            }
            lasty=y;
        }
    }
    //printf("?!@#\n");

}

Point2d GPS_to_pixel(Point2d point, int width, int height)
{
    Point2d pixelPoint;
    double GPSx,GPSy,Pixelx,Pixely;
    // printf("fabs(long)=%lf\n",point.x);
    GPSx = point.x;
    GPSy = point.y;

    double dLat,dLong;
    //int height=482,width=910;


//   coord.x = 86.915;
    // coord.y = 40.425;
    /*//////Zoomed out
        L=86.93213056;
        R=86.90999167;
        T=40.43241667;
        B=40.42354722;
    //////Engr fountain
        L=86.91629167;
        R=86.91122778;
        T=40.42976389;
        B=40.42775556;*/
    // coord.y = 40.428738;
    dLat = MAPT-MAPB;
    dLong = MAPR-MAPL;
    //printf("x-L=%lf, dL=%lf\n",GPSz.)
    Pixelx = (GPSx-MAPL)/dLong*width;

    Pixely = height-(GPSy-MAPB)/dLat*height;

    pixelPoint.x=Pixelx;
    pixelPoint.y=Pixely;
    //printf("Pixel=(%lf,%lf)\n",Pixelx,Pixely);
    return pixelPoint;
}
Point2d GPS_to_local(Point2d GPS,Point2d GPS_of_origin)
{
    double dx = GPS_of_origin.x-GPS.x;
    double dy = GPS.y-GPS_of_origin.y;
    Point2d coord;
    coord.x = dx*METERS_PER_DEGREE;
    coord.y = dy*METERS_PER_DEGREE;
    return coord;
}
Point2d local_to_GPS(Point2d local, Point2d GPS_of_origin)
{
    Point2d coord;

    coord.x = GPS_of_origin.x - local.x/METERS_PER_DEGREE;
    coord.y = GPS_of_origin.y + local.y/METERS_PER_DEGREE;
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
    //printf("x-L=%lf, dL=%lf\n",GPSz.)
    gps.x =pixel.x*dLong/width+MAPL;

    gps.y= -pixel.y*dLat/height+dLat+MAPB;


    //Pixely = height-(GPSy-MAPB)/dLat*height;
    // -Pixely*dLat/height +dLat + MAPB = (GPSy);
    //-Pixely*dLat*height +  height*dLat*height +MAPB = GPSy;

    return gps;
}
void display_waypoints(Waypoint* head, Mat &img,Point2d GPS_of_origin,int width,int height)
{
    while (head!=NULL)
    {

        Point2d local;
        local.x = head->x;
        local.y = head->y;
        Point2d pixel = local_to_pixel(local,GPS_of_origin,width,height);
        drawCross(pixel,Scalar(0,0,255),5);
        head=head->next;
    }
}
void insert_Front(Waypoint* newwaypoint)
{
    Waypoint* temp;
    if (waypoint==NULL)
    {
        waypoint= newwaypoint;
        newwaypoint->next = NULL;
        newwaypoint->prev = NULL;
        newwaypoint->head = newwaypoint;
        return;
    }


    temp = waypoint;
    waypoint = newwaypoint;
    newwaypoint->next = temp;
    newwaypoint->prev = temp->prev;
    newwaypoint->head = temp->head;
}
void insert_Back(Waypoint* newwaypoint)
{
    Waypoint* temp,*prev;

    if (waypoint==NULL)
    {
        waypoint= newwaypoint;
        newwaypoint->next = NULL;
        newwaypoint->prev = NULL;
        newwaypoint->head = newwaypoint;
        return;
    }

    temp = waypoint;

    while (temp->next != NULL)
    {
        prev= temp;
        temp = temp->next;
    }

    // waypointlist = newwaypoint;
    temp->next = newwaypoint;
    newwaypoint->next = NULL;
    newwaypoint->prev = temp;
    newwaypoint->head = temp->head;
}
