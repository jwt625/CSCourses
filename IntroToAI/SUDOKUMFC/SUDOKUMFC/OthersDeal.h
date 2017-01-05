#ifndef OTHERSDEAL_H
#define OTHERSDEAL_H

#ifdef _CH_
#pragma package <opencv>
#endif

#include "fstream"

#ifndef MY_OCR_H
#include "My_OCR.h"
#endif

#ifndef PREPROCESSING_H
#include "preprocessing.h"
#endif

#ifndef IMAGECUT_H
#include "imagecut.h"
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



void cut();

void draw(int x,int y);

void drawCursor(int x, int y);

void on_mouse( int event, int x, int y, int flags, void* param );

#ifdef _EiC
main(1, "mouseEvent.c");
#endif

#endif


