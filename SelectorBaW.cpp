#include <iostream>
#include <stdlib.h>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
using namespace cv;
using namespace std;
int main()
{
	int i,j;
	Mat img=imread("fruits.png",0);
	Mat img1(img.rows,img.cols,CV_8UC1,Scalar(0));
	for(i=0;i<img.rows;i++)
	{
		for(j=0;j<img.cols;j++)
		{
			if(img.at<uchar>(i,j)>152)
			{
				img1.at<uchar>(i,j)=0;
			}
			else
			{
				img1.at<uchar>(i,j)=255;
			}
		}
	}
	imshow("ab",img1);
	waitKey(0);
	return 0;
}