#ifndef MY_OCR_H
#define MY_OCR_H

#ifdef _CH_
#pragma package <opencv>
#endif

#ifndef _EiC
#ifndef __EiC__
#define __EiC__
#include <cv.h>
#include <highgui.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#endif

#ifndef __ML__
#define __ML__
#include <ml.h>
#endif
#endif

struct Weight
{
	int num;
	float p;
};

class My_OCR{
	public:
		float classify(IplImage* img, int showResult, int z = 0);
		My_OCR ();
		void test();	
	private:
		char file_path[255];
		int train_samples;
		int classes;
		CvMat* trainData;
		CvMat* trainClasses;
		int size;
		static const int K=10;
		CvKNearest *knn;
		void getData();
		void train();
};

#endif