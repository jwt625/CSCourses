#include "StdAfx.h"

#ifndef IMAGECUT_H
#include "imagecut.h"
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

#ifndef PREPROCESSING_H
#include "preprocessing.h"
#endif

/*
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
}*/
/*
IplImage imagecut(IplImage* imgSrc,int new_width, int new_height) {
	IplImage x;
	return x;
}
*/
void imagecut(IplImage *pSrcImage) {
	
	IplImage *g_pGrayImage = NULL;
	IplImage *g_pBinaryImage = NULL;


	// 转为灰度图
	g_pGrayImage =  cvCreateImage(cvGetSize(pSrcImage), IPL_DEPTH_8U, 1);
	cvCvtColor(pSrcImage, g_pGrayImage, CV_BGR2GRAY);
	cvSaveImage("灰度图.jpg", g_pGrayImage);
	// 创建二值图
	g_pBinaryImage = cvCreateImage(cvGetSize(g_pGrayImage), IPL_DEPTH_8U, 1);

	
	cvThreshold(g_pGrayImage, g_pBinaryImage, 100, 255, CV_THRESH_BINARY); //转为二值图，阈值是200

	cvSaveImage("二值图.jpg", g_pBinaryImage);
	//除去边缘白边
	IplImage firstprsimg = preprocessing(g_pBinaryImage, 450, 450);
	IplImage prsimg = preprocessing(&firstprsimg, 450, 450);
	

	cvSaveImage("去白边.jpg", &prsimg);
	
	IplImage *img1 = cvCreateImage(cvSize(40, 40), 8, 1);
	
	
	
	CvMat a[9][9], b[9][9];
	IplImage* test[81];
	for(int i = 0; i < 9; i++)
		for(int j = 0; j < 9; j++) { 
			cvZero(img1);
			test[i * 9 + j] = cvCreateImage(cvSize(40, 40), 8, 1);
			cvSet(test[i * 9 + j],CV_RGB(255,255,255),NULL);
			cvGetSubRect(&prsimg, &a[i][j], cvRect((50 * i + 5), (50 * j + 5), 40, 40));
			cvGetSubRect(test[i * 9 + j], &b[i][j], cvRect(0, 0, 40, 40));
			cvCopy(&a[i][j], &b[i][j], NULL);
			cvErode(test[i * 9 + j], img1, NULL, 1);
			int s = i * 9 + j;
			char file[100];
			sprintf(file,"%d_%d.jpg", j, i);
			cvSaveImage(file, img1);
		}
}