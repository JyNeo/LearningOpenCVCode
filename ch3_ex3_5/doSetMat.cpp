/**
  * @file:            Source.cpp
  * @description:     Description
  * @author:          yangjun
  * @copyright (c):   2017 yangjun. All Rights Reserved
  * @date             2017/8/11 9:26
  */ 

#include "cv.h"
#include <stdio.h>

int main()
{
	CvMat* mat = cvCreateMat(5, 5, CV_32FC1);
	float element_3_2 = 7.7;
	*((float*)CV_MAT_ELEM_PTR(*mat, 3, 2)) = element_3_2;

	// below from example ch3_ex3_8.txt
	cvmSet(mat, 2, 2, 0.5000);
	cvSetReal2D(mat, 3, 3, 0.3300);

	printf("Exercise 3_5, matrix created and accessed [3,2]=%f, [2,2]=%f, [3,3]=%f\n", 
		CV_MAT_ELEM(*mat, float, 3, 2), 
		CV_MAT_ELEM(*mat, float, 2, 2), 
		CV_MAT_ELEM(*mat, float, 3, 3));


}