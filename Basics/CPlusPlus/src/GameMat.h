/*************************
GameMat.h
包含描述游戏状态所需的结构与类
于GameMat.h中实现
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
#ifndef CIR_numbers								//定义显示所需字符，方便阅读代码
#define CIR_numbers
#define IsBOMB "⊙"
#define DOT "●"
#define CIR_1 "①"
#define CIR_2 "②"
#define CIR_3 "③"
#define CIR_4 "④"
#define CIR_5 "⑤"
#define CIR_6 "⑥"
#define CIR_7 "⑦"
#define CIR_8 "⑧"
#define CLEARED "√"
#endif

#include<time.h>					//获取当前时间以作为随机数的种子所需
#include <Windows.h>
class MATRIX
{
private:
	//行数与列数
	int m_row, m_col;			
	//m_MAT本体为int**类型
	pMAT m_MAT;				
public:	
	MATRIX(int row = 1, int col = 1);
	//获取矩阵元素
	int operator()(int x, int y)const;
	//获取行数
	int getRow()const{return m_row;}			
	//获取列数
	int getCol()const{return m_col;}				
	//初始化矩阵全体为某值，可添加行与列
	void initMat(int row = 0, int col = 0, int val = 0);		
	//	打印矩阵数值，测试用
	void printM()const;								
	//改变矩阵元素
	void changeMatItem(int x, int y, int input);				
	//重载操作符 = 的拷贝函数
	void operator= (MATRIX tempM);			
	//查找元素
	BOOL findInMat(int toFind = 0)const;	
	//计数矩阵中某数的个数
	int countInMat(int toCount = 0)const;	
	//人工释放内存
	void deleteMat(){delete [] m_MAT;}
	~MATRIX(){}
};

//由MATRIX类继承出的GameMat类
class GameMat:public MATRIX			
{
private:
	//雷数
	int m_numOfBomb;						
public:
	GameMat(int row = 1, int col = 1, int numOfBomb = 0);
	//获取雷数
	int getNumberOfBomb()const{return m_numOfBomb;}							
	//生成雷阵，可更改雷数
	void GenerateGM(int addBomb = 0, int currentX = 0, int currentY = 0);				
	//从雷阵生成雷的计数矩阵
	void GenerateBCMfrom(GameMat tempM);											
	//打印出可视化的雷阵
	void printWithColor()const;																	
	//打印出玩家看到的雷阵
	void printWithColor(GameMat tempGM)const;															
	//鼠标左键单击的相应操作
	void manipulateLD(GameMat*, GameMat*, int currentX = 0, int currentY = 0 );		
	//鼠标右键单击的相应操作
	void manipulateRD(GameMat*, GameMat*, int currentX = 0, int currentY = 0 );		
	//鼠标左右键双击的相应操作
	void manipulateBothD(GameMat*, GameMat*, int currentX = 0, int currentY = 0 );	
	//人工释放内存
	void deleteGM(){MATRIX::deleteMat();}
	~GameMat(){}
};

#endif//MATRIX_H_