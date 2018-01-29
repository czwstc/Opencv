#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <opencv2/opencv.hpp>
#define WINDOW_NAME "corner Detection"
using namespace cv;
using namespace std;
Mat g_srcImage, g_grayImage;
int g_maxCornerNumber = 12;
//int g_maxTrackbarNumber = 500;
//-----------------------------【on_GoodFeaturesToTrack( )函数】----------------------------
//          描述：响应滑动条移动消息的回调函数
//----------------------------------------------------------------------------------------------
void on_GoodFeaturesToTrack(int, void*)
{   //【1】对变量小于等于1时的处理
    if (g_maxCornerNumber <= 1) { g_maxCornerNumber = 1; }
    //【2】Shi-Tomasi算法（goodFeaturesToTrack函数）的参数准备
    vector<Point2f> corners;
    double qualityLevel = 0.02;//角点检测可接受的最小特征值
    double minDistance = 30;//角点之间的最小距离
    int blockSize = 4;//计算导数自相关矩阵时指定的邻域范围
    double k = 0.04;//权重系数
    Mat copy = g_srcImage.clone();  //复制源图像到一个临时变量中，作为感兴趣区域
    //【3】进行Shi-Tomasi角点检测
    goodFeaturesToTrack(g_grayImage,//输入图像
                        corners,//检测到的角点的输出向量
                        g_maxCornerNumber,//角点的最大数量
                        qualityLevel,//角点检测可接受的最小特征值
                        minDistance,//角点之间的最小距离
                        Mat(),//感兴趣区域
                        blockSize,//计算导数自相关矩阵时指定的邻域范围
                        false,//不使用Harris角点检测
                        k);//权重系数
    //【4】输出文字信息
    cout << "\n\t>-------------此次检测到的角点数量为：" << corners.size() << endl;
    
    for (int i = 0; i<corners.size(); i++){
        cout << "二维坐标" << i << "  (" << corners[i].x << "," << corners[i].y << ")" << endl;
        stringstream tmp;
        stringstream tmp2;
        string str;
        tmp << corners[i].x << "," <<corners[i].y;
        tmp >> str;
        putText(copy, str, corners[i], cv::FONT_HERSHEY_DUPLEX, 0.5, cv::Scalar(0, 0,0 ), 1);
    }
    //【5】绘制检测到的角点
    int r = 4;
    for (unsigned int i = 0; i < corners.size(); i++)
    {
        //以随机的颜色绘制出角点
        circle(copy, corners[i], r, Scalar(0,0,0), -1, 8, 0);
       
    }
    //【6】显示（更新）窗口
    imshow(WINDOW_NAME, copy);
    //【7】亚像素角点检测的参数设置
    Size winSize = Size(5, 5);
    Size zeroZone = Size(-1, -1);
    TermCriteria criteria = TermCriteria(CV_TERMCRIT_EPS + CV_TERMCRIT_ITER, 40, 0.001);
    //【8】计算出亚像素角点位置
    cornerSubPix(g_grayImage, corners, winSize, zeroZone, criteria);
    //【9】输出角点信息
    for (int i = 0; i < corners.size(); i++)
    {
        cout << "精确二维坐标[" << i << "]  (" << corners[i].x << "," << corners[i].y << ")" << endl;
    }
}
int main()
{
    g_srcImage = imread("/Users/czwstc/Desktop/标准测试图.jpg", 1);
    cvtColor(g_srcImage, g_grayImage, CV_BGR2GRAY); //转换灰度
    //【2】创建窗口
    imshow(WINDOW_NAME, g_srcImage);
    on_GoodFeaturesToTrack(0, 0);
    waitKey(0);
    return(0);
}
Point2f CrossPoint(const Vec4i  line1, const Vec4i   line2)  //计算两条直线的交点。直线由整数向量形式提供。
{
    Point2f pt;
    double k1, k2, b1, b2;
    if (line1[0] == line1[2])//如果第一条直线斜率不存在
    {
        pt.x = line1[0];
        pt.y = line2[1] == line2[3] ? line2[1] :
        double(line2[1] - line2[3])*(pt.x - line2[0]) / (line2[0] - line2[2]) + line2[1];
    }
    else if (line2[0] == line2[2])//如果第二条直线斜率不存在
    {
        pt.x = line2[0];
        pt.y = line1[1] == line1[3] ? line1[1] :
        double(line1[1] - line1[3])*(pt.x - line1[0]) / (line1[0] - line1[2]) + line1[1];
    }
    else     //求出斜截式方程。然后让k1x + b1 = k2x + b2，解出x，再算出y即可
    {
        k1 = double(line1[3] - line1[1]) / (line1[2] - line1[0]);
        b1 = double(line1[1] - k1*line1[0]);
        k2 = double(line2[3] - line2[1]) / (line2[2] - line2[0]);
        b2 = double(line2[1] - k2*line2[0]);
        pt.x = (b2 - b1) / (k1 - k2);  //算出x
        pt.y = k1* pt.x + b1; //算出y
    }
    return pt;
}
