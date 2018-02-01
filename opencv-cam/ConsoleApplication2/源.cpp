#include "stdafx.h"
#include "cv.h"
#include "highgui.h"
#include <opencv2\opencv.hpp>
#include <iostream>

#include <string>

using namespace std;

using namespace cv;
#include<opencv2\opencv.hpp>  
#include<opencv2\highgui\highgui.hpp>  
#include<opencv2\imgproc\imgproc.hpp>  
#include<iostream>  
#include<stdio.h>  
using namespace cv;
using namespace std;

int main(int argc, char* argv)
{
	VideoCapture  capture(0);
	Mat frame;
	if (!capture.isOpened())
	{
		cout << "摄像头打开失败！" << endl;
		return -1;
	}
	char key;
	char filename[200];
	int count = 0;
	namedWindow("【视频】", 1);
	namedWindow("【图片】", 1);
	while (1)
	{
		key = waitKey(50);
		capture >> frame;
		imshow("【视频】", frame);

		if (key == 27)
			break;//按ESC键退出程序  
		if (key == 32)//按空格键进行拍照  
		{
			sprintf_s(filename, "Picture %d.jpg", ++count);
			imwrite(filename, frame);//图片保存到本工程目录中  
			imshow("【图片】", frame);
		}
	}
	return 0;
}