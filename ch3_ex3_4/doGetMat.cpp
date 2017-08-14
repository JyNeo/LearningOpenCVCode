/**
  * @file:            Source.cpp
  * @description:     Description
  * @author:          yangjun
  * @copyright (c):   2017 yangjun. All Rights Reserved
  * @date             2017/8/11 9:21
  */ 

#include "cv.h"
#include <stdio.h>

int main()
{
	CvMat* mat = cvCreateMat(5, 5, CV_32FC1);
	float element_3_2 = CV_MAT_ELEM(*mat, float, 3, 2);
	printf("Exercise 3_4, matrix created and accessed [3,2]=%f\n", element_3_2);
}