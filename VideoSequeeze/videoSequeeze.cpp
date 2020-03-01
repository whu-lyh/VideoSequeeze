#pragma once
#include "videoSequeeze.h"

/*
	�ĸ��ַ�������ʾѹ��֡��codec ���磺
	CV_FOURCC(��P��,��I��,��M��,��1��) = MPEG-1 codec
	CV_FOURCC(��M��,��J��,��P��,��G��) = motion-jpeg codec
	CV_FOURCC(��M��, ��P��, ��4��, ��2��) = MPEG-4.2 codec
	CV_FOURCC(��D��, ��I��, ��V��, ��3��) = MPEG-4.3 codec
	CV_FOURCC(��D��, ��I��, ��V��, ��X��) = MPEG-4 codec
	CV_FOURCC(��U��, ��2��, ��6��, ��3��) = H263 codec
	CV_FOURCC(��I��, ��2��, ��6��, ��3��) = H263I codec
	CV_FOURCC(��F��, ��L��, ��V��, ��1��) = FLV1 codec
	NOTE�������ļ�ռ�ÿռ���С�ı��뷽ʽ��MPEG-4.2 codec����VideoWriter��Ĺ��캯������ΪCV_FOURCC(��M��, ��P��, ��4��, ��2��) ��
	������MPEG-1 codec����Ӧ��VideoWriter��Ĺ��캯������ΪCV_FOURCC(��P��,��I��,��M��,��1��) ����ռ���̿ռ���ǰ�ߵ�5.7����
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
	//the last parameter ������㣬��������ϣ���õ���ɫ֡�����б��룻�����ǻҶ�֡��ֻ����Windows��֧�������־����

	Mat gry_frame, bgr_frame, cny_frame;
	while ( 1 )
	{
		videocapture >> bgr_frame;
		if ( bgr_frame.empty () ) break;
		//imshow ( "origin", bgr_frame );

		imshow ( "faster", bgr_frame );
		writer << bgr_frame;

		//��Esc���˳�while
		char c = waitKey ( 10 );
		if ( c == 27 ) break;

	}
	videocapture.release ();
	return 0;
}