#pragma once
//this project is used to sequeeze a long video to a n times faster video

#pragma warning(disable: 4267)
#pragma warning(disable: 4251)
#pragma warning(disable: 4267)
#pragma warning(disable: 4244)

#include <opencv2/opencv.hpp>
#include <iostream>

#ifdef _DEBUG
#pragma comment( lib, "opencv_world340d.lib" )
//#pragma comment(lib,"opencv_core340d.lib")
//#pragma comment(lib,"opencv_highgui340d.lib")
//#pragma comment(lib,"opencv_video340d.lib")
//#pragma comment(lib,"opencv_videoio340d.lib")
//#pragma comment(lib,"opencv_videostab340d.lib")
#else
#pragma comment( lib, "opencv_world340.lib" )
//#pragma comment(lib,"opencv_core340.lib")
//#pragma comment(lib,"opencv_highgui340.lib")
//#pragma comment(lib,"opencv_video340.lib")
//#pragma comment(lib,"opencv_videoio340.lib")
//#pragma comment(lib,"opencv_videostab340.lib")
#endif