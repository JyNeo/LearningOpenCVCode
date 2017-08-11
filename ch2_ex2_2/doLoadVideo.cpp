/**
* @File:           ch2_ex2_2.cpp
* @Description:    Description
* @Author:         yangjun
* @Copyright (c):  yangjun. All Rights Reserved
* @Date            2017/8/10 15:08
*/

#include "highgui.h"

int main(int argc, char** argv) {
	cvNamedWindow("Example2", CV_WINDOW_AUTOSIZE);
	//CvCapture* capture = cvCaptureFromAVI( "F:\\visual studio 2017 project\\LearningOpenCV_Code\\lena\\video.mp4" ); // either one will work

	//函数cvCreateFileCapture()通过参数设置确定要读入的视频文件，返回一个指向CvCapture结构的指针
	//返回的指针所指向的CvCapture结构被初始化到对应视频文件的开头
	CvCapture* capture = cvCreateFileCapture("F:\\visual studio 2017 project\\LearningOpenCV_Code\\lena\\video.avi");
	IplImage* frame;

	while (1) {
		frame = cvQueryFrame(capture); //cvQueryFrame的参数为CvCapture结构的指针，用来将下一帧视频文件载入内存
		if (!frame)
			break;
		cvShowImage("Example2", frame); //dispaly each frame

		char c = cvWaitKey(33); //当前帧显示后，会等待33ms
		if (c == 27) //如果期间用户触发了一个按键，c会被设置成这个按键的ASCII码（ESC键：ASCII 27）
			break;
	}
	
	cvReleaseCapture(&capture);
	cvDestroyWindow("Example2");
}