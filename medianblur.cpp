#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <math.h>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
using namespace cv;
using namespace std;
int medianfind(int a, int b, int c, int d, int e, int f, int g, int h, int i)
{
	int il,j,max,temp,count;
	int arr[9];
	arr[0]=a;
	arr[1]=b;
	arr[2]=c;
	arr[3]=d;
	arr[4]=e;
	arr[5]=f;
	arr[6]=g;
	arr[7]=h;
	arr[8]=i;
	count=0;
	sort(arr,arr+9);
	/*for(il=0;il<9;il++)
	{
		max=arr[il];
		for(j=i;j<9;j++)
		{
			if(max<arr[j])
				{
					count=j;
					max=arr[j];
				}
		}
		temp=arr[il];
		arr[il]=arr[count];
		arr[count]=temp;
	}*/
	return arr[4];
}

int main()
{
	Mat img=imread("veg.jpg",0);
    Mat img1= img.clone();
	int i,j,x;
	for(i=0;i<img.rows;i++)
	{
		for(j=0;j<img.cols;j++)
		{
			if(i==0||j==0||i==img.rows-1||j==img.cols-1)
			{
				img1.at<uchar>(i,j)=img.at<uchar>(i,j);
			}
			else
			{
				x=medianfind(img.at<uchar>(i,j),img.at<uchar>(i-1,j-1),img.at<uchar>(i-1,j),img.at<uchar>(i-1,j+1),img.at<uchar>(i,j-1),img.at<uchar>(i,j+1),img.at<uchar>(i+1,j-1),img.at<uchar>(i+1,j),img.at<uchar>(i+1,j+1));
				img1.at<uchar>(i,j)=x;
			}
		}
	}
	namedWindow("ab",WINDOW_AUTOSIZE);
	imshow("ab",img1);
	waitKey(0);
	return 0;
}

