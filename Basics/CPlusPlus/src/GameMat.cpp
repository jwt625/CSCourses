#include"GameMat.h"

MATRIX::MATRIX(int row, int col)
{
	m_row = row;
	m_col = col;
	initMat();
}
int  MATRIX::operator()(int x, int y)const
{
	return m_MAT[x-1][y-1];
}
void MATRIX::initMat(int addRow, int addCol, int val)
{
	m_row += addRow;
	m_col += addCol;
	m_MAT = new pARY[m_row];
	for(int i = 0; i < m_row; i++)
		m_MAT[i] = new int [m_col];
	for(int i = 0; i < m_row; i++)
	{
		for(int j = 0; j < m_col; j++)
			m_MAT[i][j] = val;
	}
}
void MATRIX::printM()const
{	
	for(int i = 0; i < m_row; i++)
	{
		for(int j = 0; j < m_col; j++)
		{
			cout<<m_MAT[i][j]<<' ';
		}
		cout<<endl;
	}
}
void MATRIX::changeMatItem(int x, int y, int input)
{
	if((x <= m_row)&&(y <= m_col)&&(x >= 1)&&(y >= 1))
		m_MAT[x-1][y-1] = input;
}
void MATRIX::operator=(MATRIX tempM)
{	
	m_row = tempM.m_row;
	m_col = tempM.m_col;
	m_MAT = new pARY[m_row];
	for(int i = 0; i < m_row; i++)
		m_MAT[i] = new int [m_col];
	for(int i = 0; i < m_row; i++)
	{
		for(int j = 0; j < m_col; j++)
		{
			m_MAT[i][j] = tempM(i+1,j+1);
		}
	}
}   
BOOL MATRIX::findInMat(int toFind)const
{
	for(int i = 0; i < m_row; i++)
	{
		for(int j = 0; j < m_col; j++)
		{
			if(m_MAT[i][j] == toFind)
				return TRUE;
		}
	}
	return FALSE;
}
int MATRIX::countInMat(int toCount)const
{
	int count = 0;
	for(int i = 0; i < m_row; i++)
	{
		for(int j = 0; j < m_col; j++)
		{
			if(m_MAT[i][j] == toCount)
				count++;
		}
	}
	return count;
}

