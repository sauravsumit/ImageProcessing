#include <iostream>
#include <stdlib.h>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
using namespace cv;
using namespace std;
int main()
{
	Mat img=imread("fruits.png",1);
	Mat img1(img.rows,img.cols*2,CV_8UC3,Scalar(255,255,255));
	int a,b,i,j;
	for(i=0;i<img1.rows;i++)
	{
		b=0;
		for(j=0;j<img1.cols;j++)
		{
			if(j<img.cols)
			{
				img1.at<Vec3b> (i,j)[0]=img.at<Vec3b>(i,j)[0];
			    img1.at<Vec3b> (i,j)[1]=img.at<Vec3b>(i,j)[1];
				img1.at<Vec3b> (i,j)[2]=img.at<Vec3b>(i,j)[2];
			}
			else
			{
				img1.at<Vec3b> (i,j)[0]=img.at<Vec3b>(i,img1.cols-1-j)[0];
			    img1.at<Vec3b> (i,j)[1]=img.at<Vec3b>(i,img1.cols-1-j)[1];
				img1.at<Vec3b> (i,j)[2]=img.at<Vec3b>(i,img1.cols-1-j)[2];	
			}
			b++;
		}
		
	}
	namedWindow("ab",WINDOW_NORMAL);
	imshow("ab",img1);
	waitKey(0);
	return 0;
}
