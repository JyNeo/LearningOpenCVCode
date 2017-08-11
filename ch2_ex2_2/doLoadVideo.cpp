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

	//����cvCreateFileCapture()ͨ����������ȷ��Ҫ�������Ƶ�ļ�������һ��ָ��CvCapture�ṹ��ָ��
	//���ص�ָ����ָ���CvCapture�ṹ����ʼ������Ӧ��Ƶ�ļ��Ŀ�ͷ
	CvCapture* capture = cvCreateFileCapture("F:\\visual studio 2017 project\\LearningOpenCV_Code\\lena\\video.avi");
	IplImage* frame;

	while (1) {
		frame = cvQueryFrame(capture); //cvQueryFrame�Ĳ���ΪCvCapture�ṹ��ָ�룬��������һ֡��Ƶ�ļ������ڴ�
		if (!frame)
			break;
		cvShowImage("Example2", frame); //dispaly each frame

		char c = cvWaitKey(33); //��ǰ֡��ʾ�󣬻�ȴ�33ms
		if (c == 27) //����ڼ��û�������һ��������c�ᱻ���ó����������ASCII�루ESC����ASCII 27��
			break;
	}
	
	cvReleaseCapture(&capture);
	cvDestroyWindow("Example2");
}