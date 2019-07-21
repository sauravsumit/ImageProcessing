# include "opencv2/highgui/highgui.hpp"
# include "opencv2/core/core.hpp"
# include "opencv2/imgproc/imgproc.hpp"
# include <iostream>
using namespace cv;
using namespace std;
int main()
{
	int max=0,count[256],i,j,x,width=2,height=4;

	//initialise all elements of array count to 0
	for(i=0;i<256;i++)
	{
		count[i]=0;
	}

	//Read image
	Mat img=imread("joker.jpg",0);
	
	//Traversing rows
	for (i=0;i<img.rows;i++)
	{
		//traversing columns
		for (j=0;j<img.cols;j++)
		{
			//reading the intensity at a pixel and raising the count of that array element by 1
			x=img.at<uchar>(i,j);
			count[x]++;
		}
	}

	//reducing height
	for(i=0;i<256;i++)
	{
		count[i]=count[i]/height;
	}

	//getting the max count
	for(i=0;i<256;i++)
	{
		if (count[i]>max)
			max=count[i];
	}

	//creating a mat
	Mat hist(1.1*max,256*width,CV_8UC1,Scalar(0));
	//Traversing columns
	for(j=0;j<256*width;j++)
	{
		//Traversing rows
		for(i=0;i<(1.1*max);i++)
		{
			//poltting intensity
			if((1.1*max-i)>count[j/width])
				hist.at<uchar>(i,j)=255;
			else
				hist.at<uchar>(i,j)=0;
		}
	}

	//Showing image
	namedWindow("Histogram",WINDOW_NORMAL);
	imshow("Histogram",hist);
	waitKey(0);

	return 0;
}