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


//��ȡѵ������
void My_OCR::getData()
{
	IplImage* src_image;
	IplImage prs_image;
	CvMat row,data; //����ͷ
	char file[255];
	int i,j;
	for(i =0; i<classes; i++){
		for( j = 0; j< train_samples; j++){
			
			//ѭ����ȡ�ļ�
			/*if(j<10)
				sprintf(file,"%s%d/%d0%d.pbm",file_path, i, i , j);
			else
				sprintf(file,"%s%d/%d%d.pbm",file_path, i, i , j);*/
			sprintf(file,"%s%d_%d.bmp","t10k-images/", i, j);
			src_image = cvLoadImage(file,0); //��ѡ�е�ͼ��
			if(!src_image){
				printf("Error: Cant load image %s\n", file);
				//exit(-1);
			}
			//Ԥ����
			src_image = preforlearn(src_image);
			prs_image = preprocessing(src_image, size, size); //��ͼ�����Ԥ����
			
			//������label
			cvGetRow(trainClasses, &row, i*train_samples + j); //ȡ��Ŀ������һ�У�Ŀ����󣬾���ָ�룬������������
			cvSet(&row, cvRealScalar(i));  //�ø���ֵ��ʼ�����飬������label
			
			//ȡ��traindata�����е�ͬһ��
			cvGetRow(trainData, &row, i*train_samples + j);

			//����ͼ�񣬿�͸߾�Ϊsize��λ���Ϊ�����ȸ�������ͨ������1
			IplImage* img = cvCreateImage( cvSize( size, size ), IPL_DEPTH_32F, 1 ); 
			
			//��8���ص�ͼת����32λ������ͼ
			cvConvertScale(&prs_image, img, 0.0039215, 0); //���������飬 ������飬 �������ӣ� ƽ�ƣ�

			cvGetSubRect(img, &data, cvRect(0,0, size,size)); //����ѡ������ĳߴ磨Ŀ����� ����ָ�룬 ѡ�е�����
			
			//�����ݾ���ת����һά����
			CvMat row_header, *row1;
			row1 = cvReshape(&data, &row_header, 0, 1 );
			cvCopy(row1, &row, NULL); //�������ݣ��������飬 ������飩
		}
	}
}

//ѵ������
void My_OCR::train()
{
		knn=new CvKNearest( trainData, trainClasses, 0, false, K );

}

//���ຯ��
float My_OCR::classify(IplImage* img, int showResult, int z)
{
	IplImage prs_image;
	CvMat data;
	CvMat* nearest=cvCreateMat(1,K,CV_32FC1);
	float result;
	cvSaveImage("ͼ1.jpg", img);
	//�Խ�Ҫʶ���ͼ�����Ԥ����
	prs_image = preprocessing(img, size, size);
	cvSaveImage("ͼ2.jpg", &prs_image);
	//ת��ͼ�� 
	IplImage* img32 = cvCreateImage( cvSize( size, size ), IPL_DEPTH_32F, 1 ); //����һ��32λ������ͼ
	cvConvertScale(&prs_image, img32, 0.0039215, 0); //�������8����ͼװ����32λͼ
	cvGetSubRect(img32, &data, cvRect(0,0, size,size)); //��ȡͼ��
	
	//��ͼ�����Ϣ����ת��Ϊ����
	CvMat row_header, *row1;
	row1 = cvReshape( &data, &row_header, 0, 1 );
	
	//����knn�㷨Ѱ�����ƥ��
	result=knn->find_nearest(row1,K,0,0,nearest,0);
	
	//����knn�㷨���������������ƥ�����ȷ��
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

	//���ƥ��������ȷ��
	/*if(showResult==1){
		printf("|\t%.0f\t| \t%.2f%%  \t| \t%d of %d \t| \n",result,pre,accuracy,K);
		printf(" ---------------------------------------------------------------\n");
	}*/

	return result;

}

//���Ժ���
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

			//ѭ�����ز����ļ�
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
			
			//ͼƬԤ����
			//src_image = pre(src_image);
			prs_image = preprocessing(src_image, size, size);
			float r=classify(&prs_image,0);

			//����
			if((int)r!=i)
				error++;
			
			testCount++;
		}
	}
	float totalerror=100*(float)error/(float)testCount;
	printf("System Error: %.2f%%\n", totalerror);
	
}

//���캯��
My_OCR::My_OCR()
{

	//��ʼ��
	sprintf(file_path , "OCR/");
	train_samples = 400; //ѵ��������
	classes= 10; //������
	size=40; //ͼƬ�ĳ߶�
	
	trainData = cvCreateMat(train_samples*classes, size*size, CV_32FC1); //������������Ϊ50*10������Ϊ40*40��Ԫ������Ϊ32-bit�з���˫ͨ��
	trainClasses = cvCreateMat(train_samples*classes, 1, CV_32FC1);  //����Ϊ50*10������Ϊ1��Ԫ������ͬ��

	//����ѵ������
	getData();
	
	//����ѵ��
	train();
	
	//���в���	
	test();
	
	//printf(" ---------------------------------------------------------------\n");
	//printf("|\tClass\t|\tPrecision\t|\tAccuracy\t|\n");
	//printf(" ---------------------------------------------------------------\n");

	
}