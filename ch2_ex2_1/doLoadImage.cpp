//Alt + �������¼�: �������ƶ�������ڴ����У�Ҳ��ѡ�д���κ�ɿ���ƶ������У�
//Alt + ��: ����������ʾ;
//Alt + .: ȡ����ǰ��ע��;
//Ctl + /: ע�͵�ǰ��;
//Ctrl + Enter: �ڵ�ǰ�е��������һ������;


#include "highgui.h"

int main(int argc, char** argv)
{
	IplImage* img = cvLoadImage("F:\\visual studio 2017 project\\LearningOpenCV_Code\\lena\\lena.jpg");

	cvNamedWindow("Example1", CV_WINDOW_AUTOSIZE);
	cvShowImage("Example1", img);

	cvWaitKey(0);

	cvReleaseImage(&img);
	cvDestroyWindow("Example1");

	return 0;
}