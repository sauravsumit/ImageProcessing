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
	int i,j,th1,th2,th3,t,m,eva;
	int sxc,syc,nope;
	int sobx[9]={-1,0,1,-2,0,2,-1,0,1};
	int soby[9]={-1,-2,1,0,0,0,1,2,1};
	Mat img=imread("rubik.jpg",0);
		Mat img1=img.clone();
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
					sxc=0;
					nope=0;
					for(t=i-1;t<=i+1;t++)
					{
						for(m=j-1;m<=j+1;m++)
						{
							sxc+=img.at<uchar>(t,m)*sobx[nope];
							syc+=img.at<uchar>(t,m)*soby[nope];
							nope++;
						}
					}
					eva=sqrt(sxc*sxc+syc*syc);
					if(eva>111)
					{
						img1.at<uchar>(i,j)=0;
					}
					else
						img1.at<uchar>(i,j)=255;
				}

			}
		}
	    imshow("Window1",img1);
	    waitKey(0);
		return 0;
}