#pragma once
#include "videoSequeeze.h"

/*
	四个字符用来表示压缩帧的codec 例如：
	CV_FOURCC(‘P’,‘I’,‘M’,‘1’) = MPEG-1 codec
	CV_FOURCC(‘M’,‘J’,‘P’,‘G’) = motion-jpeg codec
	CV_FOURCC(‘M’, ‘P’, ‘4’, ‘2’) = MPEG-4.2 codec
	CV_FOURCC(‘D’, ‘I’, ‘V’, ‘3’) = MPEG-4.3 codec
	CV_FOURCC(‘D’, ‘I’, ‘V’, ‘X’) = MPEG-4 codec
	CV_FOURCC(‘U’, ‘2’, ‘6’, ‘3’) = H263 codec
	CV_FOURCC(‘I’, ‘2’, ‘6’, ‘3’) = H263I codec
	CV_FOURCC(‘F’, ‘L’, ‘V’, ‘1’) = FLV1 codec
	NOTE：生成文件占用空间最小的编码方式是MPEG-4.2 codec。在VideoWriter类的构造函数参数为CV_FOURCC(‘M’, ‘P’, ‘4’, ‘2’) 。
	最大的是MPEG-1 codec，对应在VideoWriter类的构造函数参数为CV_FOURCC(‘P’,‘I’,‘M’,‘1’) ，所占磁盘空间是前者的5.7倍。
*/

using namespace cv;

int main ()
{
	int faster_times = 10;

	cv::String in_path = "E:/lyh/PointCloudRoamVideoSamples/ShanghaiZhangJiang8Block.mp4";
	//cv::String in_path = "E:/treeExtraction.wmv";
	std::cout << in_path << std::endl;
	cv::String out_path = "E:\\lyh\\PointCloudRoamVideoSamples\\ShanghaiZhangJiang8Block4Times.mp4";
	cv::namedWindow ( "origin", cv::WindowFlags::WINDOW_AUTOSIZE );
	cv::namedWindow ( "faster", cv::WindowFlags::WINDOW_AUTOSIZE );

	cv::VideoCapture videocapture;
	videocapture.open ( in_path );

	if (!videocapture.isOpened())
	{
		std::cout << "Fail to open the video,plz check the path of the origin video" << std::endl;
		system ( "pause" );
		return -1;
	}

	double fps = videocapture.get ( CAP_PROP_FPS ) * faster_times;
	Size size ( (int) videocapture.get ( CAP_PROP_FRAME_WIDTH ), (int) videocapture.get ( CAP_PROP_FRAME_HEIGHT ) );

	VideoWriter writer;
	writer.open ( out_path, CV_FOURCC ( 'M', 'P', '4', '2' ), fps, size, true );
	//the last parameter 如果非零，编码器将希望得到彩色帧并进行编码；否则，是灰度帧（只有在Windows下支持这个标志）。

	Mat gry_frame, bgr_frame, cny_frame;
	while ( 1 )
	{
		videocapture >> bgr_frame;
		if ( bgr_frame.empty () ) break;
		//imshow ( "origin", bgr_frame );

		imshow ( "faster", bgr_frame );
		writer << bgr_frame;

		//按Esc键退出while
		char c = waitKey ( 10 );
		if ( c == 27 ) break;

	}
	videocapture.release ();
	return 0;
}