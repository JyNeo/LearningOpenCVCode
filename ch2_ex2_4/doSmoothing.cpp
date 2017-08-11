/**
  * @file:            ch2_ex2_4.cpp
  * @description:     Description
  * @author:          yangjun
  * @copyright (c):   2017 yangjun. All Rights Reserved
  * @date             2017/8/10 16:58
  */ 

#include "cv.h"
#include "highgui.h"

void doSmoothing(IplImage* image)
{
	// Create some windows to show the input and output images in.
	cvNamedWindow("Example2_4-in", CV_WINDOW_AUTOSIZE);
	cvNamedWindow("Example2_4-out", CV_WINDOW_AUTOSIZE);

	// Create a window to show our input image
	cvShowImage("Example2_4-in", image);

	// Create an image to hold the smoothed output image
	IplImage* out = cvCreateImage(
		cvGetSize(image), //当前图像结构的大小
		IPL_DEPTH_8U, //每个像素点的数据类型
		3 //通道总数
	);

	// Do the smoothing
	cvSmooth(image, out, CV_GAUSSIAN, 5, 5);
	//cvSmooth(out, out, CV_GAUSSIAN, 5, 5);

	// Show the smoothed image in the output window
	cvShowImage("Example2_4-out", out);

	// Be tidy
	cvReleaseImage(&out);

	// Wait for the user to hit a key, then clean up the windows
	cvWaitKey(0);
	cvDestroyWindow("Example2_4-in");
	cvDestroyWindow("Example2_4-out");

}

int main(int argc, char** argv)
{
	IplImage* img = cvLoadImage("F:\\visual studio 2017 project\\LearningOpenCV_Code\\lena\\lena.jpg");
	//cvNamedWindow("Example1", CV_WINDOW_AUTOSIZE);
	//cvShowImage("Example1", img);
	doSmoothing(img);
	
	cvWaitKey(0);
	cvReleaseImage(&img);
	//cvDestroyWindow("Example1");
}