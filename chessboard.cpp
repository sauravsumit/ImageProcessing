#include <iostream>
#include <stdlib.h>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
using namespace cv;
using namespace std;
int main()
{
	Mat a(320,320,CV_8UC3,Scalar(0,0,0));
	for(int i=0;i<320;i++)
	{
		for(int j=0;j<320;j++)
		{
           if((i/40)%2==0)
           	{
           		if((j/40)%2==0)
           		{
           			a.at<Vec3b>(i,j)[0]=255;
                    a.at<Vec3b>(i,j)[1]=255;
                    a.at<Vec3b>(i,j)[2]=255; 
           		}
           	}
            if((i/40)%2!=0)
           	{
           		if((j/40)%2!=0)
                 {
                 	a.at<Vec3b>(i,j)[0]=255;
                    a.at<Vec3b>(i,j)[1]=255;
                    a.at<Vec3b>(i,j)[2]=255; 
                 }
           		
           	}
        }
	}
	imshow("ab",a);
	waitKey(0);
	return 0;
}