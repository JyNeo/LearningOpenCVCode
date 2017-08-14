/**
  * @file:            Source.cpp
  * @description:     Description
  * @author:          yangjun
  * @copyright (c):   2017 yangjun. All Rights Reserved
  * @date             2017/8/14 9:02
  */ 

#include <stdio.h>
#include <cv.h>
#include <highgui.h>

int main(int argc, char** argv)
{
	const char* libraries;
	const char* modules;
	cvGetModuleInfo(0, &libraries, &modules);
	printf("Libraries: %s\nModules: %s\n", libraries, modules);
}