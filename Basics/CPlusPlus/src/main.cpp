///////////////////////////////////////////////////////
////                                                                      ////
////      MineSweeper by JWT     2013011717      ////
////		Department of Physics                             ////
////                                                                      ////
///////////////////////////////////////////////////////
#include<conio.h>				//getch()��������
#include<ctime>					//��ȡ��ǰʱ������
#include "GameMat.h"
#include "Heros.h"
#ifndef ASCII_NUM
#define ASCII_NUM
#define _ZERO 48
#define _ONE 49
#define _TWO 50
#define _THREE 51
#define _FOUR 52
#endif//ASCII_NUM

GameMat* getNewpGameMat(int row, int col, int numOB, int currentX = 0, int currentY = 0)
{	
	GameMat* temppGM = new GameMat;
	temppGM->initMat(row+1,col+1);
	temppGM->GenerateGM(numOB, currentX, currentY);
	return temppGM;
}
GameMat* getpBCMfrom(GameMat* temppGM)
{
	GameMat* temppBCM = new GameMat;
	temppBCM->GenerateBCMfrom(temppGM[0]);
	return temppBCM;
}
//�˺���ͨ����ǰ��Ϸ״̬�ж��Ƿ�Ӧ�ý�����Ϸ
BOOL judge(GameMat*, GameMat* );
//�˺���ʵ�ֹ���������ƶ������������Ҽ�����Ķ��룬����ֵΪ�������
int mouse(int & i, int & j);
//�˺���ʵ����Ϸ��ʼ�˵��Ĵ�ӡ���û�ѡ��Ļ�ȡ
int startGame(int & row, int & col, int & numOB);
//�˺����жϽ�����Ϸ������Ƿ��ʤ����ӡ��Ӧ���
void WinOrLose(GameMat* temppGM, GameMat* temppBCM, long int beginTime);
//�˺�����ӡ���Ѿ�������Ϸʱ��
long int showGameTime(long int beginTime);
void getName();
//���߷ְ�����Ϊȫ�֣�����ʹ��
HEROS HeroList;						
int main()
{	
	int row, col, numOB;
	HeroList.getHeroList();
_begin:

	int ch = startGame(row, col, numOB);				//��ʼ��Ϸ����ӡ�û�����
	system("cls");
	GameMat tempGM(row+2, col+2, numOB);
	tempGM.initMat(0, 0, -1);
	if(ch == _FOUR)
		goto _end;
	
	tempGM.printWithColor(tempGM);							//��ӡ��δ���׵Ŀհ����󹩻�ȡ��ҵĵ�һ�ε��
	int tempcurrentX = 0, tempcurrentY = 0;
	do																			//��������ǰ�Ȼ�ȡһ��������������һ�ε�����ȵ���
	{
			mouse(tempcurrentY, tempcurrentX);						//��ȡ��һ�������
	}while(!((tempcurrentY<=col)&&(tempcurrentX<=row)&&(tempcurrentX>0)&&(tempcurrentY>0)));				//�жϵ���Ƿ�����Ч������
	
	//��һ����������ȡ��Ϸ��ʼʱ��
	long int beginTime = time(NULL);																													

	//���ݵ�һ���������������������
	GameMat* pGM = getNewpGameMat(row, col, numOB, tempcurrentX, tempcurrentY);								
	/*cout<<endl<<pGM->getNumberOfBomb()<<endl;
	pGM->printM();
	system("pause");*/
	GameMat* pBCM = getpBCMfrom(pGM);
	pBCM->manipulateLD(pGM, pBCM, tempcurrentX, tempcurrentY);													//����Ӧ����ִ����������Ĳ���

	//pBCM->printM();	
	//pGM->printWithColor();
	//pBCM->printWithColor();
	do
	{
		system("cls");		
		//��ӡ��ǰ����
		pBCM->printWithColor(pGM[0]);										
		//��ӡ��Ϸʱ��
		showGameTime(beginTime);												
		/*pGM->printM();
		pBCM->printM();
		pBCM->printWithColor();
		cout<<tempcurrentX<<' '<<tempcurrentY<<endl;*/
		int opt = 0;
		do
		{
			opt = mouse(tempcurrentY, tempcurrentX);
		}while(!((tempcurrentY<pGM[0].getCol()-1)&&(tempcurrentX<pGM[0].getRow()-1)&&(tempcurrentX>0)&&(tempcurrentY>0)));		//�жϵ���Ƿ�����Ч������

		//�������������ִ�в�ͬ������0����������������1��������Ҽ�����
		switch(opt)									
		{
		case 0:
			if((pGM->operator()(tempcurrentX+1, tempcurrentY+1) == 0)||(pGM->operator()(tempcurrentX+1, tempcurrentY+1) == -1))			//�жϵ���ʱӦִ�еĲ�������
				pBCM->manipulateLD(pGM, pBCM, tempcurrentX, tempcurrentY);
			else
				pBCM->manipulateBothD(pGM, pBCM, tempcurrentX, tempcurrentY);
			break;
		case 1:
			pBCM->manipulateRD(pGM, pBCM, tempcurrentX, tempcurrentY);
			break;
		default:
			break;
		}
	}while(!judge(pGM, pBCM));																	//ѭ����ȡ���������ֱ���ж���ϷӦ����ֹ
	
	//�ж���Ϸ��ֹ���ʤ�����
	WinOrLose(pGM, pBCM, beginTime);						

	if(ch != _FOUR)
	{
		pGM->deleteGM();
		pBCM->deleteGM();
		delete pGM;
		delete pBCM;
		goto _begin;
	}
	
_end:
	return 0;
}
BOOL judge(GameMat* temppGM, GameMat* temppBCM)									
{
	int numOfBomb = temppGM[0].getNumberOfBomb();
	int row = temppGM[0].getRow();
	int col = temppGM[0].getCol();
	int count1 = 0;
	for(int i = 1; i < row; i++)
	{
		for(int j = 1; j < col; j++)
		{
			if(temppGM[0](i, j) > 0 )
				count1++;												//����̽�����ķ�����м���
		}
	}
	return (count1 == (row - 2)*(col - 2) - numOfBomb)||(temppGM[0].findInMat(3));			//����̽��������Ϊ���׷��������Ѳ��ף��򷵻�1
}
int mouse(int & i, int & j)																			
{
    DWORD dwMode, dwOldMode;                                                          /* ԭ����ģʽ����ģʽ */
    DWORD dwRead;																	  /* �Ѿ���ȡ�������¼��� */
    int mouse_pos;																	  /* ���ڷ������λ�� */
    UINT count;																		  /* ����ѭ������ */
    INPUT_RECORD ir[128];															  /* ����̨�����¼ */
    CONSOLE_CURSOR_INFO cci, cciOld;												  /* �����ص����� */
    COORD co;																		  /* ����ƶ�ʱ�������� */
    HANDLE hStdIn = NULL, hStdOut = NULL;											  /* ��׼����������  */


    hStdIn = GetStdHandle(STD_INPUT_HANDLE);										  /* ȡ������������ */
    hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

    if(!GetConsoleMode(hStdIn, &dwOldMode))											  /* ȡ�ÿ���̨ԭ����ģʽ */
    {
        fprintf(stderr, "GetConsoleMode ����:%d\n", GetLastError());
        goto _exit;
    }
    dwMode = dwOldMode | ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;
    if(!SetConsoleMode(hStdIn, dwMode))												  /* ��������¼� */
    {
        fprintf(stderr, "SetConsoleMode ����:%d\n", GetLastError());
        goto _exit;
    }

    GetConsoleCursorInfo(hStdOut, &cciOld);
    cci.bVisible = TRUE;															  /* ���ɼ� */
    cci.dwSize = 100;																  /* ��״ */
    if(!SetConsoleCursorInfo(hStdOut, &cci))
    {
        fprintf(stderr, "SetConsoleCursorInfo ����:%d\n", GetLastError());
        goto _exit;
    }

    for(;;)																			  /* ѭ���ȴ��û��¼� */
    {
        if(!ReadConsoleInput(hStdIn, &ir[0], 128, &dwRead))
        {
            fprintf(stderr, "ReadConsoleInput ����:%d\n", GetLastError());
            goto _exit;
        }
        for(count=0; count<dwRead; count++)
        {
            switch(ir[count].EventType)
            {
            case MOUSE_EVENT:
                switch(ir[count].Event.MouseEvent.dwEventFlags)
                {
                case MOUSE_MOVED:													  /* �������λ�� */
                    co.X = ir[count].Event.MouseEvent.dwMousePosition.X;
                    co.Y = ir[count].Event.MouseEvent.dwMousePosition.Y;
                    SetConsoleCursorPosition(hStdOut, co);   
					i = co.X / 2 -3;
					j = co.Y - 2;
					//cout<<"x: "<<i<<" y: "<<j;
                    break;
                case 0:																  /* ȡ�������������¼� */
                    if(ir[count].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)					//����������
                    {
						SetConsoleMode(hStdIn, dwOldMode);							  /* ��ԭԭ�������� */
                        SetConsoleCursorInfo(hStdOut, &cciOld);
                        mouse_pos = ir[count].Event.MouseEvent.dwMousePosition.X;
                        mouse_pos = mouse_pos << 16 | ir[count].Event.MouseEvent.dwMousePosition.Y;
                        return 0;
					}
					if(ir[count].Event.MouseEvent.dwButtonState == RIGHTMOST_BUTTON_PRESSED)						//����Ҽ�����
                    {
						SetConsoleMode(hStdIn, dwOldMode);							  /* ��ԭԭ�������� */
                        SetConsoleCursorInfo(hStdOut, &cciOld);
                        mouse_pos = ir[count].Event.MouseEvent.dwMousePosition.X;
                        mouse_pos = mouse_pos << 16 | ir[count].Event.MouseEvent.dwMousePosition.Y;
                        return 1;
					}
                    break;
                }
                break;
            default:
                break;
            }
        }
    }
_exit:
    return 2;
}
int startGame(int & row, int & col, int & numOB)								
{
	int ch = 0;
	row = 0;
	col = 0;
	numOB = 0;
	while(1)
	{		
		//initializing
		system("cls");
		HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);								/*��ʼ��������ɫΪ��ɫ*/
		WORD att;   
		att = FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY;
		SetConsoleTextAttribute(handle, att);
		cout<<endl<<"\t\t��Ϸ��ɨ��\n\t\tv 1.1\n\n"<<"\t    ��ѡ��\n\n"<<"  \t1. ��ʼ��Ϸ��\n\n"
			<<"  \t2. ��Ϸ˵����\n\n"<<"  \t3. ɨ��Ӣ�۰�\n\n"<<"  \t4. �˳���Ϸ.\n\n\n\t\t\t\t--By JWT\n";
		do
		{
			ch = getch();																				/*��getch()�����õ����룬�˷�����Ϊ��ȫ����ͬ*/
		}while((ch != _ONE)&&(ch != _TWO)&&(ch != _THREE)&&(ch != _FOUR));				//���δ����1��2��3��4ʱ�����������룬��ͬ

		
		if(ch == _FOUR)													//�˳���Ϸ
			break;

		if(ch == _ONE)
		{
#pragma region OptionOne_GameStart
			int n1 = 0;
			int step = 0;			
			_pre:
			system("cls");
			cout<<endl<<"\t\t��ѡ����Ϸ�Ѷȣ�\n\n"<<"  \t1. ������9*9�����飬10���ף�\n\n"<<"  \t2. �м���16*16�����飬40���ף�\n\n"
				<<"  \t3. �߼���16*30�����飬99���ף�\n\n"<<"  \t4.�Զ��壻\n\n"<<"\t��0�����ز˵���";
			do
			{
				n1 = getch();
			}while((n1 != _ZERO)&&(n1 != _ONE)&&(n1 != _TWO)&&(n1 != _THREE)&&(n1 != _FOUR));					  
			if(n1 == _ZERO) continue;
			else
			{
				switch (n1)
				{
				case _ONE:
					row = 9;
					col = 9;
					numOB = 10;
					break;
				case _TWO:
					row = 16;
					col = 16;
					numOB = 40;
					break;
				case _THREE:
					row = 16;
					col = 30;
					numOB = 99;
					break;
				case _FOUR:
					{
						int n2 = 0;
						
							_input:
							system("cls");							
							cout<<endl<<"\t������ 5 ~ 50 �������(��Ӣ�ľ��\".\"����)��";
							n2 = 0;
							row = 0;
							while(1)															/*�˲��ֵ������Բ���getch()�Ա�֤�����robust*/
							{
								if(n2 == (int)'.')
									break;
								do
								{
									n2 = getch();
								}while((n2 !=48)&&(n2 !=49)&&(n2 !=50)&&(n2 !=51)&&(n2 !=52)&&(n2 != 53)&&(n2 !=54)&&(n2 !=55)&&(n2 !=56)&&(n2 !=57)&&(n2 !=(int)'.'));
								if(n2 != (int)'.')
								{
									cout<<(n2-_ZERO);
									row = 10*row +n2 - _ZERO;						//	������������ַ�������ת��Ϊ��
								}
							}
							if((row<5)||(row>50))
								goto _input;
							cout<<endl<<"\t�����������Ϊ�� "<<row<<endl<<"\n\t������ 5 ~ 30 �������(��Ӣ�ľ��\".\"����)��";
							n2 = 0;
							col = 0;
							while(1)
							{
								if(n2 == (int)'.')
									break;
								do
								{
									n2 = getch();
								}while((n2 !=48)&&(n2 !=49)&&(n2 !=50)&&(n2 !=51)&&(n2 !=52)&&(n2 != 53)&&(n2 !=54)&&(n2 !=55)&&(n2 !=56)&&(n2 !=57)&&(n2 !=(int)'.'));		//�û�δ�������ֻ�Ӣ�ľ��ʱ�����������룬��ͬ
								if(n2 != (int)'.')
								{
									cout<<(n2-_ZERO);
									col = 10*col +n2 - _ZERO;
								}
							}
							if((col<5)||(col>30))
								goto _input;
							cout<<endl<<"\t�����������Ϊ�� "<<col<<endl<<"\n\t������ 5 ~ ����*���� �������(��Ӣ�ľ��\".\"����)��";
							n2 = 0;
							numOB = 0;
							while(1)
							{
								if(n2 == (int)'.')
									break;
								do
								{
									n2 = getch();
								}while((n2 !=48)&&(n2 !=49)&&(n2 !=50)&&(n2 !=51)&&(n2 !=52)&&(n2 != 53)&&(n2 !=54)&&(n2 !=55)&&(n2 !=56)&&(n2 !=57)&&(n2 !=(int)'.'));
								if(n2 != (int)'.')
								{
									cout<<(n2-_ZERO);
									numOB = 10*numOB +n2 - _ZERO;
								}
							}
							if((numOB >= row * col)||(numOB < 5))
								goto _input;
							cout<<endl<<"\t�����������Ϊ�� "<<numOB<<endl<<"\n\t��0��ȡ����������һ�˵�����1��ȷ�ϣ�";
						do
						{
							n2 = getch();
						}while((n2 != _ZERO)&&(n2 != _ONE));
						if(n2 == _ZERO)
							goto _pre;
						break;
					}
				}
				if (n1 != _ZERO)
					break;				
			}
#pragma endregion
		}
		
		if(ch == _TWO)															/*˵����Ϸ����*/
		{
#pragma region OptionTwo_Instructions
			int n1 = 0;
			
				system("cls");
				cout<<"\n\n\t��ϷĿ�ģ���ϷĿ��������̵�ʱ���ڸ��ݵ�����ӳ��ֵ�����\n\t        �ҳ����з��׸��ӣ�ͬʱ������ס�\n\n"
					<<"\tһ���������������ɫԲ�㼴�ɴ򿪸��ӡ�\n\n";
				cout<<"\t�����ɹ���̽���ĸ��ӽ���ʾ��, ��, �ڵȣ����С̱�ʾ��ȫ�ش���\n\t    ��ԲȦ�����ֱ�ʾ����8�����׵���Ŀ��\n\n";
				cout<<"\t��������Ҽ�����δ̽�����ĸ��Ӽ��ɱ�ע���ף�����ʾ��";
				HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
				WORD att;   
				att = FOREGROUND_RED|FOREGROUND_INTENSITY;
				SetConsoleTextAttribute(handle, att);
				cout<<IsBOMB;
				handle = GetStdHandle(STD_OUTPUT_HANDLE);		
				att = FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY;
				SetConsoleTextAttribute(handle, att);
				cout<<", \n\t    �ٴε����Ҽ�����ȡ����ע���ס�\n\n";
				cout<<"\t�ġ�������������̽������������8�������׵ĸ��ӣ����ɸ�����Χ\n\t    ���׵ı�ע����Զ��򿪡���ȫ���ĸ��ӣ���һ��ɨ����Ϸ��˫��\n\t    ͬʱ�����Ч����ͬ��\n\n";
				cout<<"\t�塢��ȷ�ҳ����з��׸��Ӻ󼴿ɻ��ʤ�������ȵ���������Ϸʧ�ܣ�\n\t    ���е��׶�����ʾ���������ȵĵ����򽫸�����ʾ��\n\n";
				cout<<"\t��ע����������Ĺ��̿��ܺ�ʱ0.2�����ң�������ѡ�����Զ�������\n\t      ����ܺ�ʱ��΢���ã��������ĵȴ���\n"
					<<"\n\t      ��Ϸʱ����ڵ�һ�ε����꿪ʼ��Ϸʱ��ʼ��ʱ��\n\t      ÿһ�ε������Ż������Ϸʱ�����ʾ����������Ϊ��Ϸʱ����ͣ��\n\n";
				cout<<"\t��0���ز˵���";
			do
			{
				n1 = getch();
				if(n1 == _ZERO) break;
			}while(n1 != _ZERO);
#pragma endregion
		}

		if(ch == _THREE)															/*�鿴�߷ְ�*/
		{
#pragma region OptionThree_HeroList
			int n1;			
			system("cls");
			HeroList.getAndPrintHeroList();							//���ļ���ȡ����ӡ�߷ְ�
			cout<<"\n\n\t��0�����ز˵���";
			do
			{
				n1 = getch();
				if(n1 == _ZERO) break;
			}while(n1 != _ZERO);
		}
#pragma endregion
	}
	return ch;				//�����û������ѡ���Ƿ����������ж������������������ִ��
}
void WinOrLose(GameMat* temppGM, GameMat* temppBCM, long int beginTime)										
{	
	system("cls");
	if(temppGM->findInMat(3))					//�ж��Ƿ�Ϊ����׶�������Ϸ
	{
		temppBCM->printWithColor(temppGM[0]);
		cout<<"\n\tYou Lose!!\n";
		long int GameTime = showGameTime(beginTime);
	}
	else
	{
		int row = temppGM[0].getRow();
		int col = temppGM[0].getCol();
		for(int i = 1; i < row; i++)
		{
			for(int j = 1; j < col; j++)
			{
				if(temppGM[0](i, j) == -1 )
					temppGM[0].changeMatItem(i, j, -2);				//�������±�ע�Դ�ӡ����ͬ��Ч��
			}
		}
		temppBCM->printWithColor(temppGM[0]);
		cout<<"\n\tYou Win!!\n";
		long int GameTime = showGameTime(beginTime);
		if((row==11)&&(col==11))
		{
			if(GameTime <= HeroList.getTime(SMALLMAP, THIRD))
			{
				cout<<"\t�������������մ�����(���س��������𳬹�20���ַ�)�� ";
				char tempname[21];
				cin.getline(tempname,20);
				HeroList.insertHero(SMALLMAP, tempname, GameTime);				//����Ҳ���߷ְ�
			}
		}
		if((row==18)&&(col==18))
		{
			if(GameTime <= HeroList.getTime(MEDIUMMAP, THIRD))
			{
				cout<<"\t�������������մ�����(���س��������𳬹�20���ַ�)�� ";
				char tempname[21];
				cin.getline(tempname,20);
				HeroList.insertHero(MEDIUMMAP, tempname, GameTime);
			}
		}
		if((row==18)&&(col==32))
		{
			if(GameTime <= HeroList.getTime(BIGMAP, THIRD))
			{
				cout<<"\t�������������մ�����(���س��������𳬹�20���ַ�)�� ";
				char tempname[21];
				cin.getline(tempname,20);
				HeroList.insertHero(BIGMAP, tempname, GameTime);
			}
		}
		HeroList.writeHeroList();							//���߷ְ�д���ļ�
	}
	
	cout<<"\n\t��0�����ز˵���";
	int tempch = 0;
	do
	{
		tempch = getch();
	}while(tempch != _ZERO);
}
long int showGameTime(long int beginTime)							
{
	long int nowTime = time(NULL);
	int GameMin = (nowTime - beginTime)/60;
	int GameSec = (nowTime - beginTime)%60;
	cout<<"\n\n\t��Ϸʱ�䣺 "<<GameMin<<" �� "<<GameSec<<" �� "<<endl;
	return nowTime - beginTime;				//����ֵΪ��Ϸʱ��
}