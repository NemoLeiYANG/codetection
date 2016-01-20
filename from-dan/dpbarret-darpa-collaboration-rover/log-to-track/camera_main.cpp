/* Demo of modified Lucas-Kanade optical flow algorithm.
   See the printf below */
#include <windows.h>


#ifdef _CH_
#pragma package <opencv>
#endif

#define CV_NO_BACKWARD_COMPATIBILITY

#ifndef _EiC
//#include "cv.h"
//#include "highgui.h"
#include <stdio.h>
#include <ctype.h>

#include "opencv2/video/tracking.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"


#endif

//#include "MyComWin.h"

IplImage *image = 0, *grey = 0, *prev_grey = 0, *pyramid = 0, *prev_pyramid = 0, *swap_temp;

int win_size = 10;
const int MAX_COUNT = 500;
CvPoint2D32f* points[2] = {0,0}, *swap_points;
char* status = 0;
int count = 0;
int need_to_init = 0;
int night_mode = 0;
int flags = 0;
int add_remove_pt = 0;
CvPoint pt, pt2;
unsigned char tosend[7];
int i2;

typedef struct Waypoint
{
    float x;
    float y;
    struct Waypoint* next;
    struct Waypoint* prev;
    struct Waypoint* head;

} Waypoint;
extern Waypoint* waypoint;

void camera_on_mouse( int event, int x, int y, int flags, void* param )
{
    //
    if( !image )
        return;

    if( image->origin )
        y = image->height - y;

    if( event == CV_EVENT_LBUTTONDOWN )
    {
        pt = cvPoint(x,y);
        add_remove_pt = 1;
        waypoint=NULL;
        printf("\n\n\n\n\n\n clicked on video \n\n\n\n\n\n\n\n");
    }
    else if (event == CV_EVENT_RBUTTONDOWN)
    {
        pt2 = cvPoint(x,y);

    }


}

CvCapture* capture;
HANDLE cam_hSerial;
IplImage* frame;
            IplImage* eig;
            IplImage* temp;
            double quality;
            double min_distance;

void initialize_camera()
{
   capture = 0;
   capture = cvCaptureFromCAM(-1);
    if( !capture )
    {
        fprintf(stderr,"Could not initialize capturing...\n");
        return;
    }

    //cvNamedWindow( "LkDemo", 0 );
    //cvSetMouseCallback( "LkDemo", camera_on_mouse, 0 );

}

