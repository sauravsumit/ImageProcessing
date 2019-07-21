#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
using namespace cv;
using namespace std;

int main()
{
	Mat a(1000,1000,CV_8UC3, Scalar(255,0,0));
	int x=a.at<Vec3b>(2,5)[0];
	namedWindow("window1",WINDOW_NORMAL);
	imshow("window1",a);
	waitKey(0);
}