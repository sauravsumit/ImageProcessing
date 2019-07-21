#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <math.h>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
using namespace cv;
using namespace std;
int main(int argc, char** argv)
{
	VideoCapture cap(0);//open webcam also can be used to play video
	if(!cap.isOpened())
		return -1;
	while(1)
	{
		Mat img;
		
		cap>>img;
		//GaussianBlur( img, img1, Size( 200,200 ), 0, 0 );
		Mat img1(img.rows,img.cols,CV_8UC1,Scalar(0));
			int i,j;
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
						img1.at<uchar>(i,j)=((img.at<uchar>(i,j))+(img.at<uchar>(i-1,j-1))+(img.at<uchar>(i-1,j))+(img.at<uchar>(i-1,j+1))+(img.at<uchar>(i,j-1))+(img.at<uchar>(i,j+1))+(img.at<uchar>(i+1,j-1))+(img.at<uchar>(i+1,j))+(img.at<uchar>(i+1,j+1)))/9;
					}
				}
			}
			Mat img2(img.rows,img.cols,CV_8UC1,Scalar(0));

		Canny(img1,img2,20,90,3);
		imshow("Window1",img2);
		waitKey(1);
	}
}