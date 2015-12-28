// compile with:
// g++ -o run-MF.out -I/home/dpbarret/opencv3/include/ /home/dpbarret/opencv3/lib/libopencv_core.so /home/dpbarret/opencv3/lib/libopencv_imgproc.so /home/dpbarret/opencv3/lib/libopencv_highgui.so /home/dpbarret/opencv3/lib/libopencv_ml.so /home/dpbarret/opencv3/lib/libopencv_video.so /home/dpbarret/opencv3/lib/libopencv_features2d.so /home/dpbarret/opencv3/lib/libopencv_calib3d.so /home/dpbarret/opencv3/lib/libopencv_objdetect.so /home/dpbarret/opencv3/lib/libopencv_flann.so /home/dpbarret/opencv3/lib/libopencv_videoio.so /home/dpbarret/opencv3/lib/libopencv_tracking.so run_MF.cpp

// run with 
// LD_LIBRARY_PATH=/home/dpbarret/opencv3/lib /home/sbroniko/codetection/source/new-sentence-codetection/run-MF.out *video-path* *start-frame* *x* *y* *w* *h*

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
  { //"{@tracker_algorithm | | Tracker algorithm }"
    "{@video_name      | | video name        }"
    "{@start_frame     |0| Start frame       }" 
    //"{@bounding_frame  |0,0,0,0| Initial bounding frame}"};
    "{@x  |0| Box top-left x}"
    "{@y  |0| Box top-left y}"
    "{@w  |0| Box width}"
    "{@h  |0| Box height}"};

// static void onMouse( int event, int x, int y, int, void* )
// {
//   if( !selectObject )
//   {
//     switch ( event )
//     {
//       case EVENT_LBUTTONDOWN:
//         //set origin of the bounding box
//         startSelection = true;
//         boundingBox.x = x;
//         boundingBox.y = y;
//         break;
//       case EVENT_LBUTTONUP:
//         //sei with and height of the bounding box
//         boundingBox.width = std::abs( x - boundingBox.x );
//         boundingBox.height = std::abs( y - boundingBox.y );
//         paused = false;
//         selectObject = true;
//         break;
//       case EVENT_MOUSEMOVE:

