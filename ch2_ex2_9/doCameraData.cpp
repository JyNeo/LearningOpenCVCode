/**
  * @file:            Source.cpp
  * @description:     Description
  * @author:          yangjun
  * @copyright (c):   2017 yangjun. All Rights Reserved
  * @date             2017/8/10 19:58
  */ 

#include "cv.h"
#include "highgui.h"

int main(int argc, char** argv) {
	cvNamedWindow("Example2_9", CV_WINDOW_AUTOSIZE);
	CvCapture* capture;
	if (argc == 1) {
		capture = cvCreateCameraCapture(0);
		printf("what the fuck\n");
	}
	else {
		capture = cvCreateFileCapture("F:\\visual studio 2017 project\\LearningOpenCV_Code\\lena\\video.avi");
	}
	//assert(capture != NULL);

	IplImage* frame;
	while (1) {
		frame = cvQueryFrame(capture);
		if (!frame) break;
		cvShowImage("Example2_9", frame);

		char c = cvWaitKey(10);
		if (c == 27) break;
	}

	cvReleaseCapture(&capture);
	cvDestroyWindow("Example2_9");
}