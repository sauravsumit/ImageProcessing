#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <stack>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
using namespace cv;
using namespace std;

int Isvalid(int a, int b, Mat img)
{
	if(a==0 || b==0 || a==img.rows-1 || b==img.cols-1)
		return 0;
	return 1;
}

 struct dfsal
 {
 	int x;
 	int y;
 };

 void DFS(Mat a,Mat b, dfsal el,int *count)
 {
 	stack <dfsal> q;
 	q.push(el);
 	b.at<uchar>(el.x,el.y)=100;
 	int i,j;
 	dfsal f1, f2;
 	while(!(q.empty()))
 	{
 		f1=q.top();	
 		if(Isvalid(f1.x,f1.y,a))
 		{
	 		for(i=f1.x;i<=f1.x+1;i++)
	 		{
	 			for(j=f1.y;j<=f1.y+1;j++)
	 			{
	 				
	 					if((a.at<uchar>(i,j)==0 && b.at<uchar>(i,j)==0))
	 				    {
	 						f2.x=i;
	 						f2.y=j;
	 						q.push(f2);
	 						b.at<uchar>(i,j)=80;
	 						f2=q.top();
	 						
	 						namedWindow("abs",WINDOW_NORMAL);
		                    imshow("abs",b);
	                     	waitKey(1);

	                     	if(Isvalid(f2.x,f2.y,a))
	                     	{
	                     		DFS(a,b,f2,count);
	                     	}
	                     	else
	                     	{
	                     		q.pop();
	                     	}
	 					}
	 					else
	 						continue;
	 			}
	 		}
	 		 q.pop();  

 	    }
 	   
      
    }
    *count++;
   cout << *count +"is the initials" << endl;
}
int main()
{
	int i,j,count;
	Mat img = imread("ii.png",0);
	//Mat img1(img.rows,img.cols,CV_8UC1,Scalar(0));
	Mat img1=img.clone();
	cout <<img.cols << endl;
	cout <<img.rows << endl;
	dfsal t;
	count=0;
	for(i=0;i<img.rows;i++)
	{
		for(j=0;j<img.cols;j++)
		{
			if(Isvalid(i,j,img))
			{
				if(img.at<uchar>(i,j)==0 && img1.at<uchar>(i,j)==0)
				{
					t.x=i;
					t.y=j;
					DFS(img,img1,t,&count);
					cout << count<< endl;
				}
			}
		}
		cout << count << endl;
	}
cout << count << endl;
	return 0;
}