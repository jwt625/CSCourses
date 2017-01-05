#ifndef IMAGECUT_H
#define IMAGECUT_H

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

void imagecut(IplImage *pSrcImage);

#endif