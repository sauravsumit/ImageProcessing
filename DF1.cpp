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
  if(a<=0 || b<=0 || a>=img.rows-1 || b>=img.cols-1)
    return 0;
  return 1;
}

 struct dfsal
 {
  int x;
  int y;
 };

 void DFS(Mat a,Mat b, dfsal el,int * count)
 {
  stack <dfsal> q;
  q.push(el);
  b.at<uchar>(el.x,el.y)=100;
  int i,j,flag,flag1,flag2;
  dfsal f1, f2;
  while(!(q.empty()))
  {
    f1=q.top();
    flag1=1;
    for(i=f1.x-1;i<=f1.x+1;i++)
    {
      for(j=f1.y-1;j<=f1.y+1;j++)
      {
        if(Isvalid(i,j,a) && b.at<uchar>(i,j)==0)
        {
          flag1=0;
        }
      }
    }
    if(flag1)
    {
      q.pop();
      f1=q.top();
       //cout<<f1.y<< endl;
        cout<<"True"<< endl;

      if(q.empty())
        break;
    }
     
    if(Isvalid(f1.x,f1.y,a))
    {
      flag=0;
      for(i=f1.x-1;i<=f1.x+1;i++)
      {
        for(j=f1.y-1;j<=f1.y+1;j++)
        {
          if(Isvalid(i,j,a))
          {
            if(a.at<uchar>(i,j)==0 && b.at<uchar>(i,j)==0)
            {
              f2.x=i;
              f2.y=j;
              q.push(f2);
              flag=1;
              b.at<uchar>(i,j)=100;
              namedWindow("abs",WINDOW_NORMAL);
              imshow("abs",b);
              waitKey(1);
              break;
            }
          }
        }
        if(flag)
        {
          break;
        }
      }
    } 
    else
    {
      continue;
    }
    flag2=1;
    for(i=0;i<b.rows;i++)
    {
      for(j=0;j<b.cols;j++)
      {
        if(b.at<uchar>(i,j)==0)
        {
          flag2=0;
        }
      }
    }
    if(flag2)
      break;
    
  }
  *count=*count+1;
}


int main()
{
  int i,j,count;
  Mat img = imread("Binary1.png",0);
  //Mat img1(img.rows,img.cols,CV_8UC1,Scalar(0));
  for(i=0;i<img.rows;i++)
  {
    for(j=0;j<img.cols;j++)
    {
      if(img.at<uchar>(i,j)>150)
        img.at<uchar>(i,j)=255;
      else
        img.at<uchar>(i,j)=0;
    }
  }
  Mat img1=img.clone();
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
          cout<<"fgfh"<< endl;
          cout<<count<< endl;
        }
      }
    }
  }
  cout <<"No. of objects"<< endl;
  cout << count << endl;
  return 0;
}