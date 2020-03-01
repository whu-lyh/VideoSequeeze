//load the video from camera on the laptop
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

//#ifdef _DEBUG
//#pragma comment(lib,"opencv_core340d.lib")
//#pragma comment(lib,"opencv_highgui340d.lib")
//#pragma comment(lib,"opencv_video340d.lib")
//#pragma comment(lib,"opencv_videoio340d.lib")
//#pragma comment(lib,"opencv_videostab340d.lib")
//#pragma comment(lib,"opencv_imgproc340d.lib")//cv::cvtColor
//#else
//#pragma comment(lib,"opencv_core340.lib")
//#pragma comment(lib,"opencv_highgui340.lib")
//#pragma comment(lib,"opencv_video340.lib")
//#pragma comment(lib,"opencv_videoio340.lib")
//#pragma comment(lib,"opencv_videostab340.lib")
//#pragma comment(lib,"opencv_imgproc340.lib")
//#endif

using namespace std;
using namespace cv;

int main0 (int argc,char*argv[ ])
{
	argv [1] = "2";
	VideoCapture cap;
	cap.open ( 0 ); //0 means open the local camera on the laotop

	if ( !cap.isOpened () )
	{
		std::cout << "Fail to open the video,plz check the path of the origin video" << std::endl;
		system ( "pause" );
		return -1;
	}

	Mat frame;
	if (argv[1]=="1")
	{
		while ( 1 )
		{
			cap >> frame;
			Mat gray, detected_edges, dst;
			gray.create ( gray.size (), gray.type () );
			detected_edges.create ( detected_edges.size (), detected_edges.type () );
			dst.create ( dst.size (), dst.type () );
			int kernel_size = 3;
			int ratio = 3;
			double lowThreshold = 60;

			cv::cvtColor ( frame, gray, CV_BGR2GRAY );
			cv::blur ( gray, detected_edges, Size ( 3, 3 ) );
			cv::Canny ( detected_edges, detected_edges, lowThreshold, lowThreshold*ratio, kernel_size );
			dst = Scalar::all ( 0 );
			frame.copyTo ( dst, detected_edges );
			imshow ( "Canny retult", dst );

			//quit press ESC
			char c = waitKey ( 10 );
			if ( c == 27 ) break;
		}
	} 
	else if(argv[1]=="2")
	{
		while ( 1 )
		{
			cap >> frame;//equal to cap.read(frame);
			cv::flip ( frame, frame, 1 );//mirror image,just have try and you will know what is this
			cvtColor ( frame, frame, CV_BGR2BGRA );
			if ( frame.empty () )
				break;
			imshow ( "video", frame );

			//quit press ESC
			char c = waitKey ( 10 );
			if ( c == 27 ) break;
		}
	}

	cap.release ();//release all the resources
	cv::destroyAllWindows ();//close all window

	system ( "pause" );
	return 0;
}