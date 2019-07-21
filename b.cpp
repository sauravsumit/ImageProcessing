#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stack>
using namespace std;
using namespace cv;
#define col 0
struct point
{
    int x,y;
};
int isvalid(int x,int y,int rows,int cols)
{
    if(x<0||y<0||x>=rows||y>=cols)
   	 return 0;
    return 1;
}

int main()
{
Mat img=imread("A1.png",0);
int i,j,th=128,k,f,l;
for(i=0;i<img.rows;++i)
    for(j=0;j<img.cols;++j)
   	 if(img.at<uchar>(i,j)>th)
   		 img.at<uchar>(i,j)=255;
   	 else
   		 img.at<uchar>(i,j)=0;
Mat a=img.clone();
int ker=2    ;
int diagonal = sqrt(img.rows*img.rows+img.cols*img.cols);
Mat h(2*diagonal,180,CV_8UC1,Scalar(0));
Mat bin(2*diagonal,180,CV_8UC1,Scalar(0));
for(int i=0;i<img.rows;++i)
   	 for(int j=0;j<img.cols;++j)
   	 {
   		 if(img.at<uchar>(i,j)==255)
   		 {
   			 float p;
   			 for(int k=0;k<180;++k)
   			 {
   			 p= i*cos(k*3.14/180)+ j*sin(k*3.14/180);
   				 if(h.at<uchar>(diagonal-p,k)<250)
   					 h.at<uchar>(diagonal-p,k)+=3;
   			 }    
   		 }
   	 }

    namedWindow("rq",WINDOW_NORMAL);
   
    
    imshow("rq",h);  	 

    waitKey(0);
}
