#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <string.h>
int game_start();
int mouse();
int adjust();
int reprint(int *ps);
int judge();
int rdlist();
int prtlist();
int wrtlist(int *ps);
int wrtjudge();
int mat[22][22];													/*mat[22][22]四周留空防止溢出*/
int i = 0, j = 0, score = 0, n;
typedef struct
{
	char name[20];
	int score;
	int step;
} plist;
plist ply1[5];														/*用于存储排行榜的数组*/
plist ply2[5];
int main()
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);					/*调整字体颜色，防止循环后字体颜色不为白色*/
	WORD att;  
	att = FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY;
	SetConsoleTextAttribute(handle, att);

	while(1)															/*使用永真循环达到持续运行的效果*/
	{
		rdlist();
		int ch;																  
		do
		{
			system("cls");
			printf("\n");
			printf("  游戏 : 彩色泡泡\n\n");
			printf("  请选择：\n");
			printf("  1. 开始游戏；\n");
			printf("  2. 游戏说明；\n");
			printf("  3. 得分排行榜；\n");
			printf("  4. 退出游戏.\n");
			ch = getch();												/*用getch()函数得到输入*/
		}while((ch != 49)&&(ch != 50)&&(ch != 51)&&(ch != 52));						/*getch()返回值为ASC码，字符0对应整数48，下文中类似*/

		if(ch == 49)
		{
			int n1;
			int step = 0;
			do
			{
				system("cls");
				printf("\n");
				printf("请选择游戏规模：\n\n");
				printf("  1. 小型：10*10；\n");
				printf("  2. 大型：20*20；\n\n");
				printf("按0键返回菜单：");
				n1 = getch();
			}while((n1 != 48)&&(n1 != 49)&&(n1 != 50));					  
			if(n1 == 48) continue;
			n = n1 - 48;
			game_start();
			score = 0;
			do
			{
				do																/*持续读入鼠标的输入直到符合消去规则*/
				{
					mouse();
				}while(((mat[i][j]!=mat[i-1][j])&&(mat[i][j]!=mat[i+1][j])&&(mat[i][j]!=mat[i][j-1])&&(mat[i][j]!=mat[i][j+1]))
					||(i>10*n)||(j>10*n)||(mat[i][j]<0));
				adjust();														/*调整mat[22][22]中的颜色数据*/
				step++;
				reprint(&step);													/*重新打印泡泡*/
			}while(judge());
			printf("\n\n    游戏结束！\n\n    您的得分是：%d, 您使用了%d步\n\n", score, step);
			if(wrtjudge())														/*判断是否进入高分榜*/
			{
				printf("    高手请留下您的尊姓大名(20个字符以内且勿含有空格)：");
				wrtlist(&step);
			}
			else printf("您的功力不足，继续加油吧！");
			printf("\n    按0键返回菜单：");
			do
			{
				n1 = getch();
			}while(n1 != 48);
			if(n1 == 48) continue;
		}

		if(ch == 50)															/*说明游戏规则*/
		{
			int n1;
			do
			{
				system("cls");
				printf("\n");
				printf("游戏目的：尽可能地消去泡泡。\n\n");
				printf("          1.用鼠标点击上下左右有相同颜色的泡泡时即可将它们消去\n");
				printf("          2.如果点击的为一个被其他颜色包围的单一的泡泡，则无法消去。\n");
				printf("          3.下方泡泡被消去，则上方泡泡将竖直下落，若一列完全被消去，则其左方的所有泡泡整体向右平移一列。\n");
				printf("          4.当游戏中已经没有可以消去的泡泡时，游戏结束\n");
				printf("          5.得分计算方式：一次操作消掉x个相连的同色泡泡，则得分为x^2，因此一次性消去个数越多得分越高。\n\n");
				printf("按0返回菜单：");
				n1 = getch();
				if(n1 == 48) break;
			}while(n1 != 48);
		}

		if(ch == 51)															/*查看高分榜*/
		{
			int n1;
			do
			{
				system("cls");
				prtlist();
				printf("\n\n  按0键返回菜单：");
				n1 = getch();
				if(n1 == 48) break;
			}while(n1 != 48);
		}

		if(ch == 52) break;
	}
	system("exit");
}
int game_start()																/*此函数实现开局mat[22][22]的随机生成与打印*/
{
	system("cls");
	printf("用鼠标点击上下左右有相同颜色的泡泡来将它们消去:\n\n");

		i = 0;
		while(i<100*n*n)
		{
			j = i / (10*n) + 1;
			mat[(i%(10*n))+1][j] = rand()%4 + 1;
			switch(mat[(i%(10*n))+1][j])															  /*泡泡颜色控制*/
			{
				case 1:
				{
					HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
					WORD att;  
					att = FOREGROUND_GREEN|FOREGROUND_INTENSITY;
					SetConsoleTextAttribute(handle, att);
					printf("●");
					break;
				}
				case 2:
				{
					HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
					WORD att;   
					att = FOREGROUND_RED|FOREGROUND_INTENSITY;
					SetConsoleTextAttribute(handle, att);
					printf("●");
					break;
				}
				case 3:
				{
					HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
					WORD att;  
					att = FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY;
					SetConsoleTextAttribute(handle, att);
					printf("●");
					break;
				}
				case 4:
				{
					HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
					WORD att;  
					att = FOREGROUND_BLUE|FOREGROUND_INTENSITY;
					SetConsoleTextAttribute(handle, att);
					printf("●");
					break;
				}
			}
			i++;
			if(i/(10*n)+1>j) printf("\n");
		}		
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);											 /*将字体颜色调回白色*/
	WORD att;  
	att = FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY;
	SetConsoleTextAttribute(handle, att);
	return(0);
}
int mouse()														/*此函数实现光标跟随鼠标移动和鼠标左键点击的读入(此函数中以%开头的注释为代码原作者所加)*/
{
    DWORD dwMode, dwOldMode;                                                          /* %原来的模式与新模式 */
    DWORD dwRead;																	  /* %已经读取的输入事件数 */
    int mouse_pos;																	  /* %用于返回鼠标位置 */
    UINT count;																		  /* %用于循环控制 */
    INPUT_RECORD ir[128];															  /* %控制台输入记录 */
    CONSOLE_CURSOR_INFO cci, cciOld;												  /* %鼠标相关的设置 */
    COORD co;																		  /* %鼠标移动时更新坐标 */
    HANDLE hStdIn = NULL, hStdOut = NULL;											  /* %标准输入输出句柄  */


    hStdIn = GetStdHandle(STD_INPUT_HANDLE);										  /* %取得输入输出句柄 */
    hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

    if(!GetConsoleMode(hStdIn, &dwOldMode))											  /* %取得控制台原来的模式 */
    {
        fprintf(stderr, "GetConsoleMode 错误:%d\n", GetLastError());
        goto _exit;
    }
    dwMode = dwOldMode | ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;
    if(!SetConsoleMode(hStdIn, dwMode))												  /* %开启鼠标事件 */
    {
        fprintf(stderr, "SetConsoleMode 错误:%d\n", GetLastError());
        goto _exit;
    }

    GetConsoleCursorInfo(hStdOut, &cciOld);
    cci.bVisible = TRUE;															  /* %光标可见 */
    cci.dwSize = 100;																  /* %块状 */
    if(!SetConsoleCursorInfo(hStdOut, &cci))
    {
        fprintf(stderr, "SetConsoleCursorInfo 错误:%d\n", GetLastError());
        goto _exit;
    }

    for(;;)																			  /* %循环等待用户事件 */
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
                case MOUSE_MOVED:													  /* %更新鼠标位置 */
                    co.X = ir[count].Event.MouseEvent.dwMousePosition.X;
                    co.Y = ir[count].Event.MouseEvent.dwMousePosition.Y;
                    SetConsoleCursorPosition(hStdOut, co);   
					i = co.X / 2 + 1;												  /*取得鼠标位置*/
					j = co.Y - 1;
                    break;
                case 0:																  /*取得鼠标单击事件*/
                    if(ir[count].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
                    {
						SetConsoleMode(hStdIn, dwOldMode);							  /* %还原原来的设置 */
                        SetConsoleCursorInfo(hStdOut, &cciOld);
                        mouse_pos = ir[count].Event.MouseEvent.dwMousePosition.X;
                        mouse_pos = mouse_pos << 16 | ir[count].Event.MouseEvent.dwMousePosition.Y;
                        return mouse_pos;
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
    return 1;
}
int adjust()																	/*此函数实现泡泡按照游戏规则的调整*/
{
	int count=1, move, p, q, k;
	mat[i][j] = mat[i][j] - 8;
	while(1)																			/*标记应消去的泡泡*/
	{
		k = count;
		for(p=1;p<=10*n;p++)
		{
			for(q=1;q<=10*n;q++)
			{
				if(mat[p][q]==mat[p+1][q]+8)
				{
					mat[p][q]=mat[p+1][q];
					count++;
				}
				if(mat[p][q]==mat[p-1][q]+8)
				{
					mat[p][q]=mat[p-1][q];
					count++;
				}
				if(mat[p][q]==mat[p][q+1]+8)
				{
					mat[p][q]=mat[p][q+1];
					count++;
				}
				if(mat[p][q]==mat[p][q-1]+8)
				{
					mat[p][q]=mat[p][q-1];
					count++;
				}
			}
		}
		if(k==count) break;															/*循环直到没有新的泡泡被标记*/
	}
	score = score + count*count;													/*计算得分*/
	k = 0;
	do
	{
		for(p=10*n;p>0;p--)																/*将消去的空位上移*/
		{
			move = 0;
			q=10*n;
			while(mat[p][q]>0) q--;
			if(q<1) continue;
			while(mat[p][q-move]<=0) 
			{
				mat[p][q-move] = -10;
				move++;
				if(q-move<1) break;
			}
			if((q-move<1)&&(move < 10*n)) continue;
			if(q-move>=1)
			{
				while(mat[p][q-move]>0)
				{
					mat[p][q] = mat[p][q-move];
					mat[p][q-move] = -10;
					q--;
				}
			}
		}
		k++;
	}while(k<9);																	/*该算法将空位移至遇见上方空位为止，因此最糟糕的情况需连续运行9次*/														
																			
	for(p=10*n;p>0;p--)																/*若有空列则将左方所有列右移*/
	{
		q = 10*n;
		move = 0;
		while(mat[p][q]>0) p--;
		while(mat[p-move][q]<=0) move++;
		for(k=p;k-move>0;k--)
		{
			for(q=10*n;q>0;q--)
			{
				mat[k][q] = mat[k-move][q];
				mat[k-move][q] = -10;
			}
		}
	}
	return(0);
}
int reprint(int *ps)																/*此函数将调整后的mat[22][22]重新打印*/
{
	system("cls");
	printf("用鼠标点击上下左右有相同颜色的泡泡来将它们消去:\n\n");

	i = 0;
	while(i<100*n*n)
	{
		j = i / (10*n) + 1;
		switch(mat[(i%(10*n))+1][j])															  /*泡泡颜色控制*/
		{
			case 1:
			{
				HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
				WORD att;  
				att = FOREGROUND_GREEN|FOREGROUND_INTENSITY;
				SetConsoleTextAttribute(handle, att);
				printf("●");
				break;
			}
			case 2:
			{
				HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
				WORD att;   
				att = FOREGROUND_RED|FOREGROUND_INTENSITY;
				SetConsoleTextAttribute(handle, att);
				printf("●");
				break;
			}
			case 3:
			{
				HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
				WORD att;  
				att = FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY;
				SetConsoleTextAttribute(handle, att);
				printf("●");
				break;
			}
			case 4:
			{
				HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
				WORD att;  
				att = FOREGROUND_BLUE|FOREGROUND_INTENSITY;
				SetConsoleTextAttribute(handle, att);
				printf("●");
				break;
			}
			case -10:
			{
				printf("  ");
				break;
			}
		}
		i++;
		if(i/(10*n)+1>j) printf("\n");
	}
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);											 /*将字体颜色调回白色*/
	WORD att;  
	att = FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY;
	SetConsoleTextAttribute(handle, att);
	printf("\n    得分:%d     使用步骤:%d", score, *ps);
	return(0);
}
int judge()																	/*此函数判断游戏是否结束*/
{
	int a, b, v=0;
	for(a=n*10;mat[a][10*n]>0;a--)
	{
		for(b=n*10;mat[a][b]>0;b--)
		{
			if(mat[a][b]<0) continue;
			if((mat[a][b]==mat[a-1][b])||(mat[a][b]==mat[a+1][b])||(mat[a][b]==mat[a][b-1])||(mat[a][b]==mat[a][b+1]))
			{
				v = 1;
				break;
			}
		}
		if(v==1) break;
	}
	return(v);
}
int wrtlist(int *ps)																/*此函数将高分榜的两个结构体数组中的信息写进外部txt文件*/
{
	FILE *fp;
	char name[20];
	int k, l;
	
	gets(name);
	if(n == 1)
	{
		k = 0;
		while((score<ply1[k].score)&&(k<5)) k++;
		for(l=4;l>k;l--)
		{
			ply1[l]=ply1[l-1];
		}
		strcpy(ply1[k].name, name);
		ply1[k].score = score;
		ply1[k].step = *ps;
		fp = fopen("plist1.txt", "w");
		k = 0;
		fprintf(fp, "%s %d %d\n", ply1[k].name, ply1[k].score, ply1[k].step);
		fclose(fp);
		fp = fopen("plist1.txt", "a");
		k = 1;
		while(k<5)
		{
			fprintf(fp, "%s %d %d\n", ply1[k].name, ply1[k].score, ply1[k].step);
			k++;
		}
		fclose(fp);
	}
	if(n == 2)
	{
		k = 0;
		while((score<ply2[k].score)&&(k<5)) k++;
		for(l=4;l>k;l--)
		{
			ply2[l]=ply2[l-1];
		}
		strcpy(ply2[k].name, name);
		ply2[k].score = score;
		ply2[k].step = *ps;
		fp = fopen("plist2.txt", "w");
		k = 0;
		fprintf(fp, "%s %d %d\n", ply2[k].name, ply2[k].score, ply2[k].step);
		fclose(fp);
		fp = fopen("plist2.txt", "a");
		k = 1;
		while(k<5)
		{
			fprintf(fp, "%s %d %d\n", ply2[k].name, ply2[k].score, ply2[k].step);
			k++;
		}
		fclose(fp);
	}
	return(0);
}
int rdlist()																			/*此函数将txt中存储的高分榜信息读入结构体数组，若为空则生成默认文件及结构体数组*/
{
	FILE *fp;
	char line[30];
	int k;

	fp = fopen("plist1.txt", "r");
	if(fp == NULL)																		/*若文件为空则创建名称为"null"，得分与步数均为0的高分榜信息文件*/
	{
		for(k=0;k<5;k++)
		{
			strcpy(ply1[k].name , "null");
			ply1[k].score = 0;
			ply1[k].step = 0;
		}
		fp = fopen("plist1.txt", "w");
		k = 4;
		fprintf(fp, "%s %d %d\n", ply1[k].name, ply1[k].score, ply1[k].step);
		fclose(fp);
		fp = fopen("plist1.txt", "a");
		k = 3;
		while(k>=0)
		{
			fprintf(fp, "%s %d %d\n", ply1[k].name, ply1[k].score, ply1[k].step);
			k--;
		}
		fclose(fp);
	}
	else
	{
		k = 0;
		do
		{
			fscanf(fp, "%s %d %d", &ply1[k].name, &ply1[k].score, &ply1[k].step);
			k++;
		}while(fgets(line, 30, fp) != NULL);
	}

	fp = fopen("plist2.txt", "r");
	if(fp == NULL)
	{
		for(k=0;k<5;k++)
		{
			strcpy(ply2[k].name , "null");
			ply2[k].score = 0;
			ply2[k].step = 0;
		}
		fp = fopen("plist2.txt", "w");
		k = 4;
		fprintf(fp, "%s %d %d\n", ply2[k].name, ply2[k].score, ply2[k].step);
		fclose(fp);
		fp = fopen("plist2.txt", "a");
		k = 3;
		while(k>=0)
		{
			fprintf(fp, "%s %d %d\n", ply2[k].name, ply2[k].score, ply2[k].step);
			k--;
		}
		fclose(fp);
	}
	else
	{
		k = 0;
		do
		{
			fscanf(fp, "%s %d %d", &ply2[k].name, &ply2[k].score, &ply2[k].step);
			k++;
		}while(fgets(line, 30, fp) != NULL);
	}
	return(0);
}
int prtlist()																			/*此函数实现高分榜的打印*/
{
	printf("\t\t高分榜\n\n\n");
	printf("\t小型:\n\n");
	if(ply1[0].score<=0) printf("\t空空如也，赶快玩一把吧！");
	else
	{
		printf("\t名次\t姓名\t\t\t得分\t步数\n");
		for(i=0;(ply1[i].score>100)&&(i<5);i++)											/*根据玩家名称长短分类，以达到打印整齐的效果*/
		{
			if(strlen(ply1[i].name)<8) printf("\t%d\t%s\t\t\t%d\t%d\n", i+1, ply1[i].name, ply1[i].score, ply1[i].step);
			else if(strlen(ply1[i].name)<16) printf("\t%d\t%s\t\t%d\t%d\n", i+1, ply1[i].name, ply1[i].score, ply1[i].step);
			else printf("\t%d\t%s\t%d\t%d\n", i+1, ply1[i].name, ply1[i].score, ply1[i].step);
		}
	}
	printf("\n\n\t大型:\n\n");
	if(ply2[0].score<=0) printf("\t空空如也，赶快玩一把吧！");
	else
	{
		printf("\t名次\t姓名\t\t\t得分\t步数\n");
		for(i=0;(ply2[i].score>100)&&(i<5);i++)
		{
			if(strlen(ply2[i].name)<8) printf("\t%d\t%s\t\t\t%d\t%d\n", i+1, ply2[i].name, ply2[i].score, ply2[i].step);
			else if(strlen(ply2[i].name)<16) printf("\t%d\t%s\t\t%d\t%d\n", i+1, ply2[i].name, ply2[i].score, ply2[i].step);
			else printf("\t%d\t%s\t%d\t%d\n", i+1, ply2[i].name, ply2[i].score, ply2[i].step);
		}
	}
	return(0);
}
int wrtjudge()																			/*此函数判断玩家是否进入高分榜*/
{
	int v;
	if(n==1)
	{
		if(score>ply1[4].score) v = 1;
		else v = 0;
	}
	if(n==2)
	{
		if(score>ply2[4].score) v = 1;
		else v = 0;
	}
	return(v);
}