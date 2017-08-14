/**
  * @file:            Source.cpp
  * @description:     Description
  * @author:          yangjun
  * @copyright (c):   2017 yangjun. All Rights Reserved
  * @date             2017/8/14 8:59
  */ 

#include <cv.h>
#include <highgui.h>
#include <stdio.h>

int main(int argc, char** argv)
{
	CvMat *the_matrix_data = cvCreateMat(5, 5, CV_32FC1);
	float element_3_2 = 7.7;
	*((float*)CV_MAT_ELEM_PTR(*the_matrix_data, 3, 2)) = element_3_2;

	cvmSet(the_matrix_data, 4, 4, 0.5000);
	cvSetReal2D(the_matrix_data, 3, 3, 0.5000);

	//CvMat A = cvMat(5, 5, CV_32F, the_matrix_data); // data error

	printf("Example 3_15:\nSaving my_matrix.xml\n");
	cvSave("my_matrix.xml", the_matrix_data);
	//. . .
	// to load it then in some other program use бн
	printf("Loading my_matrix.xml\n");
	CvMat* A1 = (CvMat*)cvLoad("my_matrix.xml");
}