GameMat::GameMat(int row, int col, int numOfBomb):MATRIX(row, col)
{
	if((row-2)*(col-2) <= numOfBomb)
		m_numOfBomb = 0;
	else
		m_numOfBomb = numOfBomb;
}
void GameMat::GenerateGM(int addBomb, int currentX, int currentY)
{
	m_numOfBomb += addBomb;
	currentX++;
	currentY++;
	int row = MATRIX::getRow();
	int col = MATRIX::getCol();	
	if((row-2)*(col-2) <= m_numOfBomb)
		m_numOfBomb = 0;
	int num = m_numOfBomb;
	if(num < (row-2)*(col-2)/2)											//雷数小于总数的一半时随机生成雷的坐标，反之生成非雷的坐标
	{
		MATRIX::changeMatItem(currentX, currentY, 1);		//标记玩家第一次单击位置，不参与随机生成的雷的坐标
		srand( (unsigned)GetCurrentTime());							//从当前时间获取随机数种子
		while(num > 0)
		{
			int x, y;
			do												//get the positions of bombs randomly
			{
				x = rand()%(row-2) + 2;
				y = rand()%(col-2) + 2;
			}while(MATRIX::operator()(x, y) != 0);
			MATRIX::changeMatItem(x, y, -1)	;			//'-1' for positions with bombs
			num--;
		}
		MATRIX::changeMatItem(currentX, currentY, 0);		//去除对第一次单击位置的标记
	}
	else
	{
		for(int i = 1; i < row -1; i++)				//initializing all MAT item to be bombs
		{
			for(int j = 1; j < col -1; j++)
				MATRIX::changeMatItem(i+1,j+1,-1);									//'-1' for positions with bombs
		}
		MATRIX::changeMatItem(currentX, currentY, 0);							//标记玩家第一次单击位置，不参与随机生成的雷的坐标
		num++;
		srand( (unsigned)GetCurrentTime());
		while((col-2)*(row-2) - num > 0)
		{
			int x, y;
			do												//get the positions of no bomb randomly
			{				
				x = rand()%(row-2) + 2;
				y = rand()%(col-2) + 2;
			}while(MATRIX::operator()(x,y) != -1);			
			MATRIX::changeMatItem(x,y,0);
			num++;
		}
	}
}
void GameMat::GenerateBCMfrom(GameMat tempGM)
{
	initMat(tempGM.getRow()-1,tempGM.getCol()-1);
	int row = MATRIX::getRow();
	int col = MATRIX::getCol();
	for(int i = 2; i < row; i++)
	{
		for(int j = 2; j< col; j++)
		{
			if (tempGM(i, j) != -1)
			{
				int bombcount = 0;
				for(int p = -1; p <= 1; p++)							//对周围8格中的雷数进行计数
				{
					for(int q = -1; q<= 1; q++)
					{
						if( tempGM(i+p, j+q) == -1)		
							bombcount++;
					}
				}
				MATRIX::changeMatItem(i, j, bombcount);
			}
			else
				MATRIX::changeMatItem(i, j, -1);
		}
	}
}
void GameMat::printWithColor()const
{
	int row = MATRIX::getRow();
	int col = MATRIX::getCol();
	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < col; j++)
		{
			if((i == 0)||(i == row -1))
			{
				cout<<j<<' ';
			}
			else if((j == 0)||(j == col -1))
			{
				cout<<i<<' ';
			}
			else
			{
				switch(MATRIX::operator()(i+1, j+1))
				{
				case -1:						//打印红点
				{
					HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
					WORD att;   
					att = FOREGROUND_RED|FOREGROUND_INTENSITY;
					SetConsoleTextAttribute(handle, att);
					cout<<DOT;		
					handle = GetStdHandle(STD_OUTPUT_HANDLE);		
					att = FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY;
					SetConsoleTextAttribute(handle, att);
					break;
				}
				case 0:						//打印白点
				{
					cout<<DOT;
					break;
				}
				case 1:
				{
					cout<<CIR_1;
					break;
				}
				case 2:
				{
					cout<<CIR_2;
					break;
				}
				case 3:
				{
					cout<<CIR_3;
					break;
				}
				case 4:
				{
					cout<<CIR_4;
					break;
				}
				case 5:
				{
					cout<<CIR_5;
					break;
				}
				case 6:
				{
					cout<<CIR_6;
					break;
				}
				case 7:
				{
					cout<<CIR_7;
					break;
				}
				case 8:
				{
					cout<<CIR_8;
					break;
				}
				}		
			}
		}
		cout<<endl;
	}
}
void GameMat::printWithColor(GameMat tempGM)const
{
	int row = MATRIX::getRow();
	int col = MATRIX::getCol();
	int restBomb = tempGM.m_numOfBomb - tempGM.countInMat(-2);
	cout<<endl;
	cout<<"\t剩余雷数： "<<restBomb<<endl;				//打印剩余雷数
	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < col; j++)
		{
			if((i == 0)||(i == row -1))
			{
				/*cout<<j<<' ';*/
			}
			else if((j == 0)||(j == col -1))
			{
				//cout<<i<<' ';
				cout<<'\t';
			}
			else
			{
				if(tempGM(i+1, j+1) > 0)
				{
					switch(MATRIX::operator()(i+1, j+1))
				{
				case -2:
				{
					HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
					WORD att;   
					att = FOREGROUND_RED|FOREGROUND_INTENSITY;
					SetConsoleTextAttribute(handle, att);
					if(tempGM(i+1, j+1) == 3)			//游戏结束前打印意为被标记的红色带圈点，游戏结束后则打印红点
					{
						cout<<DOT;
					}
					else
					{
						cout<<IsBOMB;
					}
					handle = GetStdHandle(STD_OUTPUT_HANDLE);		
					att = FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY;
					SetConsoleTextAttribute(handle, att);
					break;
				}
				case -1:
				{
					HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
					WORD att;   
					att = FOREGROUND_RED;
					SetConsoleTextAttribute(handle, att);
					if(tempGM(i+1, j+1) == 3)
					{
						cout<<DOT;
					}
					else
					{
						cout<<IsBOMB;
					}				
					handle = GetStdHandle(STD_OUTPUT_HANDLE);		
					att = FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY;
					SetConsoleTextAttribute(handle, att);
					break;
				}
				case 0:			
				{
					cout<<CLEARED;
					break;
				}
				case 1:
				{
					cout<<CIR_1;
					break;
				}
				case 2:
				{
					cout<<CIR_2;
					break;
				}
				case 3:
				{
					cout<<CIR_3;
					break;
				}
				case 4:
				{
					cout<<CIR_4;
					break;
				}
				case 5:
				{
					cout<<CIR_5;
					break;
				}
				case 6:
				{
					cout<<CIR_6;
					break;
				}
				case 7:
				{
					cout<<CIR_7;
					break;
				}
				case 8:
				{
					cout<<CIR_8;
					break;
				}
				}		
				}
				else if(tempGM(i+1, j+1) == -2)
				{
					HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
					WORD att;   
					att = FOREGROUND_RED|FOREGROUND_INTENSITY;
					SetConsoleTextAttribute(handle, att);
					cout<<IsBOMB;				
					handle = GetStdHandle(STD_OUTPUT_HANDLE);		
					att = FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY;
					SetConsoleTextAttribute(handle, att);
				}
				else
				{
					HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
					WORD att;   
					att = FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY;
					SetConsoleTextAttribute(handle, att);
					cout<<DOT;
				}
			}
		}
		cout<<endl;
	}
}
void GameMat::manipulateLD(GameMat* temppGM, GameMat* temppBCM, int currentX, int currentY)
{
	int row, col;
	row = MATRIX::getRow();
	col = MATRIX::getCol();
	currentX++;						//由于getMatItem等函数取矩阵中值均从1开始取，且矩阵四周有防溢出留出的空白，因此需对坐标均加一
	currentY++;
	
	if(temppBCM[0](currentX, currentY) == -1)
	{
		temppGM[0].initMat( 0, 0, 3);
		temppBCM[0].changeMatItem( currentX, currentY, -2);
	}
	else
	{
		if((temppBCM[0](currentX, currentY) != 0)&&(temppGM[0](currentX, currentY) == 0))
		{
			temppGM[0].changeMatItem(currentX, currentY, 2);
		}
		else if(temppGM[0](currentX, currentY) == 0)
		{
			temppGM[0].changeMatItem(currentX, currentY, 1);
			int k= 0 , count = 0;
			while(1)
			{
				k = count;
				for(int p=2;p<row;p++)
				{			
					for(int q=2;q<col;q++)
					{						
						if((temppBCM[0](p, q) == 0) && (temppGM[0](p+1, q) == 1)&&(temppGM[0](p, q) == 0))
						{
							temppGM[0].changeMatItem(p, q, 1);
							count++;
						}
						if((temppBCM[0](p, q) == 0) && (temppGM[0](p-1, q) == 1)&&(temppGM[0](p, q) == 0))
						{
							temppGM[0].changeMatItem(p, q, 1);
							count++;
						}
						if((temppBCM[0](p, q) == 0) && (temppGM[0](p, q+1) == 1)&&(temppGM[0](p, q) == 0))
						{
							temppGM[0].changeMatItem(p, q, 1);
							count++;
						}
						if((temppBCM[0](p, q) == 0) && (temppGM[0](p, q-1) == 1)&&(temppGM[0](p, q) == 0))
						{
							temppGM[0].changeMatItem(p, q, 1);
							count++;
						}
					}					
				}
				if(k==count) break;
			}
			for(int p=2;p<row;p++)
			{
				for(int q=2;q<col;q++)
				{
					for(int i = -1; i <= 1; i++)
					{
						for(int j = -1; j<= 1; j++)
						{
							if((temppGM[0](i+p, j+q) == 1)&&(temppGM[0](p, q) != 1)&&(temppGM[0](p, q) != -1)&&(temppGM[0](p, q) != -2))
								temppGM[0].changeMatItem(p, q, 2);
						}
					}
				}
			}
		}
	}
}
void GameMat::manipulateRD(GameMat* temppGM, GameMat* temppBCM, int currentX, int currentY)
{
	int row, col;
	row = MATRIX::getRow();
	col = MATRIX::getCol();
	currentX++;
	currentY++;
	if((temppGM[0](currentX, currentY) == 0)||(temppGM[0](currentX, currentY) == -1))
		temppGM[0].changeMatItem(currentX, currentY, -2);
	else if((temppGM[0](currentX, currentY) == -2))
		temppGM[0].changeMatItem(currentX, currentY, 0);
}
void GameMat::manipulateBothD(GameMat* temppGM, GameMat* temppBCM, int currentX, int currentY)
{
	int row, col;
	row = MATRIX::getRow();
	col = MATRIX::getCol();
	currentX++;
	currentY++;
	if((temppBCM[0](currentX, currentY) > 0)&&(temppGM[0](currentX, currentY) > 0))
	{
		int count = 0;
		for(int p = -1; p <= 1; p++)
		{
			for(int q = -1; q<= 1; q++)
			{
				if( temppGM[0](currentX+p, currentY+q) == -2)		
					count++;
			}
		}
		if(count == temppBCM[0](currentX, currentY))
		{
			for(int p = -1; p <= 1; p++)
			{
				for(int q = -1; q<= 1; q++)
				{
					if((temppGM[0](currentX+p, currentY+q) != -2)&&(temppGM[0](currentX+p, currentY+q) < 1))
						if((currentX+p != 1)&&(currentY+q != 1)&&(currentX+p != row)&&(currentY+q != col))
							temppBCM[0].manipulateLD(temppGM, temppBCM, currentX+p-1, currentY+q-1);
				}
			}
		}
	}
}