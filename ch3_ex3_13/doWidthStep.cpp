/**
  * @file:            doWidthStep.cpp
  * @description:     Description
  * @author:          yangjun
  * @copyright (c):   2017 yangjun. All Rights Reserved
  * @date             2017/8/11 16:47
  */ 

#include <cv.h>
#include <highgui.h>

int main(int argc, char** argv)
{
	IplImage* interest_img;
	CvRect interest_rect;
	if ((interest_img = cvLoadImage("F:\\visual studio 2017 project\\LearningOpenCV_Code\\lena\\lena.jpg", 1)) != 0)
	{
		interest_rect.x = 200;
		interest_rect.y = 200;
		interest_rect.width = 200;
		interest_rect.height = 200;
		int add = 200;

		IplImage *sub_img = cvCreateImageHeader(
			cvSize(
				interest_rect.width,
				interest_rect.height
			),
			interest_img->depth,
			interest_img->nChannels
		);

		sub_img->origin = interest_img->origin;

		sub_img->widthStep = interest_img->widthStep;

		sub_img->imageData = interest_img->imageData +
			interest_rect.y * interest_img->widthStep +
			interest_rect.x * interest_img->nChannels;

		cvAddS(sub_img, cvScalar(add), sub_img);

		cvReleaseImageHeader(&sub_img);

		cvNamedWindow("Roi_Add", CV_WINDOW_AUTOSIZE);
		cvShowImage("Roi_Add", interest_img);
		cvWaitKey();
	}
	return 0;
}