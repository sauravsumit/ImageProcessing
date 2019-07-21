#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <math.h>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
using namespace cv;
using namespace std;

int main()
{
	Mat img=imread("erosion4.png",0);
	Mat img1=img.clone();
	int i,j;

	for(i=0;i<img.rows;i++)
	{
		for(j=0;j<img.cols;j++)
		{
			if(!(i==0|| j==0 ||i==img.rows-1 ||j==img.cols-1))
			{
				if(img.at<uchar>(i-1,j-1)==0 || img.at<uchar>(i-1,j)==0 || img.at<uchar>(i-1,j+1)==0 || img.at<uchar>(i,j-1)==0 || img.at<uchar>(i,j+1)==0 ||img.at<uchar>(i+1,j-1)==0 ||img.at<uchar>(i+1,j)==0 || img.at<uchar>(i+1,j+1)==0 )
				{
					img1.at<uchar>(i,j) = 0;
				}
				else
					img1.at<uchar>(i,j) = 255;
			}
		}
	}

	Mat img2=img1.clone();

	for(i=0;i<img.rows;i++)
	{
		for(j=0;j<img.cols;j++)
		{
			if(!(i==0|| j==0 ||i==img.rows-1 ||j==img.cols-1))
			{
				if(img1.at<uchar>(i,j)==255 ||img1.at<uchar>(i-1,j-1)==255 || img1.at<uchar>(i-1,j)==255 || img1.at<uchar>(i-1,j+1)==255 || img1.at<uchar>(i,j-1)==255 || img1.at<uchar>(i,j+1)==255 ||img1.at<uchar>(i+1,j-1)==255 ||img1.at<uchar>(i+1,j)==255 || img1.at<uchar>(i+1,j+1)==255 )
				{
					img2.at<uchar>(i,j) = 255;
				}
				else
					img2.at<uchar>(i,j) = 0;
			}
		}
	}

	Mat img3=img2.clone();

	for(i=0;i<img.rows;i++)
	{
		for(j=0;j<img.cols;j++)
		{
			if(!(i==0|| j==0 ||i==img.rows-1 ||j==img.cols-1))
			{
				if(img2.at<uchar>(i,j)==255 ||img2.at<uchar>(i-1,j-1)==255 || img2.at<uchar>(i-1,j)==255 || img2.at<uchar>(i-1,j+1)==255 || img2.at<uchar>(i,j-1)==255 || img2.at<uchar>(i,j+1)==255 ||img2.at<uchar>(i+1,j-1)==255 ||img2.at<uchar>(i+1,j)==255 || img2.at<uchar>(i+1,j+1)==255 )
				{
					img3.at<uchar>(i,j) = 255;
				}
				else
					img3.at<uchar>(i,j) = 0;
			}
		}
	}


	Mat img4=img3.clone();
	for(i=0;i<img.rows;i++)
	{
		for(j=0;j<img.cols;j++)
		{
			if(!(i==0|| j==0 ||i==img.rows-1 ||j==img.cols-1))
			{
				if(img3.at<uchar>(i-1,j-1)==0 || img3.at<uchar>(i-1,j)==0 || img3.at<uchar>(i-1,j+1)==0 || img3.at<uchar>(i,j-1)==0 || img3.at<uchar>(i,j+1)==0 ||img3.at<uchar>(i+1,j-1)==0 ||img3.at<uchar>(i+1,j)==0 || img3.at<uchar>(i+1,j+1)==0 )
				{
					img4.at<uchar>(i,j) = 0;
				}
				else
					img4.at<uchar>(i,j) = 255;
			}
		}
	}


	namedWindow("ab",WINDOW_AUTOSIZE);
	imshow("ab",img4);
	waitKey(0);
	return 0;
}