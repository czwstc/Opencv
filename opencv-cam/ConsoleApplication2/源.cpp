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
		cout << "����ͷ��ʧ�ܣ�" << endl;
		return -1;
	}
	char key;
	char filename[200];
	int count = 0;
	namedWindow("����Ƶ��", 1);
	namedWindow("��ͼƬ��", 1);
	while (1)
	{
		key = waitKey(50);
		capture >> frame;
		imshow("����Ƶ��", frame);

		if (key == 27)
			break;//��ESC���˳�����  
		if (key == 32)//���ո����������  
		{
			sprintf_s(filename, "Picture %d.jpg", ++count);
			imwrite(filename, frame);//ͼƬ���浽������Ŀ¼��  
			imshow("��ͼƬ��", frame);
		}
	}
	return 0;
}