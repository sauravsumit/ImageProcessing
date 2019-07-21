		#include<iostream>
        #include <stdlib.h>
		#include "opencv2/highgui/highgui.hpp"
		#include "opencv2/imgproc/imgproc.hpp"
		#include "opencv2/core/core.hpp"

		using namespace cv;
		using namespace std;


		int main()
		{
			Mat img=imread("veg.jpg",0);
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

			namedWindow("ab",WINDOW_AUTOSIZE);
			imshow("ab",img1);
			waitKey(0);
			return 0;
		}