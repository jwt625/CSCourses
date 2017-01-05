/*************************
Heros.h
����ʵ�ָ߷ְ�����Ľṹ����
��Heros.h��ʵ��
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

//������������Ϸʱ��Ľṹ��
struct HeroStruct				
{
	char m_name[21];
	int GameTime;
	HeroStruct(  int _time = 99999): GameTime(_time){}
};

//�ɶ�άHeroStruct����������ɨ��Ӣ�۰�
class HEROS
{
private:
	//��ά���飬�ֱ�Ϊ������ģ����Ϸ��ǰ����
	HeroStruct m_heros[3][3];						
public:
	HEROS(){}
	//��ȡ����
	string getName(int size = 0, int order = 0)const;		
	//��ȡ��Ϸʱ��
	int getTime(int size = 0, int order = 0)const;				
	//����Ӣ�����߷ְ�
	void insertHero(int size, char* tempName, int tempTime = 99999);		
	//��ȡ�߷ְ񲢴�ӡ
	int getAndPrintHeroList();											
	//��ȡ�߷ְ����ṹ���ά������
	int getHeroList();														
	//���߷ְ�д���ļ�
	void writeHeroList()const;											
};

#endif//HEROS_H_