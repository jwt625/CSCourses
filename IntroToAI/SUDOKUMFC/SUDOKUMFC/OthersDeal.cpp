#include "StdAfx.h"

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

#ifndef OTHERSDEAL_H
#include "OthersDeal.h"
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

IplImage* imagen, *img;
int red,green,blue;
IplImage* screenBuffer;
int drawing;
int r,last_x, last_y;
My_OCR ocr;
int PictSUDOKU[9][9];
Weight Weights[10];
int cccccc = 0;


void cut() {
	IplImage *pSrcImage = cvLoadImage("数独.jpg", CV_LOAD_IMAGE_UNCHANGED);
	imagecut(pSrcImage);
	
	char file[255];
	int k;
	for(int i = 0; i < 9; i++) {
		for(int j = 0; j < 9; j++) {
			sprintf(file,"%d_%d.jpg", i, j);
			img = cvLoadImage(file, CV_LOAD_IMAGE_UNCHANGED);
			CvScalar pixel;
			float wh = 0, bl = 0;
			for(int m = 0; m < img->height; m++)
				for(int n = 0; n < img->width; n++) {
					pixel = cvGet2D(img, m, n);
					if(pixel.val[0] > 128) wh ++;
					else bl ++;
				}
			float r = 0;
			r = bl * 1.0 / (wh + bl);
			if (r < 0.25) k = 0;
			else 
				k = ocr.classify(img, 1, 1);
			PictSUDOKU[i][j] = k;
		}
		//printf("\n");
	}
	
}

void draw(int x,int y){
	//在鼠标所在位置画圆(永久)
	cvCircle(imagen, cvPoint(x,y), r, CV_RGB(red, green, blue), -1, 4, 0);
	screenBuffer = cvCloneImage(imagen);
	cvShowImage( "Demo", screenBuffer );
}

void drawCursor(int x, int y){
	//画光标
	screenBuffer = cvCloneImage(imagen);
	cvCircle(screenBuffer, cvPoint(x, y), r, CV_RGB(0, 0, 0), 1, 4, 0);
}




void on_mouse( int event, int x, int y, int flags, void* param )
{
	last_x = x;
	last_y = y;
	drawCursor(x, y);
    //Select mouse Event
	if(event == CV_EVENT_LBUTTONDOWN)
        {
			drawing = 1;
			draw(x, y);
		}
    else if(event == CV_EVENT_LBUTTONUP)
		{
			//drawing = !drawing;
			drawing=0;
		}
	else if(event == CV_EVENT_MOUSEMOVE  &&  flags & CV_EVENT_FLAG_LBUTTON)
		{
			if(drawing)
				draw(x, y);
		}
}

#ifdef _EiC
main(1, "mouseEvent.c");
#endif