#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <queue>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
using namespace cv;
using namespace std;

int Notempty(int a, int b, Mat img)
{
	if(a==0 || b==0 || a==img.rows-1 || b==img.cols-1)
		return 0;
	return 1;
}

 struct bfsal
 {
 	int x;
 	int y;
 };

 void BFS(Mat a, bfsal el, int * incr)
 {
 	queue <bfsal> q;
 	q.push(el);

 	int i,j;
 	bfsal f1, f2;
 	while(!(q.empty()))
 	{
 		f1=q.front();
 		
 		q.pop();
 		

 		for(i=f1.x-1;i<=f1.x+1;i++)
 		{
 			for(j=f1.y-1;j<=f1.y+1;j++)
 			{
 				if(Notempty(i,j,a))
 				{
 					if(a.at<uchar>(i,j)==255)
 				    {
 						f2.x=i;
 						f2.y=j;
 						q.push(f2);
 						a.at<uchar>(i,j)=0;
 					}
 				}
 			}
 		}
 	}
 	*incr=*incr+1;
 }

int main()
{
	int i,j,count;
	Mat img = imread("Binary1.png",0);
	//Mat img1(img.rows,img.cols,CV_8UC1,Scalar(0));
	bfsal t;
	count=0;
	for(i=0;i<img.rows;i++)
	{
		for(j=0;j<img.cols;j++)
		{
			if(Notempty(i,j,img))
			{
				if(img.at<uchar>(i,j)==255)
				{
					t.x=i;
					t.y=j;
					BFS(img,t,&count);
				}
			}
		}
	}
	cout << count << endl;
	return 0;
}