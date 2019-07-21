#include <iostream>
#include <stdlib.h>
#include <cmath>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
using namespace cv;
using namespace std;

void imgplot(int i,int j,Mat a,Mat img1)
{
	int il;
	int rad[181];
	for(il=0;il<181;il++)
	{
		rad[il]=0;
	}
	for(il=0;il<181;il++)
	{
		rad[il]=(i*cos((il*3.14159)/180)+j*sin((il*3.14159)/180));	
	}
	for(il=0;il<181;il++)
	{
		
		img1.at<uchar>((int)((img1.rows)-rad[il]),il)=img1.at<uchar>((int)((img1.rows)-rad[il]),il)+5;
	}
	
}

int main()
{
	Mat img=imread("A3.png",0);
	int i,j,k,val1,val2,q,w,max;
	int val=sqrt(img.rows*img.rows+img.cols*img.cols);
	Mat img1(val,181,CV_8UC1,Scalar(0));
	
	for(i=0;i<img.rows;i++)
	{
		for(j=0;j<img.cols;j++)
		{
			if(img.at<uchar>(i,j)==255)
			{
				imgplot(i,j,img,img1);
			}
		}
	}
	Mat img2(img1.rows,img1.cols,CV_8UC1,Scalar(0));

	for(i=0;i<img2.rows;i++)
	{
		for(j=0;j<img2.cols;j++)
		{
			/*if(i==0 ||j==0 || i==img.rows || j==img.cols)
			{
				img2.at<uchar>(i,j)=img1.at<uchar>(i,j);
			}
			else
			{
				img2.at<uchar>(i,j)=(img1.at<uchar>(i,j))/4+(img1.at<uchar>(i-1,j-1))/16+(img1.at<uchar>(i-1,j))/8+(img1.at<uchar>(i-1,j+1))/16+(img1.at<uchar>(i,j-1))/8+(img1.at<uchar>(i,j+1))/8+(img1.at<uchar>(i+1,j-1))/16+(img1.at<uchar>(i+1,j))/8+(img1.at<uchar>(i+1,j+1))/16;
			}*/
			if(img1.at<uchar>(i,j)>150)
			{
				img2.at<uchar>(i,j)=255;
			}


		}
	}

	int ar[5];
	for(i=0;i<5;i++)
	{
		ar[i]=0;
	}
	Mat img3=img2.clone();
	val1=0;val2=0;
	Mat img4(img1.rows,181,CV_8UC1,Scalar(0));
	for(i=0;i<5;i++)
	{
		max=img3.at<uchar>(0,0);
		//cout<< "max"<<endl;
		//cout<< max<<endl;
		for(j=0;j<img3.rows;j++)
		{
			for(k=0;k<img3.cols;k++)
			{
				if(max<img1.at<uchar>(j,k))
				{
					max=img3.at<uchar>(j,k);
					val1=j;
					val2=k;
					//cout<< "max found"<<endl;
					//cout<< max<<endl;
				}
			}
		}
		
		for(q=val1-25;q<=val1+25;q++)
		{
			for(w=val2-25;w<=val2+25;w++)
			{
				img3.at<uchar>(q,w)=0;
			}
		}
		img4.at<uchar>(val1,val2)=255;
		//cout<< val1<<endl;
	}


	namedWindow("ab",WINDOW_NORMAL);
	namedWindow("asb",WINDOW_NORMAL);
	namedWindow("aasb",WINDOW_NORMAL);
	namedWindow("aaasb",WINDOW_NORMAL);

	imshow("ab",img2);
	imshow("asb",img1);
	imshow("aasb",img3);
	imshow("aaasb",img4);
	waitKey(0);
}