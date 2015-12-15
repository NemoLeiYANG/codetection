// compile with:
// g++ -o run-TLD.out -I/home/dpbarret/opencv3/include/ /home/dpbarret/opencv3/lib/libopencv_core.so /home/dpbarret/opencv3/lib/libopencv_imgproc.so /home/dpbarret/opencv3/lib/libopencv_highgui.so /home/dpbarret/opencv3/lib/libopencv_ml.so /home/dpbarret/opencv3/lib/libopencv_video.so /home/dpbarret/opencv3/lib/libopencv_features2d.so /home/dpbarret/opencv3/lib/libopencv_calib3d.so /home/dpbarret/opencv3/lib/libopencv_objdetect.so /home/dpbarret/opencv3/lib/libopencv_flann.so /home/dpbarret/opencv3/lib/libopencv_videoio.so /home/dpbarret/opencv3/lib/libopencv_tracking.so run_TLD.cpp

// run with 
// LD_LIBRARY_PATH=~/opencv3/lib ~/run-TLD.out TLD /aux/dpbarret/upgraded-purdue-mindseye-release-t19jul2011/weizmann/daria_run.avi 0
// TLD can be replaced with MIL or BOOSTING to run different algorithms, but TLD is the most recent paper (in PAMI), and has awards and articles about how great and revolutionary it is

#include "/home/dpbarret/opencv3/include/opencv2/core/utility.hpp"
#include "/home/dpbarret/opencv3/include/opencv2/tracking.hpp"
#include "/home/dpbarret/opencv3/include/opencv2/videoio.hpp"
#include "/home/dpbarret/opencv3/include/opencv2/highgui.hpp"
#include <iostream>
#include <cstring>

using namespace std;
using namespace cv;

static Mat image;
static Rect2d boundingBox;
static bool paused;
static bool selectObject = false;
static bool startSelection = false;

static const char* keys =
{ "{@tracker_algorithm | | Tracker algorithm }"
    "{@video_name      | | video name        }"
    "{@start_frame     |0| Start frame       }" 
    "{@bounding_frame  |0,0,0,0| Initial bounding frame}"};

static void onMouse( int event, int x, int y, int, void* )
{
  if( !selectObject )
  {
    switch ( event )
    {
      case EVENT_LBUTTONDOWN:
        //set origin of the bounding box
        startSelection = true;
        boundingBox.x = x;
        boundingBox.y = y;
        break;
      case EVENT_LBUTTONUP:
        //sei with and height of the bounding box
        boundingBox.width = std::abs( x - boundingBox.x );
        boundingBox.height = std::abs( y - boundingBox.y );
        paused = false;
        selectObject = true;
        break;
      case EVENT_MOUSEMOVE:

        if( startSelection && !selectObject )
        {
          //draw the bounding box
          Mat currentFrame;
          image.copyTo( currentFrame );
          rectangle( currentFrame, Point((int) boundingBox.x, (int)boundingBox.y ), Point( x, y ), Scalar( 255, 0, 0 ), 2, 1 );
          imshow( "Tracking API", currentFrame );
        }
        break;
    }
  }
}

static void help()
{
  cout << "\nThis example shows the functionality of \"Long-term optical tracking API\""
       "-- pause video [p] and draw a bounding box around the target to start the tracker\n"
       "Example of <video_name> is in opencv_extra/testdata/cv/tracking/\n"
       "Call:\n"
       "./tracker <tracker_algorithm> <video_name> <start_frame> [<bounding_frame>]\n"
       << endl;

  cout << "\n\nHot keys: \n"
       "\tq - quit the program\n"
       "\tp - pause video\n";
}

