#include<opencv2\opencv.hpp>
#include<iostream>
using namespace cv;
using namespace std;
int main()
{
	Mat picture = imread("wallpaper.jpg");//ͼƬ������ӵ�����Ŀ¼��
										  //Ҳ���Ǻ�test.cpp�ļ�����һ���ļ����£�����
	imshow("���Գ���", picture);
	waitKey(20150901);
	cout << "push to github again" << endl;
}