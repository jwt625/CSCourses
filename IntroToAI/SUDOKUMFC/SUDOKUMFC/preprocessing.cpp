#include "StdAfx.h"

#ifndef PREPROCESSING_H
#include "preprocessing.h"
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

void infindX(IplImage* imgSrc,int* min, int* max){
	int i;
	int minFound=0;
	CvMat data;
	CvScalar maxVal=cvRealScalar(imgSrc->width * 255);
	CvScalar val=cvRealScalar(0);
	//For each col sum, if sum < width*255 then we find the min 
	//then continue to end to search the max, if sum< width*255 then is new max
	for (i=0; i< imgSrc->width; i++){
		cvGetCol(imgSrc, &data, i);
		val= cvSum(&data);
		if(val.val[0] > maxVal.val[0]){
			*max= i;
			if(!minFound){
				*min= i;
				minFound= 1;
			}
		}
	}
}

void infindY(IplImage* imgSrc,int* min, int* max){
	int i;
	int minFound=0;
	CvMat data;
	CvScalar maxVal=cvRealScalar(imgSrc->width * 255);
	CvScalar val=cvRealScalar(0);
	//For each col sum, if sum < width*255 then we find the min 
	//then continue to end to search the max, if sum< width*255 then is new max
	for (i=0; i< imgSrc->height; i++){
		cvGetRow(imgSrc, &data, i);
		val= cvSum(&data);
		if(val.val[0] > maxVal.val[0]){
			*max=i;
			if(!minFound){
				*min= i;
				minFound= 1;
			}
		}
	}
}
void findX(IplImage* imgSrc,int* min, int* max){
	int i;
	int minFound=0;
	CvMat data;
	CvScalar maxVal=cvRealScalar(imgSrc->width * 255);
	CvScalar val=cvRealScalar(0);
	//For each col sum, if sum < width*255 then we find the min 
	//then continue to end to search the max, if sum< width*255 then is new max
	for (i=0; i< imgSrc->width; i++){
		cvGetCol(imgSrc, &data, i);
		val= cvSum(&data);
		if(val.val[0] < maxVal.val[0]){
			*max= i;
			if(!minFound){
				*min= i;
				minFound= 1;
			}
		}
	}
}

void findY(IplImage* imgSrc,int* min, int* max){
	int i;
	int minFound=0;
	CvMat data;
	CvScalar maxVal=cvRealScalar(imgSrc->width * 255);
	CvScalar val=cvRealScalar(0);
	//For each col sum, if sum < width*255 then we find the min 
	//then continue to end to search the max, if sum< width*255 then is new max
	for (i=0; i< imgSrc->height; i++){
		cvGetRow(imgSrc, &data, i);
		val= cvSum(&data);
		if(val.val[0] < maxVal.val[0]){
			*max=i;
			if(!minFound){
				*min= i;
				minFound= 1;
			}
		}
	}
}
CvRect findBB(IplImage* imgSrc){
	CvRect aux;
	int xmin, xmax, ymin, ymax;
	xmin=xmax=ymin=ymax=0;

	findX(imgSrc, &xmin, &xmax);
	findY(imgSrc, &ymin, &ymax);
	
	aux=cvRect(xmin, ymin, xmax-xmin, ymax-ymin);
	
	return aux;
	
}
CvRect infindBB(IplImage* imgSrc){
	CvRect aux;
	int xmin, xmax, ymin, ymax;
	xmin=xmax=ymin=ymax=0;

	infindX(imgSrc, &xmin, &xmax);
	infindY(imgSrc, &ymin, &ymax);
	
	aux=cvRect(xmin, ymin, xmax-xmin, ymax-ymin);
	
	return aux;
	
}


/*IplImage* preforlearn(IplImage* pSrcImage) {
	IplImage *g_pBinaryImage = NULL;  
 
	g_pBinaryImage = cvCreateImage(cvGetSize(pSrcImage), 8, 1); 
	cvThreshold(pSrcImage, g_pBinaryImage, 100 , 255, CV_THRESH_BINARY); 
	cvXorS(g_pBinaryImage, cvScalarAll(255), g_pBinaryImage);
	return g_pBinaryImage;
}
*/

IplImage preprocessing(IplImage* imgSrc,int new_width, int new_height){
	IplImage* result;
	IplImage* scaledResult;

	CvMat data;
	CvMat dataA;
	CvRect bb;//bounding box
	CvRect bba;//boundinb box maintain aspect ratio
	
	//寻找图像的边界
	 bb=findBB(imgSrc);
	// bb = infindBB(imgSrc);
	
	cvGetSubRect(imgSrc, &data, cvRect(bb.x, bb.y, bb.width, bb.height));
	
	int size=(bb.width>bb.height)?bb.width:bb.height; //取长宽较大的作为图像的尺度
	result=cvCreateImage( cvSize( size, size ), 8, 1 ); //创建一个8比特的图像
	cvSet(result,CV_RGB(255,255,255),NULL);
	
	int x=(int)floor((float)(size-bb.width)/2.0f);
	int y=(int)floor((float)(size-bb.height)/2.0f);
	cvGetSubRect(result, &dataA, cvRect(x,y,bb.width, bb.height));
	cvCopy(&data, &dataA, NULL);
	
	scaledResult=cvCreateImage( cvSize( new_width, new_height ),8, 1 );
	cvResize(result, scaledResult, CV_INTER_NN);
	
	
	return *scaledResult;
	
}
