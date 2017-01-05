/*************************
Heros.h
包含实现高分榜所需的结构与类
于Heros.h中实现
*************************/

#ifndef cout
#include<iostream>
using namespace std;
#endif
#ifndef ifstream
#include<fstream>
#endif
#ifndef HEROS_H_
#define HEROS_H_
#define SMALLMAP  0
#define MEDIUMMAP 1
#define BIGMAP 2
#define FIRST 0
#define SECOND 1
#define THIRD 2

//包含姓名与游戏时间的结构体
struct HeroStruct				
{
	char m_name[21];
	int GameTime;
	HeroStruct(  int _time = 99999): GameTime(_time){}
};

//由二维HeroStruct数组描述的扫雷英雄榜
class HEROS
{
private:
	//二维数组，分别为三个规模的游戏的前三名
	HeroStruct m_heros[3][3];						
public:
	HEROS(){}
	//获取姓名
	string getName(int size = 0, int order = 0)const;		
	//获取游戏时间
	int getTime(int size = 0, int order = 0)const;				
	//插入英雄至高分榜
	void insertHero(int size, char* tempName, int tempTime = 99999);		
	//读取高分榜并打印
	int getAndPrintHeroList();											
	//读取高分榜至结构体二维数组中
	int getHeroList();														
	//将高分榜写入文件
	void writeHeroList()const;											
};

#endif//HEROS_H_