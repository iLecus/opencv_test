#include<opencv2\opencv.hpp>
#include<iostream>
using namespace cv;
using namespace std;

//全局变量声明
Mat g_srcImage, g_dstImage1, g_dstImage2, g_dstImage3, g_dstImage4, g_dstImage5;
int g_nBoxFilterValue = 6; //方框滤波内核值
int g_nMeanBlurValue = 10; //均值滤波内核值
int g_nGaussianBlurValue = 6; //高斯滤波内核值
int g_nMedianBlurValue = 10; //中值滤波内核值
int g_nBilateralFilterValue = 10; //双边滤波内核值

//全局函数声明,轨迹条回归函数
static void on_BoxFilter(int, void*);
static void on_MeanBlur(int, void*);
static void on_GaussianBlur(int, void*);
static void on_MedianBlur(int, void*);
static void on_BilateralFilter(int, void*);


int main()
{
	system("color 5E");
	g_srcImage = imread("wallpaper.jpg");
	if (!g_srcImage.data) { cout << "读取srcImage错误！" << endl; return false; }
	g_dstImage1 = g_srcImage.clone();
	g_dstImage2 = g_srcImage.clone();
	g_dstImage3 = g_srcImage.clone();
	g_dstImage4 = g_srcImage.clone();
	g_dstImage5 = g_srcImage.clone();

	namedWindow("【<0>原图窗口】", 1);
	imshow("【<0>原图窗口】", g_srcImage);

	//方框滤波
	namedWindow("【<1>方框滤波】", 1);
	//创建轨迹条
	createTrackbar("内核值：", "【<1>方框滤波】", &g_nBoxFilterValue, 50, on_BoxFilter);
	on_BoxFilter(g_nBoxFilterValue, 0);
	imshow("【<1>方框滤波】", g_dstImage1);

	//均值滤波
	namedWindow("【<2>均值滤波】", 1);
	createTrackbar("内核值：", "【<2>均值滤波】", &g_nMeanBlurValue, 50, on_MeanBlur);
	on_MeanBlur(g_nMeanBlurValue, 0);

	//高斯滤波
	namedWindow("【<3>高斯滤波】");
	createTrackbar("内核值：", "【<3>高斯滤波】", &g_nGaussianBlurValue, 50, on_GaussianBlur);
	on_GaussianBlur(g_nGaussianBlurValue, 0);

	//中值滤波
	namedWindow("【<4>中值滤波】");
	createTrackbar("内核值：", "【<4>中值滤波】", &g_nMedianBlurValue, 50, on_MedianBlur);
	on_MedianBlur(g_nMedianBlurValue, 0);

	//双边滤波
	namedWindow("【<5>双边滤波】");
	createTrackbar("内核值：", "【<5>双边滤波】", &g_nBilateralFilterValue, 50, on_BilateralFilter);
	on_BilateralFilter(g_nBilateralFilterValue, 0);

	while (char(waitKey(1) != 'q')) {};
	return 0;
}

	//回调函数
	static void on_BoxFilter(int, void*)
	{
		boxFilter(g_srcImage, g_dstImage1, -1, Size(g_nBoxFilterValue + 1, g_nBoxFilterValue + 1));
		imshow("【<1>方框滤波】", g_dstImage1);
	}

	static void on_MeanBlur(int, void*)
	{
		blur(g_srcImage, g_dstImage2, Size(g_nMeanBlurValue + 1, g_nMeanBlurValue + 1), Point(-1, -1));
		imshow("【<2>均值滤波】", g_dstImage2);
	}

	static void on_GaussianBlur(int, void*)
	{
		GaussianBlur(g_srcImage, g_dstImage3, Size(g_nGaussianBlurValue * 2 + 1, g_nGaussianBlurValue * 2 + 1), 0, 0);
		imshow("【<3>高斯滤波】", g_dstImage3);
	}

	static void on_MedianBlur(int, void*)
	{
		medianBlur(g_srcImage, g_dstImage4, g_nMedianBlurValue * 2 + 1);
		imshow("【<4>中值滤波】", g_dstImage4);
	}

	static void on_BilateralFilter(int, void*)
	{
		bilateralFilter(g_srcImage, g_dstImage5, g_nBilateralFilterValue, g_nBilateralFilterValue * 2, g_nBilateralFilterValue / 2);
		imshow("【<5>双边滤波】", g_dstImage5);
	}