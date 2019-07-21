#include <iostream>
#include <stdlib.h>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
using namespace cv;
using namespace std;
int main()
{
    int i,j,th;
    th=0;
    namedWindow("ab",WINDOW_NORMAL);
	createTrackbar("intensityFilter","ab",&th,255);
	Mat img=imread("fruits.png",0);
	
	while(1)
	{
		Mat img1=img.clone();
		for(i=0;i<img.rows;i++)
		{
			for(j=0;j<img.cols;j++)
			{
				if(img.at<uchar>(i,j)>th)
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
		waitKey(1);
	}
	return 0;
}