int main( int argc, char** argv ){
  CommandLineParser parser( argc, argv, keys );

  String tracker_algorithm = parser.get<String>( 0 );
  String video_name = parser.get<String>( 1 );
  int start_frame = 0;//parser.get<int>( 2 );

  //printf("arg: %s\n",argv[3]);
  int x1 = atoi(argv[3]);
  
  //printf("arg: %s\n",argv[4]);
  int y1 = atoi(argv[4]);
  
  //printf("arg: %s\n",argv[5]);
  int x2 = atoi(argv[5]);
  
  //printf("arg: %s\n",argv[6]);
  int y2 = atoi(argv[6]);

  if( tracker_algorithm.empty() || video_name.empty() )
  {
    help();
    return -1;
  }

  int coords[4]={x1,y1,x2,y2};
  bool initBoxWasGivenInCommandLine=true;
  if (0)
    {
      String initBoundingBox=parser.get<String>(3);
      for(size_t npos=0,pos=0,ctr=0;ctr<4;ctr++){
        npos=initBoundingBox.find_first_of(',',pos);
        if(npos==string::npos && ctr<3){
           printf("bounding box should be given in format \"x1,y1,x2,y2\",where x's and y's are integer cordinates of opposed corners of bdd box\n");
           printf("got: %s\n",initBoundingBox.substr(pos,string::npos).c_str());
           printf("manual selection of bounding box will be employed\n");
           break;
        }
        int num=atoi(initBoundingBox.substr(pos,(ctr==3)?(string::npos):(npos-pos)).c_str());
        if(num<=0){
           printf("bounding box should be given in format \"x1,y1,x2,y2\",where x's and y's are integer cordinates of opposed corners of bdd box\n");
           printf("got: %s\n",initBoundingBox.substr(pos,npos-pos).c_str());
           printf("manual selection of bounding box will be employed\n");
           break;
        }
        coords[ctr]=num;
        pos=npos+1;
      }
      if(coords[0]>0 && coords[1]>0 && coords[2]>0 && coords[3]>0){
          initBoxWasGivenInCommandLine=true;
      }
  }

  //open the capture
  VideoCapture cap;
  cap.open( video_name );
  cap.set( CAP_PROP_POS_FRAMES, start_frame );

  if( !cap.isOpened() )
  {
    help();
    cout << "***Could not initialize capturing...***\n";
    cout << "Current parameter's value: \n";
    parser.printMessage();
    return -1;
  }

  Mat frame;
  paused = true;
  //namedWindow( "Tracking API", 1 );
  //setMouseCallback( "Tracking API", onMouse, 0 );

  //instantiates the specific Tracker
  Ptr<Tracker> tracker = Tracker::create( tracker_algorithm );
  if( tracker == NULL )
  {
    cout << "***Error in the instantiation of the tracker...***\n";
    return -1;
  }

  //get the first frame
  cap >> frame;
  frame.copyTo( image );
  if(initBoxWasGivenInCommandLine){
      selectObject=true;
      paused=false;
      boundingBox.x = coords[0];
      boundingBox.y = coords[1];
      boundingBox.width = std::abs( coords[2] - coords[0] );
      boundingBox.height = std::abs( coords[3]-coords[1]);
      //printf("bounding box with vertices (%d,%d) and (%d,%d) was given in command line\n",coords[0],coords[1],coords[2],coords[3]);
      rectangle( image, boundingBox, Scalar( 255, 0, 0 ), 2, 1 );
  }
  //  imshow( "Tracking API", image );

  bool initialized = false;
  int frameCounter = 0;
  printf("(");
  for ( ;; )
  {
    if( !paused )
    {
      if(initialized){
          cap >> frame;
          if(frame.empty()){
            break;
          }
          frame.copyTo( image );
      }

      if( !initialized && selectObject )
      {
        //initializes the tracker
        if( !tracker->init( frame, boundingBox ) )
        {
          cout << "***Could not initialize tracker...***\n";
          return -1;
        }
        initialized = true;
      }
      else if( initialized )
      {
        //updates the tracker
        if( tracker->update( frame, boundingBox ) )
        {
	  printf("#(%d %d %d %d) ",
		 (int)round(boundingBox.x),
		 (int)round(boundingBox.y),
		 (int)round(boundingBox.x)+(int)round(boundingBox.width),
		 (int)round(boundingBox.y)+(int)round(boundingBox.height));
          rectangle( image, boundingBox, Scalar( 255, 0, 0 ), 2, 1 );
        }
	else
	  printf("#(%d %d %d %d) ",
		 0,
		 0,
		 0,
		 0); // we have no box, so use an arbitrary one so that there is a box for later stages to process
      }
      //imshow( "Tracking API", image );
      frameCounter++;
    }

    char c = (char) waitKey( 2 );
    if( c == 'q' )
      break;
    if( c == 'p' )
      paused = !paused;

  }
  printf(")");

  return 0;
}
