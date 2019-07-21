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
	Mat img=imread("fruits.png",1);
  Mat img2=imread("fruits.png",0);
  Mat a(img.rows,img.cols,CV_8UC1,Scalar(0));
  Mat b(img.rows,img.cols,CV_8UC1,Scalar(0));

	for(int i=0;i<img.rows;i++)
	{
		for(int j=0;j<img.cols;j++)
		{
       a.at<uchar>(i,j)= (0.114*img.at<Vec3b>(i,j)[0]) + (0.587*img.at<Vec3b>(i,j)[1]) + (0.299*img.at<Vec3b>(i,j)[0]);
        b.at<uchar>(i,j)= ((img.at<Vec3b>(i,j)[0]) + (img.at<Vec3b>(i,j)[1]) + (img.at<Vec3b>(i,j)[0]))/3;
    }
	}
	imshow("ab",a);
	waitKey(0);
  imshow("abc",b);
  waitKey(0);
	return 0;
}