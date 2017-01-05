#include "StdAfx.h"

#ifndef PREFORLEARN_H
#include "preforlearn.h"
#endif

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
#endif

IplImage* preforlearn(IplImage* pSrcImage) {
	IplImage *g_pBinaryImage = NULL;  
 
	g_pBinaryImage = cvCreateImage(cvGetSize(pSrcImage), 8, 1); 
	cvThreshold(pSrcImage, g_pBinaryImage, 100 , 255, CV_THRESH_BINARY); 
	cvXorS(g_pBinaryImage, cvScalarAll(255), g_pBinaryImage);
	return g_pBinaryImage;
}