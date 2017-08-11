/**
  * @file:            ch2_ex2_3.cpp
  * @description:     Description
  * @author:          yangjun
  * @copyright (c):   2017 yangjun. All Rights Reserved
  * @date             2017/8/10 15:29
  */  

#include <stdio.h>
#include "cv.h"
#include "highgui.h"

using namespace std;

int        g_slider_position = 0;
CvCapture* g_capture = NULL;

void onTrackbarSlide(int position) {
	cvSetCaptureProperty(
		g_capture,
		CV_CAP_PROP_POS_FRAMES,
		position
	);
}

int main(int argc, char** argv) {

	cvNamedWindow("Example2_3", CV_WINDOW_AUTOSIZE);
	g_capture = cvCreateFileCapture("F:\\visual studio 2017 project\\LearningOpenCV_Code\\lena\\video.avi");

	int frames = (int)cvGetCaptureProperty(
		g_capture,
		CV_CAP_PROP_FRAME_COUNT
	);

	int tmpw = (int)cvGetCaptureProperty(
		g_capture,
		CV_CAP_PROP_FRAME_WIDTH
	);

	int tmph = (int)cvGetCaptureProperty(
		g_capture,
		CV_CAP_PROP_FRAME_HEIGHT
	);

	printf("opencv frames %d w %d h %d\n", frames, tmpw, tmph);

	cvCreateTrackbar(
		"trackbar", //trackbar名称
		"Example2_3", //绑定的窗口名称
		&g_slider_position, //滑块位置
		frames, //总帧数
		onTrackbarSlide //回调函数
	);

	IplImage* frame;
	frames = 0;
	while (1) {
		frame = cvQueryFrame(g_capture);
		if (!frame) break;
		//int frames = cvGetCaptureProperty( g_capture, CV_CAP_PROP_POS_FRAMES);
		frames++;

		cvSetTrackbarPos("trackbar", "Example2_3", frames);
		cvShowImage("Example2_3", frame);

		char c = (char)cvWaitKey(10);
		if (c == 27) break;
	}

	cvReleaseCapture(&g_capture);
	cvDestroyWindow("Example2_3");
	return(0);
}