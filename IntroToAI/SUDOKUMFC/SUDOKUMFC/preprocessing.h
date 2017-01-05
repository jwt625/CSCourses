#ifndef PREPROCESSING_H
#define PREPROCESSING_H

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

IplImage preprocessing(IplImage* imgSrc,int new_width, int new_heightm );
//IplImage* preforlearn(IplImage* pSrcImage);

#endif