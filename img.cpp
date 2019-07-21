#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <math.h>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
using namespace cv;
using namespace std;
int main(int argc, char** argv)
{
	VideoCapture cap(0);//open webcam also can be used to play video
	if(!cap.isOpened())
		return -1;
	while(1)
	{
		Mat img;
		
		cap>>img;
		
		imshow("Window1",img);
		waitKey(1);
	}
}