/**
  * @file:            Source.cpp
  * @description:     Description
  * @author:          yangjun
  * @copyright (c):   2017 yangjun. All Rights Reserved
  * @date             2017/8/11 16:26
  */ 

#include <cv.h>
#include <highgui.h>

int main(int argc, char** argv)
{

	IplImage* src;
	cvNamedWindow("Example3_12_pre", CV_WINDOW_AUTOSIZE);
	cvNamedWindow("Example3_12_post", CV_WINDOW_AUTOSIZE);
	if ((src = cvLoadImage("F:\\visual studio 2017 project\\LearningOpenCV_Code\\lena\\lena.jpg", 1)) != 0)
	{
		int x = 200;
		int y = 200;
		int width = 200;
		int height = 200;
		int add = 200;
		
		cvShowImage("Example3_12_pre", src);
		cvSetImageROI(src, cvRect(x, y, width, height));
		cvAddS(src, cvScalar(add), src);

		cvResetImageROI(src);
		cvShowImage("Example3_12_post", src);
		cvWaitKey();
	}

	cvReleaseImage(&src);
	cvDestroyWindow("Example3_12_pre");
	cvDestroyWindow("Example3_12_post");
	return 0;
}