#include <iostream>
#include <stdlib.h>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
using namespace cv;
using namespace std;
int main()
{
	Mat img1=imread("fruits.png",1);
	Mat img(img1.rows/2,img1.cols/2,CV_8UC3,Scalar(255,255,255));
	int a,b,i,j;
	a=0;
	for(i=0;i<img1.rows-1;i+=2)
	{
		b=0;
		for(j=0;j<img1.cols-1;j+=2)
		{
			img.at<Vec3b>(a,b)[0]=(img1.at<Vec3b>(i,j)[0]+img1.at<Vec3b>(i+1,j)[0]+img1.at<Vec3b>(i,j+1)[0]+img1.at<Vec3b>(i+1,j+1)[0])/4;
			img.at<Vec3b>(a,b)[1]=(img1.at<Vec3b>(i,j)[1]+img1.at<Vec3b>(i+1,j)[1]+img1.at<Vec3b>(i,j+1)[1]+img1.at<Vec3b>(i+1,j+1)[1])/4;
			img.at<Vec3b>(a,b)[2]=(img1.at<Vec3b>(i,j)[2]+img1.at<Vec3b>(i+1,j)[2]+img1.at<Vec3b>(i,j+1)[2]+img1.at<Vec3b>(i+1,j+1)[2])/4;
			b++;
		}
		a++;
	}
	namedWindow("ab",WINDOW_NORMAL);
	imshow("ab",img);
	waitKey(0);
	return 0;
}
