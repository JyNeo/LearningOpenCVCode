/**
  * @file:            Source.cpp
  * @description:     Description
  * @author:          yangjun
  * @copyright (c):   2017 yangjun. All Rights Reserved
  * @date             2017/8/11 17:24
  */ 

#include <cv.h>
#include <highgui.h>
#include <stdio.h>

int main(int argc, char** argv)
{
	IplImage *src1, *src2;
	if ((src1 = cvLoadImage("F:\\visual studio 2017 project\\LearningOpenCV_Code\\lena\\lena.jpg", 1)) != 0 
		&& ((src2 = cvLoadImage("F:\\visual studio 2017 project\\LearningOpenCV_Code\\lena\\lena_gray.jpg", 1)) != 0))
	{
		int x = 200;// atoi(argv[3]);
		int y = 200;// atoi(argv[4]);
		int width = 200;// atoi(argv[5]);
		int height = 200;// atoi(argv[6]);
		double alpha = 0.4;// (double)atof(argv[7]);
		double beta = 0.6;//(double)atof(argv[8]);

		cvSetImageROI(src1, cvRect(x, y, width, height));
		cvSetImageROI(src2, cvRect(0, 0, width, height));
		cvAddWeighted(src1, alpha, src2, beta, 0.0, src1);

		cvResetImageROI(src1);
		cvNamedWindow("Alpha_blend", 1);
		cvShowImage("Alpha_blend", src1);
		cvWaitKey();
	}
	else
		printf("Couldn't load one or both of %s, %s\n", argv[1], argv[2]);
	return 0;
}