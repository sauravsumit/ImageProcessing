#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include <iostream>
#include <algorithm>
using namespace cv;
using namespace std;
int mean(int a, int b, Mat c)
 { int sum=0;
    int z[9]={0,0,0,0,0,0,0,0,0};
    int y=0;
   
   for(int i=a-1; i<(a+2); i++)
     {
      for(int j=b-1; j <(b+2); j++)
       {  
          z[y]=c.at<uchar>(i,j);
          y++;
        }
       }
      sort(z,z+9);
    return (z[4]); 
 } 
int main()
 { 
  int sum=0;
  Mat a=imread("veg.jpg",0);
  Mat b=imread("veg.jpg",0);
  for(int i=1; i<(a.rows-1); i++)
    {
      for(int j=1; j<(a.cols-1); j++)
	{ 
          
          b.at<uchar>(i,j)=mean(i,j,a);
         }
     }
    
   imshow("Image",b);
   imshow("Image1",a);
   waitKey(0);
  return 0;
 }