//         if( startSelection && !selectObject )
//         {
//           //draw the bounding box
//           Mat currentFrame;
//           image.copyTo( currentFrame );
//           rectangle( currentFrame, Point((int) boundingBox.x, (int)boundingBox.y ), Point( x, y ), Scalar( 255, 0, 0 ), 2, 1 );
//           imshow( "Tracking API", currentFrame );
//         }
//         break;
//     }
//   }
// }

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

  String tracker_algorithm = "MEDIANFLOW";//parser.get<String>( 0 );
  String video_name = parser.get<String>( 0 );
  int start_frame = parser.get<int>( 1 );
  int x = parser.get<int>( 2 );
  int y = parser.get<int>( 3 );
  int w = parser.get<int>( 4 );
  int h = parser.get<int>( 5 );

  //  printf("%s %d %d %d %d %d\n",video_name.c_str(),start_frame,x,y,w,h);
  //return 0;

  if( tracker_algorithm.empty() || video_name.empty() )
  {
    help();
    return -1;
  }

  //int coords[4]={x1,y1,x2,y2};
  int coords[4]={x,y,w,h};
  bool initBoxWasGivenInCommandLine=true;

  //open the capture
  VideoCapture cap;
  cap.open( video_name );
  cap.set( CAP_PROP_POS_FRAMES, 0);// set starting frame at 0 //start_frame );
  if( !cap.isOpened() )
  {
    help();
    cout << "***Could not initialize capturing...***\n";
    cout << "Current parameter's value: \n";
    parser.printMessage();
    return -1;
  }
  int num_frames = cap.get(CAP_PROP_FRAME_COUNT);
  int frame_width = cap.get(CAP_PROP_FRAME_WIDTH);
  int frame_height = cap.get(CAP_PROP_FRAME_HEIGHT);

  //error check box to make sure it is in frame
  if (((x+w) > (frame_width-1)) || ((y+h) > (frame_height-1)))
  {
    cout << "**ERROR: proposal box outside of image dimensions**\n";
    return -1;
  }

  // printf("num_frames = %d, frame_width = %d, frame_height = %d\n",
  // 	 num_frames,frame_width,frame_height);
  //return 0;

  //copy all frames into an array of Mat
  Mat frames[num_frames];
  for(int i = 0; i < num_frames; i++)
  {
    cap >> frames[i];
  }
  //  printf("frames copied\n");
  //  return 0;

  //create array of Rect2d to hold bounding boxes
  Rect2d boundingBoxes[num_frames];
  Rect2d emptyBoundingBox; //for when no update happens
  emptyBoundingBox.x = 0;
  emptyBoundingBox.y = 0;
  emptyBoundingBox.width = 0;
  emptyBoundingBox.height = 0;

  Mat frame;
  paused = true;

  //instantiates the specific Tracker
  Ptr<Tracker> tracker = Tracker::create( tracker_algorithm );
  if( tracker == NULL )
  {
    cout << "***Error in the instantiation of the tracker...***\n";
    return -1;
  }

  //get the first frame
  frame = frames[start_frame];
  frame.copyTo( image );
  if(initBoxWasGivenInCommandLine){
      selectObject=true;
      paused=false;
      boundingBox.x = coords[0];
      boundingBox.y = coords[1];
      boundingBox.width = coords[2];//std::abs( coords[2] - coords[0] );
      boundingBox.height = coords[3];//std::abs( coords[3]-coords[1]);
      boundingBoxes[start_frame] = boundingBox;
      //printf("bounding box with vertices (%d,%d) and (%d,%d) was given in command line\n",coords[0],coords[1],coords[2],coords[3]);
      //rectangle( image, boundingBox, Scalar( 255, 0, 0 ), 2, 1 );
  }
  // //visualize for debugging
  // rectangle( image, boundingBox, Scalar( 255, 0, 0 ), 2, 1 );
  // imshow( "Tracking API", image );
  // char c = (char) waitKey( 20 );
  // if( c == 'q' )
  //   return 0;
  // if( c == 'p' )
  //   paused = !paused;


  bool initialized = false;
  int frameCounter;

  //do forward and backwards loops based on value of start_frame
  if (start_frame < (num_frames - 1))
  { //do forward loop
    frameCounter = start_frame + 1;
    while (frameCounter < num_frames)
    {
      if( !paused )
      {
	if(initialized)
	{
    	  frame = frames[frameCounter];
          frame.copyTo( image );
	}
	
	if( !initialized && selectObject )
	{ //initializes the tracker
	  
	  if( !tracker->init( frame, boundingBox ) )
	  {
	    cout << "***Could not initialize tracker...***\n";
	    return -1;
	  }
	  initialized = true;
	  boundingBoxes[frameCounter] = boundingBox;
	}
	else if( initialized )
	{ //updates the tracker
	  if( tracker->update( frame, boundingBox ) )
	    boundingBoxes[frameCounter] = boundingBox;
	  else
	    boundingBoxes[frameCounter] = emptyBoundingBox;
	  // we have no box, so use an arbitrary one so that there is a box for later stages to process
	}
	// //visualize for debugging
	// rectangle( image, boundingBox, Scalar( 255, 0, 0 ), 2, 1 );
	// imshow( "Tracking API", image );
	// char c = (char) waitKey( 20 );
	// if( c == 'q' )
	//   return 0;
	// if( c == 'p' )
	//   paused = !paused;
	// cout<<frameCounter<<endl;

	frameCounter++;
      }
    }
  }
  if (start_frame > 0)
  { //do backward loop
    frameCounter = start_frame - 1;
    while (frameCounter >= 0)
    {
      if( !paused )
      {
	if(initialized)
	{
    	  frame = frames[frameCounter];
          frame.copyTo( image );
	}
	if( !initialized && selectObject )
	{ //initializes the tracker
	  if( !tracker->init( frame, boundingBox ) )
	  {
	    cout << "***Could not initialize tracker...***\n";
	    return -1;
	  }
	  initialized = true;
	  boundingBoxes[frameCounter] = boundingBox;
	}
	else if( initialized )
	{ //updates the tracker
	  if( tracker->update( frame, boundingBox ) )
	    boundingBoxes[frameCounter] = boundingBox;
	  else
	    boundingBoxes[frameCounter] = emptyBoundingBox;
	  // we have no box, so use an arbitrary one so that there is a box for later stages to process
	}

	// //visualize for debugging
	// rectangle( image, boundingBox, Scalar( 255, 0, 0 ), 2, 1 );
	// imshow( "Tracking API", image );
	// char c = (char) waitKey( 20 );
	// if( c == 'q' )
	//   return 0;
	// if( c == 'p' )
	//   paused = !paused;
	// cout<<frameCounter<<endl;

	frameCounter--;
      }
    }
  }
  //produce output
  printf("(");
  for (int i = 0; i < num_frames; i++)
  {
    printf("#(%d %d %d %d) ",
	   (int)round(boundingBoxes[i].x),
	   (int)round(boundingBoxes[i].y),
	   (int)round(boundingBoxes[i].x)+(int)round(boundingBoxes[i].width),
	   (int)round(boundingBoxes[i].y)+(int)round(boundingBoxes[i].height));
  }
  printf(")");

  return 0;
}
