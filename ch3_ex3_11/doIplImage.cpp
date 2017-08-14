/**
  * @file:            Source.cpp
  * @description:     Description
  * @author:          yangjun
  * @copyright (c):   2017 yangjun. All Rights Reserved
  * @date             2017/8/11 15:57
  */ 

#include <stdio.h>
#include <cv.h>
#include <highgui.h>

void saturate_sv(IplImage* img) {

	for (int y = 0; y < img->height; y++) {
		uchar* ptr = (uchar*)(
			img->imageData + y * img->widthStep
			);
		for (int x = 0; x < img->width; x++) {
			ptr[3 * x + 1] = 255;
			ptr[3 * x + 2] = 255;
		}
	}
}

int main(int argc, char** argv)
{
	IplImage* img = cvLoadImage("F:\\visual studio 2017 project\\LearningOpenCV_Code\\lena\\lena.jpg");
	cvNamedWindow("Example3_11", CV_WINDOW_AUTOSIZE);
	saturate_sv(img);
	cvShowImage("Example3_11", img);
	cvWaitKey(0);
	cvReleaseImage(&img);
	cvDestroyWindow("Example3_11");
}