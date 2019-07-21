		#include<iostream>
        #include <stdlib.h>
		#include "opencv2/highgui/highgui.hpp"
		#include "opencv2/imgproc/imgproc.hpp"
		#include "opencv2/core/core.hpp"

		using namespace cv;
		using namespace std;


		int main()
		{
			Mat img=imread("lena.png",0);
			int th1,th2;
			th1=th2=0;
			int i,j;
			namedWindow("window",WINDOW_AUTOSIZE);
			createTrackbar("Canny","window",&th1,400);
			createTrackbar("Canny2","window",&th2,800);

			while(1)
			{
				
				Mat img1(img.rows,img.cols,CV_8UC1,Scalar(0));
				Mat img2(img.rows,img.cols,CV_8UC1,Scalar(0));
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
							img1.at<uchar>(i,j)=(img.at<uchar>(i,j))/4+(img.at<uchar>(i-1,j-1))/16+(img.at<uchar>(i-1,j))/8+(img.at<uchar>(i-1,j+1))/16+(img.at<uchar>(i,j-1))/8+(img.at<uchar>(i,j+1))/8+(img.at<uchar>(i+1,j-1))/16+(img.at<uchar>(i+1,j))/8+(img.at<uchar>(i+1,j+1))/16;
						}
					}
				}
				Canny(img1,img2,th1,th2,3);
				namedWindow("ab",WINDOW_AUTOSIZE);
				imshow("ab",img2);
				waitKey(1);				
			}
			return 0;;
		}





			
			