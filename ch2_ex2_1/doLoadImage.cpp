//Alt + 方向上下键: 可上下移动光标所在代码行，也可选中代码段后成块的移动代码行；
//Alt + →: 调用智能提示;
//Alt + .: 取消当前行注释;
//Ctl + /: 注释当前行;
//Ctrl + Enter: 在当前行的上面插入一个空行;


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