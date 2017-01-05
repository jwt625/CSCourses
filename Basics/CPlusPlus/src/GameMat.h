/*************************
GameMat.h
����������Ϸ״̬����Ľṹ����
��GameMat.h��ʵ��
*************************/

#ifndef pMAT
typedef int** pMAT;
typedef int* pARY;
#endif
#ifndef cout
#include<iostream>
using namespace std;
#endif
#ifndef MATRIX_H_
#define MATRIX_H_
#ifndef CIR_numbers								//������ʾ�����ַ��������Ķ�����
#define CIR_numbers
#define IsBOMB "��"
#define DOT "��"
#define CIR_1 "��"
#define CIR_2 "��"
#define CIR_3 "��"
#define CIR_4 "��"
#define CIR_5 "��"
#define CIR_6 "��"
#define CIR_7 "��"
#define CIR_8 "��"
#define CLEARED "��"
#endif

#include<time.h>					//��ȡ��ǰʱ������Ϊ���������������
#include <Windows.h>
class MATRIX
{
private:
	//����������
	int m_row, m_col;			
	//m_MAT����Ϊint**����
	pMAT m_MAT;				
public:	
	MATRIX(int row = 1, int col = 1);
	//��ȡ����Ԫ��
	int operator()(int x, int y)const;
	//��ȡ����
	int getRow()const{return m_row;}			
	//��ȡ����
	int getCol()const{return m_col;}				
	//��ʼ������ȫ��Ϊĳֵ�������������
	void initMat(int row = 0, int col = 0, int val = 0);		
	//	��ӡ������ֵ��������
	void printM()const;								
	//�ı����Ԫ��
	void changeMatItem(int x, int y, int input);				
	//���ز����� = �Ŀ�������
	void operator= (MATRIX tempM);			
	//����Ԫ��
	BOOL findInMat(int toFind = 0)const;	
	//����������ĳ���ĸ���
	int countInMat(int toCount = 0)const;	
	//�˹��ͷ��ڴ�
	void deleteMat(){delete [] m_MAT;}
	~MATRIX(){}
};

//��MATRIX��̳г���GameMat��
class GameMat:public MATRIX			
{
private:
	//����
	int m_numOfBomb;						
public:
	GameMat(int row = 1, int col = 1, int numOfBomb = 0);
	//��ȡ����
	int getNumberOfBomb()const{return m_numOfBomb;}							
	//�������󣬿ɸ�������
	void GenerateGM(int addBomb = 0, int currentX = 0, int currentY = 0);				
	//�����������׵ļ�������
	void GenerateBCMfrom(GameMat tempM);											
	//��ӡ�����ӻ�������
	void printWithColor()const;																	
	//��ӡ����ҿ���������
	void printWithColor(GameMat tempGM)const;															
	//��������������Ӧ����
	void manipulateLD(GameMat*, GameMat*, int currentX = 0, int currentY = 0 );		
	//����Ҽ���������Ӧ����
	void manipulateRD(GameMat*, GameMat*, int currentX = 0, int currentY = 0 );		
	//������Ҽ�˫������Ӧ����
	void manipulateBothD(GameMat*, GameMat*, int currentX = 0, int currentY = 0 );	
	//�˹��ͷ��ڴ�
	void deleteGM(){MATRIX::deleteMat();}
	~GameMat(){}
};

#endif//MATRIX_H_