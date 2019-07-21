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
	
	int arr[256];
	int i,j,x,max;
	for(i=0;i<256;i++)
	{
		arr[i]=0;
	}

	for(i=0;i<img.rows;i++)
	{
		for(j=0;j<img.cols;j++)
		{
			x=img.at<Vec3b>(i,j)[2];
			arr[x]=arr[x]+1;
		}
	}
	for(i=0;i<256;i++)
	{
		arr[i]=arr[i]/300;
	}

	max=arr[0];
	for(i=1;i<256;i++)
	{
		if(max<arr[i])
		{
			max=arr[i];
		}
	}
	cout<<max<<endl;

	Mat img1(max+20,256,CV_8UC1,Scalar(255));

	for(i=0;i<256;i++)
	 {
	 	for(j=img1.rows-1;j>=(img1.rows-1-arr[i]);j--)
	 	{
	 		img1.at<uchar>(j,i)=0;
	 	}
	 }

	cout<<img1.at<uchar>(0,1008)<<endl;
	namedWindow("ab",WINDOW_NORMAL);
	imshow("ab",img1);
	waitKey(0);
	return 0;

}

