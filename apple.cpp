

#include <iostream>
#include <stdlib.h>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
using namespace cv;
using namespace std;
int main()
{
    int i,j,th1,th2,th3,th4,th5,th6;
    th1=0;th2=0;th3=0;th4=0;th5=0;th6=0;
    namedWindow("ab",WINDOW_NORMAL);
	createTrackbar("BlueMin","ab",&th1,255);
	createTrackbar("BlueMax","ab",&th2,255);
    createTrackbar("GreenMin","ab",&th3,255);
    createTrackbar("GreenMax","ab",&th4,255);
    createTrackbar("RedMin","ab",&th5,255);
    createTrackbar("RedMax","ab",&th6,255);

	Mat img=imread("fruits.png",1);
	
	while(1)
	{
		Mat img1=img.clone();
		for(i=0;i<img.rows;i++)
		{
			for(j=0;j<img.cols;j++)
			{
				if(img.at<Vec3b>(i,j)[0]>th1 && img.at<Vec3b>(i,j)[0]<th2 && img.at<Vec3b>(i,j)[1]>th3 && img.at<Vec3b>(i,j)[1]<th4 && img.at<Vec3b>(i,j)[2]>th5 && img.at<Vec3b>(i,j)[0]<th6)
				{
					img1.at<Vec3b>(i,j)[0]=img.at<Vec3b>(i,j)[0];
					img1.at<Vec3b>(i,j)[1]=img.at<Vec3b>(i,j)[1];
					img1.at<Vec3b>(i,j)[2]=img.at<Vec3b>(i,j)[2];
				}
				else
				{
					img1.at<Vec3b>(i,j)[0]=255;
					img1.at<Vec3b>(i,j)[1]=255;
					img1.at<Vec3b>(i,j)[2]=255;
				}
	        }
		}
		
		imshow("ab",img1);
		waitKey(1);
	}
	return 0;
}