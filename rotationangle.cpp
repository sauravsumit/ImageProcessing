#include <iostream>
#include <stdlib.h>
#include <math.h>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
using namespace cv;
using namespace std;
int main()
{
	Mat img=imread("fruits.png",1);
	Mat img1(img.rows*3,img.cols*3,CV_8UC3,Scalar(255,255,255));
	int a,b,i,j,t;
	cin >> t;
	const double PI  =3.14159;
	for(i=0;i<img.rows;i++)
	{
		for(j=0;j<img.cols;j++)
		{
			a=cos((t*PI)/180)*(i-img.rows/2)+sin((t*PI)/180)*(j-img.cols/2)+img.rows*1.5;
			b=cos((t*PI)/180)*(j-img.cols/2)-sin((t*PI)/180)*(i-img.rows/2)+img.cols*1.5;;
			img1.at<Vec3b>(a,b)[0]=img.at<Vec3b>(i,j)[0];
			img1.at<Vec3b>(a,b)[1]=img.at<Vec3b>(i,j)[1];
			img1.at<Vec3b>(a,b)[2]=img.at<Vec3b>(i,j)[2];
		}
		
	}
	namedWindow("ab",WINDOW_NORMAL);
	imshow("ab",img1);
	waitKey(0);
	return 0;
}
