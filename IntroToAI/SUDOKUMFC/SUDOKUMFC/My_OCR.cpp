#include "StdAfx.h"


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

#ifndef PREPROCESSING_H
#include "preprocessing.h"
#endif

#ifndef PREFORLEARN_H
#include "preforlearn.h"
#endif

#ifndef MY_OCR_H
#include "My_OCR.h"
#endif

extern Weight Weights[10];


//获取训练数据
void My_OCR::getData()
{
	IplImage* src_image;
	IplImage prs_image;
	CvMat row,data; //矩阵头
	char file[255];
	int i,j;
	for(i =0; i<classes; i++){
		for( j = 0; j< train_samples; j++){
			
			//循环读取文件
			/*if(j<10)
				sprintf(file,"%s%d/%d0%d.pbm",file_path, i, i , j);
			else
				sprintf(file,"%s%d/%d%d.pbm",file_path, i, i , j);*/
			sprintf(file,"%s%d_%d.bmp","t10k-images/", i, j);
			src_image = cvLoadImage(file,0); //打开选中的图像
			if(!src_image){
				printf("Error: Cant load image %s\n", file);
				//exit(-1);
			}
			//预处理
			src_image = preforlearn(src_image);
			prs_image = preprocessing(src_image, size, size); //对图像进行预处理
			
			//标记类的label
			cvGetRow(trainClasses, &row, i*train_samples + j); //取出目标矩阵的一行（目标矩阵，矩阵指针，行数的索引）
			cvSet(&row, cvRealScalar(i));  //用给定值初始化数组，标记类的label
			
			//取出traindata矩阵中的同一行
			cvGetRow(trainData, &row, i*train_samples + j);

			//创建图像，宽和高均为size，位深度为单精度浮点数，通道数是1
			IplImage* img = cvCreateImage( cvSize( size, size ), IPL_DEPTH_32F, 1 ); 
			
			//把8比特的图转换成32位单精度图
			cvConvertScale(&prs_image, img, 0.0039215, 0); //（输入数组， 输出数组， 比例因子， 平移）

			cvGetSubRect(img, &data, cvRect(0,0, size,size)); //返回选中区域的尺寸（目标矩阵， 矩阵指针， 选中的区域）
			
			//将数据矩阵转换成一维向量
			CvMat row_header, *row1;
			row1 = cvReshape(&data, &row_header, 0, 1 );
			cvCopy(row1, &row, NULL); //拷贝数据（输入数组， 输出数组）
		}
	}
}

//训练函数
void My_OCR::train()
{
		knn=new CvKNearest( trainData, trainClasses, 0, false, K );

}

//分类函数
float My_OCR::classify(IplImage* img, int showResult, int z)
{
	IplImage prs_image;
	CvMat data;
	CvMat* nearest=cvCreateMat(1,K,CV_32FC1);
	float result;
	cvSaveImage("图1.jpg", img);
	//对将要识别的图像进行预处理
	prs_image = preprocessing(img, size, size);
	cvSaveImage("图2.jpg", &prs_image);
	//转换图像 
	IplImage* img32 = cvCreateImage( cvSize( size, size ), IPL_DEPTH_32F, 1 ); //创建一个32位单精度图
	cvConvertScale(&prs_image, img32, 0.0039215, 0); //将输入的8比特图装换成32位图
	cvGetSubRect(img32, &data, cvRect(0,0, size,size)); //截取图像
	
	//将图像的信息矩阵转换为向量
	CvMat row_header, *row1;
	row1 = cvReshape( &data, &row_header, 0, 1 );
	
	//利用knn算法寻找最佳匹配
	result=knn->find_nearest(row1,K,0,0,nearest,0);
	
	//利用knn算法的特性来估计这次匹配的正确率
	int accuracy=0, w;
	float *p = new float [K];
	for(int i = 0; i < K; i++)
		p[i] = 0;
	for(int i=0;i<K;i++){
		w = nearest->data.fl[i];
		p[w] ++;
	}
	if(z == 1) {
		int max = 1;
		for(int i = 1; i < K; i++) {
			if (p[i] > p[max]) max = i;
		}
		//if (p[max] * 1.0 / K < 0.5)
			//return -1;
		return max;
	}
	
	if(z == 2) {
	for(int i = 0; i < K; i++) {
		p[i] = p[i] / K;
		Weights[i].num = i;
		Weights[i].p = p[i];
		//printf("(%d, %f)", i, p[i]);
	}
	//printf("\n"); 
	}
	
	float pre=100*((float)accuracy/(float)K);

	//输出匹配结果即正确性
	/*if(showResult==1){
		printf("|\t%.0f\t| \t%.2f%%  \t| \t%d of %d \t| \n",result,pre,accuracy,K);
		printf(" ---------------------------------------------------------------\n");
	}*/

	return result;

}

//测试函数
void My_OCR::test()
{
	IplImage* src_image;
	IplImage prs_image;
	CvMat row,data;
	char file[255];
	int i,j;
	int error=0;
	int testCount=0;
	for(i =0; i<classes; i++){
		for( j = 0; j< 100; j++){

			//循环加载测试文件
			if(j<10)
				sprintf(file,"%s%d/%d0%d.pbm",file_path, i, i , j);
			else
				sprintf(file,"%s%d/%d%d.pbm",file_path, i, i , j);
			//sprintf(file,"%s%d_%d.bmp","t10k-images/", i, j);
			src_image = cvLoadImage(file,0);
			if(!src_image){
				printf("Error: Cant load image %s\n", file);
				//exit(-1);
			}
			
			//图片预处理
			//src_image = pre(src_image);
			prs_image = preprocessing(src_image, size, size);
			float r=classify(&prs_image,0);

			//测试
			if((int)r!=i)
				error++;
			
			testCount++;
		}
	}
	float totalerror=100*(float)error/(float)testCount;
	printf("System Error: %.2f%%\n", totalerror);
	
}

//构造函数
My_OCR::My_OCR()
{

	//初始化
	sprintf(file_path , "OCR/");
	train_samples = 400; //训练样本数
	classes= 10; //分类数
	size=40; //图片的尺度
	
	trainData = cvCreateMat(train_samples*classes, size*size, CV_32FC1); //创建矩阵，行数为50*10，列数为40*40，元素类型为32-bit有符号双通道
	trainClasses = cvCreateMat(train_samples*classes, 1, CV_32FC1);  //行数为50*10，列数为1，元素类型同上

	//设置训练数据
	getData();
	
	//进行训练
	train();
	
	//进行测试	
	test();
	
	//printf(" ---------------------------------------------------------------\n");
	//printf("|\tClass\t|\tPrecision\t|\tAccuracy\t|\n");
	//printf(" ---------------------------------------------------------------\n");

	
}