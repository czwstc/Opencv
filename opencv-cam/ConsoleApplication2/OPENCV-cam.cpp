#include "stdafx.h"
#include "cv.h"
#include "highgui.h"
#include <opencv2\opencv.hpp>
#include <iostream>

#include <string>

using namespace std;

using namespace cv;

void main()
{
	VideoCapture capture(0);
	VideoWriter writer("VideoTest.avi", CV_FOURCC('M', 'J', 'P', 'G'), 15.0, Size(640, 480));
	Mat frame;

	while (capture.isOpened())
	{
		capture >> frame;
		writer << frame;
		imshow("video", frame);
		if (cvWaitKey(20) == 27)
		{
			break;
		}
	}
}