/**
  * @file:            Source.cpp
  * @description:     Description
  * @author:          yangjun
  * @copyright (c):   2017 yangjun. All Rights Reserved
  * @date             2017/8/14 14:26
  */ 

#include <cv.h>
#include <highgui.h>
#include <stdio.h>

int main(int argc, char** argv)
{
	printf("Example 3_19 Reading in cfg.xml\n");
	CvFileStorage* fs = cvOpenFileStorage(
		"cfg.xml",
		0,
		CV_STORAGE_READ
	);

	int frame_count = cvReadIntByName(
		fs,
		0,
		"frame_count",
		5 /* default value */
	);

	CvSeq* s = cvGetFileNodeByName(fs, 0, "frame_size")->data.seq;

	int frame_width = cvReadInt(
		(CvFileNode*)cvGetSeqElem(s, 0)
	);

	int frame_height = cvReadInt(
		(CvFileNode*)cvGetSeqElem(s, 1)
	);

	printf("frame_count=%d, frame_width=%d, frame_height=%d\n", frame_count, frame_width, frame_height);

	CvFileNode* file_node = cvGetFileNodeByName( // find node in file
		fs,
		NULL,
		"color_cvt_matrix");
	CvMat* readbynode = (CvMat *)cvRead( // read data by node
		fs,
		file_node);

	printf("element_3_2 = %f\nelement_3_3 = %f\nelement_4_4 = %f\n",
		CV_MAT_ELEM(*readbynode, float, 3, 2),
		CV_MAT_ELEM(*readbynode, float, 3, 3),
		CV_MAT_ELEM(*readbynode, float, 4, 4));

	cvReleaseFileStorage(&fs);
}
