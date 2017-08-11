/**
  * @file:            ch2_ex2_6.cpp
  * @description:     Description
  * @author:          yangjun
  * @copyright (c):   2017 yangjun. All Rights Reserved
  * @date             2017/8/10 18:29
  */ 

#include "cv.h"
#include "highgui.h"

IplImage* doCanny(
	IplImage* in,
	double    lowThresh,
	double    highThresh,
	double    aperture)
{
	if (in->nChannels != 1)
		return(0); //Canny only handles gray scale images
	IplImage* out = cvCreateImage(
		cvGetSize(in),
		in->depth, //IPL_DEPTH_8U,    
		1);
	cvCanny(in, out, lowThresh, highThresh, aperture);
	return(out);
};

int main(int argc, char** argv)
{
	IplImage* img_rgb = cvLoadImage("F:\\visual studio 2017 project\\LearningOpenCV_Code\\lena\\lena.jpg");
	IplImage* img_gry = cvCreateImage(cvSize(img_rgb->width, img_rgb->height), img_rgb->depth, 1);

	cvCvtColor(img_rgb, img_gry, CV_BGR2GRAY);
	
	cvNamedWindow("Example Rgb", CV_WINDOW_AUTOSIZE);
	cvNamedWindow("Example Gray", CV_WINDOW_AUTOSIZE);
	cvNamedWindow("Example Canny", CV_WINDOW_AUTOSIZE);

	cvShowImage("Example Rgb", img_rgb); //display rgb scale image
	cvShowImage("Example Gray", img_gry); //display gray scale image
	//imwrite("lena_gray.jpg", Mat(img_gry));

	IplImage* img_cny = doCanny(img_gry, 10, 100, 3);
	cvShowImage("Example Canny", img_cny);
	
	cvWaitKey(0);
	cvReleaseImage(&img_rgb);
	cvReleaseImage(&img_gry);
	cvReleaseImage(&img_cny);
	cvDestroyWindow("Example Rgb");
	cvDestroyWindow("Example Gray");
	cvDestroyWindow("Example Canny");
}