int camera_track(int scan)
{

	char byte;
    char * cptr;
    short x,y,blank;

	float delay1,delay2,delay3;
	int xsum,ysum;
	int right = 0, left = 0, up = 0, down = 0;
	////////////////////////////////////////////////////
	//HANDLE hSerial;
	//DCB dcbSerialParams = {0};
	//DCB dcbSerial;
	DWORD dwBytesRead = 0;

	//hSerial = CreateFile("COM3",GENERIC_READ | GENERIC_WRITE,0,	0,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,0);
	//if(hSerial==INVALID_HANDLE_VALUE)
	//{
	//	if(GetLastError()==ERROR_FILE_NOT_FOUND)
	//	{
	//		printf("failed to open serial port\n");
		//serial port does not exist. Inform user.
		//}
	//some other error occurred. Inform user.
	//}

	//dcbSerial.DCBlength=sizeof(dcbSerialParams);
	//if (!GetCommState(hSerial, &dcbSerialParams))
	//{
	//	printf("error getting state\n");
	//	//error getting state
	//}
	//dcbSerialParams.BaudRate=CBR_38400;
	//dcbSerialParams.ByteSize=8;
	//dcbSerialParams.StopBits=ONESTOPBIT;
	//dcbSerialParams.Parity=NOPARITY;
//	if(!SetCommState(hSerial, &dcbSerialParams))
	//{

	//	printf("error setting serial port state\n");
//	}

	//char szBuff[1] = {Byte};




	////////////////////////////////////////////////////////
   // if( argc == 1 || (argc == 2 && strlen(argv[1]) == 1 && isdigit(argv[1][0])))
   //     capture = cvCaptureFromCAM( argc == 2 ? argv[1][0] - '0' : 0 );
   // else if( argc == 2 )
    //    capture = cvCaptureFromAVI( argv[1] );
	//capture = cvCaptureFromCAM(-1);
   // if( !capture )
  //  {
  //      fprintf(stderr,"Could not initialize capturing...\n");
  //      return -1;
  //  }

    /* print a welcome message, and the OpenCV version */
 //   printf ("Welcome to lkdemo, using OpenCV version %s (%d.%d.%d)\n",
//	    CV_VERSION,
//	    CV_MAJOR_VERSION, CV_MINOR_VERSION, CV_SUBMINOR_VERSION);

  //  printf( "Hot keys: \n"
   //         "\tESC - quit the program\n"
  //          "\tr - auto-initialize tracking\n"
   //         "\tc - delete all the points\n"
  //          "\tn - switch the \"night\" mode on/off\n"
  //          "To add/remove a feature point click it\n" );

  //  cvNamedWindow( "LkDemo", 0 );
  //  cvSetMouseCallback( "LkDemo", camera_on_mouse, 0 );

   // for(;;)

        frame = 0;
        int i, k, c;

        frame = cvQueryFrame( capture );
        if( !frame )
            return 0;

        if( !image )
        {
            /* allocate all the buffers */
            image = cvCreateImage( cvGetSize(frame), 8, 3 );
            image->origin = frame->origin;
            grey = cvCreateImage( cvGetSize(frame), 8, 1 );
            prev_grey = cvCreateImage( cvGetSize(frame), 8, 1 );
            pyramid = cvCreateImage( cvGetSize(frame), 8, 1 );
            prev_pyramid = cvCreateImage( cvGetSize(frame), 8, 1 );
            points[0] = (CvPoint2D32f*)cvAlloc(MAX_COUNT*sizeof(points[0][0]));
            points[1] = (CvPoint2D32f*)cvAlloc(MAX_COUNT*sizeof(points[0][0]));
            status = (char*)cvAlloc(MAX_COUNT);
            flags = 0;
        }

        cvCopy( frame, image, 0 );
        cvCvtColor( image, grey, CV_BGR2GRAY );

        if( night_mode )
            cvZero( image );

        if( need_to_init )
        {
            /* automatic initialization */
            eig = cvCreateImage( cvGetSize(grey), 32, 1 );
            temp = cvCreateImage( cvGetSize(grey), 32, 1 );
            quality = 0.01;
            min_distance = 10;

            count = MAX_COUNT;
            cvGoodFeaturesToTrack( grey, eig, temp, points[1], &count,
                                   quality, min_distance, 0, 3, 0, 0.04 );
            cvFindCornerSubPix( grey, points[1], count,
                cvSize(win_size,win_size), cvSize(-1,-1),
                cvTermCriteria(CV_TERMCRIT_ITER|CV_TERMCRIT_EPS,20,0.03));
            cvReleaseImage( &eig );
            cvReleaseImage( &temp );

            add_remove_pt = 0;
        }
        else if( count > 0 )
        {
            cvCalcOpticalFlowPyrLK( prev_grey, grey, prev_pyramid, pyramid,
                points[0], points[1], count, cvSize(win_size,win_size), 3, status, 0,
                cvTermCriteria(CV_TERMCRIT_ITER|CV_TERMCRIT_EPS,20,0.03), flags );
            flags |= CV_LKFLOW_PYR_A_READY;


			xsum=0;
			ysum=0;


            for( i = k = 0; i < count; i++ )
            {
                if( add_remove_pt )
                {
                    double dx = pt.x - points[1][i].x;
                    double dy = pt.y - points[1][i].y;

                    if( dx*dx + dy*dy <= 25 )
                    {
                        add_remove_pt = 0;
                        continue;
                    }
                }

                if( !status[i] )
                    continue;

                points[1][k++] = points[1][i];
                cvCircle( image, cvPointFrom32f(points[1][i]), 3, CV_RGB(0,255,0), -1, 8,0);

				xsum+=points[1][i].x;
				ysum+=points[1][i].y;



			}
			//printf("count is %d\n",count);



            tosend[0] = 0xFF;
            tosend[1] = 0x03;


            tosend[6] = 0xFE;


			/*blank = (short)(999);



			////////////////////////////////////////////////////////////////////////////
			// send 999
			//for (delay1=0;delay1<999;delay1++) for (delay2=0;delay2<99;delay2++) for(delay3=0;delay3<999;delay3++);
			cptr = (char*)&blank;
			byte = *(cptr+1);

			if(!WriteFile(hSerial, &byte, 1, &dwBytesRead, NULL))
			{
				printf("unable to write byte\n");//error occurred. Report to user.
			}
           	byte = *cptr;

			//
			if(!WriteFile(hSerial, &byte, 1, &dwBytesRead, NULL))
			{
				printf("unable to write byte\n");//error occurred. Report to user.
			}
*/         //if(right == 0 && left == 0)
			if (count!=0 )
			{


				/////////
				//calculate x and y avgs
				x = 2*xsum/count;
				y = 2*ysum/count;
			////////////////////////////////////////////////////////////////////////////
				// send x

				cptr = (char*)&x;

                tosend[2] = *(cptr+1);
                tosend[3] = *cptr;

				/*byte = *(cptr+1);

				if(!WriteFile(hSerial, &byte, 1, &dwBytesRead, NULL))
				{
					printf("unable to write byte\n");//error occurred. Report to user.
				}

            	byte = *cptr;

				//
				if(!WriteFile(hSerial, &byte, 1, &dwBytesRead, NULL))
				{
					printf("unable to write byte\n");//error occurred. Report to user.
				}
			*/	//////////////////////////////////////////////////////////////////////////////
				//// send y

				cptr = (char*)&y;

                tosend[4] = *(cptr+1);
                tosend[5] = *cptr;
				/*byte = *(cptr+1);

				if(!WriteFile(hSerial, &byte, 1, &dwBytesRead, NULL))
				{
					printf("unable to write byte\n");//error occurred. Report to user.
				}

            	byte = *cptr;

				//
				if(!WriteFile(hSerial, &byte, 1, &dwBytesRead, NULL))
				{
					printf("unable to write byte\n");//error occurred. Report to user.
				}
*/

//SEND START PIXELS AND STOP BYTE
/*
                for (i2=0; i2<7; i2++)
                {
                    printf("%x ", tosend[i2]);

                }
                    printf("\n");
				if(!WriteFile(hSerial, &tosend, 7, &dwBytesRead, NULL))
				{
					printf("unable to write byte\n");//error occurred. Report to user.
				}

				printf("%d dots,  avg is at (x,y)=(%x,%x)\n",count,x,y);*/
			}
            count = k;
        }
    //if(right == 0 && left == 0)
		if (count == 0)
		{
            tosend[0] = 0xFF;
            tosend[1] = 0x03;


            tosend[6] = 0xFE;

		/*		blank = (short)(999);

			////////////////////////////////////////////////////////////////////////////
			// send 999
			//for (delay1=0;delay1<999;delay1++) for (delay2=0;delay2<99;delay2++) for(delay3=0;delay3<999;delay3++);
			cptr = (char*)&blank;
			byte = *(cptr+1);

			if(!WriteFile(hSerial, &byte, 1, &dwBytesRead, NULL))
			{
				printf("unable to write byte\n");//error occurred. Report to user.
			}
           	byte = *cptr;

			//
			if(!WriteFile(hSerial, &byte, 1, &dwBytesRead, NULL))
			{
				printf("unable to write byte\n");//error occurred. Report to user.
			}
	*/			////////////////////////////////////////////////////////////////////////////
				// send x
				x = 320;
				cptr = (char*)&x;
                tosend[2] = *(cptr+1);
                tosend[3] = *cptr;

/*				byte = *(cptr+1);

				if(!WriteFile(hSerial, &byte, 1, &dwBytesRead, NULL))
				{
					printf("unable to write byte\n");//error occurred. Report to user.
				}

            	byte = *cptr;

				//
				if(!WriteFile(hSerial, &byte, 1, &dwBytesRead, NULL))
				{
					printf("unable to write byte\n");//error occurred. Report to user.
				}
				//////////////////////////////////////////////////////////////////////////////
	*/			//// send y
				y = 240;
				cptr = (char*)&y;
                tosend[4] = *(cptr+1);
                tosend[5] = *cptr;

	/*			byte = *(cptr+1);

				if(!WriteFile(hSerial, &byte, 1, &dwBytesRead, NULL))
				{
					printf("unable to write byte\n");//error occurred. Report to user.
				}

            	byte = *cptr;

				//
				if(!WriteFile(hSerial, &byte, 1, &dwBytesRead, NULL))
				{
					printf("unable to write byte\n");//error occurred. Report to user.
				}
*/

		}

		if (scan==1)
		{
		    right=1;
		    left=0;
		}
		if (scan==2)
		{
		    right=0;
		    left=1;
		}
       // printf("\n\nSCAN=%d\n",scan);
		if (right == 1)
		{

            tosend[0] = 0xFF;
            tosend[1] = 0x03;
            x = 500;//380;
            cptr = (char*)&x;
            tosend[2] = *(cptr+1);
            tosend[3] = *cptr;

            y = 240;
            cptr = (char*)&y;
            tosend[4] = *(cptr+1);
            tosend[5] = *cptr;

            tosend[6] = 0xFE;
		}

		if (left == 1)
		{
            tosend[0] = 0xFF;
            tosend[1] = 0x03;
            x = 130;//260;
            cptr = (char*)&x;
            tosend[2] = *(cptr+1);
            tosend[3] = *cptr;

            y = 240;
            cptr = (char*)&y;
            tosend[4] = *(cptr+1);
            tosend[5] = *cptr;

            tosend[6] = 0xFE;
		}

		if (up == 1)
		{
            tosend[0] = 0xFF;
            tosend[1] = 0x03;
            x = 320;
            cptr = (char*)&x;
            tosend[2] = *(cptr+1);
            tosend[3] = *cptr;

            y = 180;
            cptr = (char*)&y;
            tosend[4] = *(cptr+1);
            tosend[5] = *cptr;

            tosend[6] = 0xFE;
		}

		if (down == 1)
        {
            tosend[0] = 0xFF;
            tosend[1] = 0x03;
            x = 320;
            cptr = (char*)&x;
            tosend[2] = *(cptr+1);
            tosend[3] = *cptr;

            y = 300;
            cptr = (char*)&y;
            tosend[4] = *(cptr+1);
            tosend[5] = *cptr;

            tosend[6] = 0xFE;
        }

         for (i2=0; i2<7; i2++)
                {
                    //printf("%x ", tosend[i2]);

                }
                    printf("\n");
                if(!WriteFile(cam_hSerial, &tosend, 7, &dwBytesRead, NULL))
				{
					printf("unable to write byte\n");//error occurred. Report to user.
				}
				//printf("Sending (x,y)=(%d,%d)\n",x,y);

        if( add_remove_pt && count < MAX_COUNT )
        {
            points[1][count++] = cvPointTo32f(pt);
            cvFindCornerSubPix( grey, points[1] + count - 1, 1,
                cvSize(win_size,win_size), cvSize(-1,-1),
                cvTermCriteria(CV_TERMCRIT_ITER|CV_TERMCRIT_EPS,20,0.03));
            add_remove_pt = 0;
        }

        CV_SWAP( prev_grey, grey, swap_temp );
        CV_SWAP( prev_pyramid, pyramid, swap_temp );
        CV_SWAP( points[0], points[1], swap_points );
        need_to_init = 0;
        //cvShowImage( "LkDemo", image );
        left = 0;
        right = 0;
        up = 0;
        down = 0;
        c = cvWaitKey(1);
        if( (char)c == 27 )
            return count;
        switch( (char) c )
        {
        case 'r':
            need_to_init = 1;
            break;
        case 'c':
            count = 0;
            break;
        case 'n':
            night_mode ^= 1;
            break;
        case 'a':
            left = 1;
             //printf("\n\nMoving left\n\n");
            break;
        case 'd':
            right = 1;
            //printf("\n\nMoving right\n\n");
            break;
        case 'w':
            up = 1;
            //printf("\n\nMoving up\n\n");
            break;
        case 's':
            down = 1;
            //printf("\n\nMoving down\n\n");
            break;


        default:
            ;
        }


   // cvReleaseCapture( &capture );
   // cvDestroyWindow("LkDemo");
	//CloseHandle(hSerial);
    return count;
}

#ifdef _EiC
main(1,"lkdemo.c");
#endif
/*emo", image );

        c = cvWaitKey(10);
        if( (char)c == 27 )
            break;
        switch( (char) c )
        {
        case 'r':
            need_to_init = 1;
            break;
        case 'c':
            count = 0;
            break;
        case 'n':
            night_mode ^= 1;
            break;
        default:
            ;
        }
    }

    cvReleaseCapture( &capture );
    cvDestroyWindow("LkDemo");
	CloseHandle(hSerial);
    return 0;
}

#ifdef _EiC
mai
*/
