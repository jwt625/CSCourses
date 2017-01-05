///////////////////////////////////////////////////////
////                                                                      ////
////      MineSweeper by JWT     2013011717      ////
////		Department of Physics                             ////
////                                                                      ////
///////////////////////////////////////////////////////
#include<conio.h>				//getch()函数所需
#include<ctime>					//获取当前时间所需
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
//此函数通过当前游戏状态判断是否应该结束游戏
BOOL judge(GameMat*, GameMat* );
//此函数实现光标跟随鼠标移动和鼠标左键与右键点击的读入，返回值为点击类型
int mouse(int & i, int & j);
//此函数实现游戏初始菜单的打印与用户选择的获取
int startGame(int & row, int & col, int & numOB);
//此函数判断结束游戏后玩家是否获胜并打印相应结果
void WinOrLose(GameMat* temppGM, GameMat* temppBCM, long int beginTime);
//此函数打印出已经过的游戏时间
long int showGameTime(long int beginTime);
void getName();
//将高分榜声明为全局，方便使用
HEROS HeroList;						
int main()
{	
	int row, col, numOB;
	HeroList.getHeroList();
_begin:

	int ch = startGame(row, col, numOB);				//开始游戏并打印用户界面
	system("cls");
	GameMat tempGM(row+2, col+2, numOB);
	tempGM.initMat(0, 0, -1);
	if(ch == _FOUR)
		goto _end;
	
	tempGM.printWithColor(tempGM);							//打印尚未布雷的空白雷阵供获取玩家的第一次点击
	int tempcurrentX = 0, tempcurrentY = 0;
	do																			//生成雷阵前先获取一次鼠标点击，避免第一次点击即踩到雷
	{
			mouse(tempcurrentY, tempcurrentX);						//获取第一次鼠标点击
	}while(!((tempcurrentY<=col)&&(tempcurrentX<=row)&&(tempcurrentX>0)&&(tempcurrentY>0)));				//判断点击是否在有效区域内
	
	//第一次鼠标点击后获取游戏开始时间
	long int beginTime = time(NULL);																													

	//根据第一次鼠标点击的坐标生成雷阵
	GameMat* pGM = getNewpGameMat(row, col, numOB, tempcurrentX, tempcurrentY);								
	/*cout<<endl<<pGM->getNumberOfBomb()<<endl;
	pGM->printM();
	system("pause");*/
	GameMat* pBCM = getpBCMfrom(pGM);
	pBCM->manipulateLD(pGM, pBCM, tempcurrentX, tempcurrentY);													//对相应矩阵执行左键点击后的操作

	//pBCM->printM();	
	//pGM->printWithColor();
	//pBCM->printWithColor();
	do
	{
		system("cls");		
		//打印当前雷阵
		pBCM->printWithColor(pGM[0]);										
		//打印游戏时间
		showGameTime(beginTime);												
		/*pGM->printM();
		pBCM->printM();
		pBCM->printWithColor();
		cout<<tempcurrentX<<' '<<tempcurrentY<<endl;*/
		int opt = 0;
		do
		{
			opt = mouse(tempcurrentY, tempcurrentX);
		}while(!((tempcurrentY<pGM[0].getCol()-1)&&(tempcurrentX<pGM[0].getRow()-1)&&(tempcurrentX>0)&&(tempcurrentY>0)));		//判断点击是否在有效区域内

		//根据鼠标点击类型执行不同操作，0代表鼠标左键单击，1代表鼠标右键单击
		switch(opt)									
		{
		case 0:
			if((pGM->operator()(tempcurrentX+1, tempcurrentY+1) == 0)||(pGM->operator()(tempcurrentX+1, tempcurrentY+1) == -1))			//判断单击时应执行的操作类型
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
	}while(!judge(pGM, pBCM));																	//循环获取玩家鼠标操作直到判断游戏应当终止
	
	//判断游戏终止后的胜败情况
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
				count1++;												//对已探索到的方格进行计数
		}
	}
	return (count1 == (row - 2)*(col - 2) - numOfBomb)||(temppGM[0].findInMat(3));			//若已探索方格数为非雷方格数或已踩雷，则返回1
}
int mouse(int & i, int & j)																			
{
    DWORD dwMode, dwOldMode;                                                          /* 原来的模式与新模式 */
    DWORD dwRead;																	  /* 已经读取的输入事件数 */
    int mouse_pos;																	  /* 用于返回鼠标位置 */
    UINT count;																		  /* 用于循环控制 */
    INPUT_RECORD ir[128];															  /* 控制台输入记录 */
    CONSOLE_CURSOR_INFO cci, cciOld;												  /* 鼠标相关的设置 */
    COORD co;																		  /* 鼠标移动时更新坐标 */
    HANDLE hStdIn = NULL, hStdOut = NULL;											  /* 标准输入输出句柄  */


    hStdIn = GetStdHandle(STD_INPUT_HANDLE);										  /* 取得输入输出句柄 */
    hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

    if(!GetConsoleMode(hStdIn, &dwOldMode))											  /* 取得控制台原来的模式 */
    {
        fprintf(stderr, "GetConsoleMode 错误:%d\n", GetLastError());
        goto _exit;
    }
    dwMode = dwOldMode | ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;
    if(!SetConsoleMode(hStdIn, dwMode))												  /* 开启鼠标事件 */
    {
        fprintf(stderr, "SetConsoleMode 错误:%d\n", GetLastError());
        goto _exit;
    }

    GetConsoleCursorInfo(hStdOut, &cciOld);
    cci.bVisible = TRUE;															  /* 光标可见 */
    cci.dwSize = 100;																  /* 块状 */
    if(!SetConsoleCursorInfo(hStdOut, &cci))
    {
        fprintf(stderr, "SetConsoleCursorInfo 错误:%d\n", GetLastError());
        goto _exit;
    }

    for(;;)																			  /* 循环等待用户事件 */
    {
        if(!ReadConsoleInput(hStdIn, &ir[0], 128, &dwRead))
        {
            fprintf(stderr, "ReadConsoleInput 错误:%d\n", GetLastError());
            goto _exit;
        }
        for(count=0; count<dwRead; count++)
        {
            switch(ir[count].EventType)
            {
            case MOUSE_EVENT:
                switch(ir[count].Event.MouseEvent.dwEventFlags)
                {
                case MOUSE_MOVED:													  /* 更新鼠标位置 */
                    co.X = ir[count].Event.MouseEvent.dwMousePosition.X;
                    co.Y = ir[count].Event.MouseEvent.dwMousePosition.Y;
                    SetConsoleCursorPosition(hStdOut, co);   
					i = co.X / 2 -3;
					j = co.Y - 2;
					//cout<<"x: "<<i<<" y: "<<j;
                    break;
                case 0:																  /* 取得鼠标左键单击事件 */
                    if(ir[count].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)					//鼠标左键单击
                    {
						SetConsoleMode(hStdIn, dwOldMode);							  /* 还原原来的设置 */
                        SetConsoleCursorInfo(hStdOut, &cciOld);
                        mouse_pos = ir[count].Event.MouseEvent.dwMousePosition.X;
                        mouse_pos = mouse_pos << 16 | ir[count].Event.MouseEvent.dwMousePosition.Y;
                        return 0;
					}
					if(ir[count].Event.MouseEvent.dwButtonState == RIGHTMOST_BUTTON_PRESSED)						//鼠标右键单击
                    {
						SetConsoleMode(hStdIn, dwOldMode);							  /* 还原原来的设置 */
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
		HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);								/*初始化字体颜色为白色*/
		WORD att;   
		att = FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY;
		SetConsoleTextAttribute(handle, att);
		cout<<endl<<"\t\t游戏：扫雷\n\t\tv 1.1\n\n"<<"\t    请选择：\n\n"<<"  \t1. 开始游戏；\n\n"
			<<"  \t2. 游戏说明；\n\n"<<"  \t3. 扫雷英雄榜；\n\n"<<"  \t4. 退出游戏.\n\n\n\t\t\t\t--By JWT\n";
		do
		{
			ch = getch();																				/*用getch()函数得到输入，此方法较为安全，下同*/
		}while((ch != _ONE)&&(ch != _TWO)&&(ch != _THREE)&&(ch != _FOUR));				//玩家未输入1，2，3或4时持续请求输入，下同

		
		if(ch == _FOUR)													//退出游戏
			break;

		if(ch == _ONE)
		{
#pragma region OptionOne_GameStart
			int n1 = 0;
			int step = 0;			
			_pre:
			system("cls");
			cout<<endl<<"\t\t请选择游戏难度：\n\n"<<"  \t1. 初级：9*9个方块，10个雷；\n\n"<<"  \t2. 中级：16*16个方块，40个雷；\n\n"
				<<"  \t3. 高级：16*30个方块，99个雷；\n\n"<<"  \t4.自定义；\n\n"<<"\t按0键返回菜单：";
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
							cout<<endl<<"\t请输入 5 ~ 50 间的行数(以英文句号\".\"结束)：";
							n2 = 0;
							row = 0;
							while(1)															/*此部分的输入仍采用getch()以保证输入的robust*/
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
									row = 10*row +n2 - _ZERO;						//	将连续输入的字符型数字转换为数
								}
							}
							if((row<5)||(row>50))
								goto _input;
							cout<<endl<<"\t您输入的行数为： "<<row<<endl<<"\n\t请输入 5 ~ 30 间的列数(以英文句号\".\"结束)：";
							n2 = 0;
							col = 0;
							while(1)
							{
								if(n2 == (int)'.')
									break;
								do
								{
									n2 = getch();
								}while((n2 !=48)&&(n2 !=49)&&(n2 !=50)&&(n2 !=51)&&(n2 !=52)&&(n2 != 53)&&(n2 !=54)&&(n2 !=55)&&(n2 !=56)&&(n2 !=57)&&(n2 !=(int)'.'));		//用户未输入数字或英文句号时持续请求输入，下同
								if(n2 != (int)'.')
								{
									cout<<(n2-_ZERO);
									col = 10*col +n2 - _ZERO;
								}
							}
							if((col<5)||(col>30))
								goto _input;
							cout<<endl<<"\t您输入的列数为： "<<col<<endl<<"\n\t请输入 5 ~ 行数*列数 间的雷数(以英文句号\".\"结束)：";
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
							cout<<endl<<"\t您输入的雷数为： "<<numOB<<endl<<"\n\t按0键取消并返回上一菜单，按1键确认：";
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
		
		if(ch == _TWO)															/*说明游戏规则*/
		{
#pragma region OptionTwo_Instructions
			int n1 = 0;
			
				system("cls");
				cout<<"\n\n\t游戏目的：游戏目标是在最短的时间内根据点击格子出现的数字\n\t        找出所有非雷格子，同时避免踩雷。\n\n"
					<<"\t一、用鼠标左键点击白色圆点即可打开格子。\n\n";
				cout<<"\t二、成功被探索的格子将显示√, ①, ②等，其中√表示安全地带，\n\t    带圆圈的数字表示相邻8格中雷的数目。\n\n";
				cout<<"\t三、鼠标右键单击未探索过的格子即可标注地雷，将显示：";
				HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
				WORD att;   
				att = FOREGROUND_RED|FOREGROUND_INTENSITY;
				SetConsoleTextAttribute(handle, att);
				cout<<IsBOMB;
				handle = GetStdHandle(STD_OUTPUT_HANDLE);		
				att = FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY;
				SetConsoleTextAttribute(handle, att);
				cout<<", \n\t    再次单击右键即可取消标注地雷。\n\n";
				cout<<"\t四、鼠标左键单击已探索过的且相邻8格中有雷的格子，即可根据周围\n\t    地雷的标注情况自动打开“安全”的格子，与一般扫雷游戏的双键\n\t    同时点击的效果相同。\n\n";
				cout<<"\t五、正确找出所有非雷格子后即可获得胜利，若踩到地雷则游戏失败，\n\t    所有地雷都将显示出来，被踩的地雷则将高亮显示。\n\n";
				cout<<"\t备注：生成雷阵的过程可能耗时0.2秒左右，而若您选择了自定义雷阵，\n\t      则可能耗时略微更久，请您耐心等待。\n"
					<<"\n\t      游戏时间会在第一次点击鼠标开始游戏时开始计时，\n\t      每一次点击鼠标后才会更新游戏时间的显示，请勿误认为游戏时间暂停。\n\n";
				cout<<"\t按0返回菜单：";
			do
			{
				n1 = getch();
				if(n1 == _ZERO) break;
			}while(n1 != _ZERO);
#pragma endregion
		}

		if(ch == _THREE)															/*查看高分榜*/
		{
#pragma region OptionThree_HeroList
			int n1;			
			system("cls");
			HeroList.getAndPrintHeroList();							//从文件读取并打印高分榜
			cout<<"\n\n\t按0键返回菜单：";
			do
			{
				n1 = getch();
				if(n1 == _ZERO) break;
			}while(n1 != _ZERO);
		}
#pragma endregion
	}
	return ch;				//返回用户最初的选择，是否结束程序的判断与操作需在主函数中执行
}
void WinOrLose(GameMat* temppGM, GameMat* temppBCM, long int beginTime)										
{	
	system("cls");
	if(temppGM->findInMat(3))					//判断是否为因踩雷而结束游戏
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
					temppGM[0].changeMatItem(i, j, -2);				//将雷重新标注以打印出不同的效果
			}
		}
		temppBCM->printWithColor(temppGM[0]);
		cout<<"\n\tYou Win!!\n";
		long int GameTime = showGameTime(beginTime);
		if((row==11)&&(col==11))
		{
			if(GameTime <= HeroList.getTime(SMALLMAP, THIRD))
			{
				cout<<"\t高手请输入尊姓大名！(按回车结束，勿超过20个字符)： ";
				char tempname[21];
				cin.getline(tempname,20);
				HeroList.insertHero(SMALLMAP, tempname, GameTime);				//将玩家插入高分榜
			}
		}
		if((row==18)&&(col==18))
		{
			if(GameTime <= HeroList.getTime(MEDIUMMAP, THIRD))
			{
				cout<<"\t高手请输入尊姓大名！(按回车结束，勿超过20个字符)： ";
				char tempname[21];
				cin.getline(tempname,20);
				HeroList.insertHero(MEDIUMMAP, tempname, GameTime);
			}
		}
		if((row==18)&&(col==32))
		{
			if(GameTime <= HeroList.getTime(BIGMAP, THIRD))
			{
				cout<<"\t高手请输入尊姓大名！(按回车结束，勿超过20个字符)： ";
				char tempname[21];
				cin.getline(tempname,20);
				HeroList.insertHero(BIGMAP, tempname, GameTime);
			}
		}
		HeroList.writeHeroList();							//将高分榜写入文件
	}
	
	cout<<"\n\t按0键返回菜单：";
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
	cout<<"\n\n\t游戏时间： "<<GameMin<<" 分 "<<GameSec<<" 秒 "<<endl;
	return nowTime - beginTime;				//返回值为游戏时间
}