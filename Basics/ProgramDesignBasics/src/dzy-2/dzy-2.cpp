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
int mat[22][22];													/*mat[22][22]�������շ�ֹ���*/
int i = 0, j = 0, score = 0, n;
typedef struct
{
	char name[20];
	int score;
	int step;
} plist;
plist ply1[5];														/*���ڴ洢���а������*/
plist ply2[5];
int main()
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);					/*����������ɫ����ֹѭ����������ɫ��Ϊ��ɫ*/
	WORD att;  
	att = FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY;
	SetConsoleTextAttribute(handle, att);

	while(1)															/*ʹ������ѭ���ﵽ�������е�Ч��*/
	{
		rdlist();
		int ch;																  
		do
		{
			system("cls");
			printf("\n");
			printf("  ��Ϸ : ��ɫ����\n\n");
			printf("  ��ѡ��\n");
			printf("  1. ��ʼ��Ϸ��\n");
			printf("  2. ��Ϸ˵����\n");
			printf("  3. �÷����а�\n");
			printf("  4. �˳���Ϸ.\n");
			ch = getch();												/*��getch()�����õ�����*/
		}while((ch != 49)&&(ch != 50)&&(ch != 51)&&(ch != 52));						/*getch()����ֵΪASC�룬�ַ�0��Ӧ����48������������*/

		if(ch == 49)
		{
			int n1;
			int step = 0;
			do
			{
				system("cls");
				printf("\n");
				printf("��ѡ����Ϸ��ģ��\n\n");
				printf("  1. С�ͣ�10*10��\n");
				printf("  2. ���ͣ�20*20��\n\n");
				printf("��0�����ز˵���");
				n1 = getch();
			}while((n1 != 48)&&(n1 != 49)&&(n1 != 50));					  
			if(n1 == 48) continue;
			n = n1 - 48;
			game_start();
			score = 0;
			do
			{
				do																/*����������������ֱ��������ȥ����*/
				{
					mouse();
				}while(((mat[i][j]!=mat[i-1][j])&&(mat[i][j]!=mat[i+1][j])&&(mat[i][j]!=mat[i][j-1])&&(mat[i][j]!=mat[i][j+1]))
					||(i>10*n)||(j>10*n)||(mat[i][j]<0));
				adjust();														/*����mat[22][22]�е���ɫ����*/
				step++;
				reprint(&step);													/*���´�ӡ����*/
			}while(judge());
			printf("\n\n    ��Ϸ������\n\n    ���ĵ÷��ǣ�%d, ��ʹ����%d��\n\n", score, step);
			if(wrtjudge())														/*�ж��Ƿ����߷ְ�*/
			{
				printf("    �����������������մ���(20���ַ����������пո�)��");
				wrtlist(&step);
			}
			else printf("���Ĺ������㣬�������Ͱɣ�");
			printf("\n    ��0�����ز˵���");
			do
			{
				n1 = getch();
			}while(n1 != 48);
			if(n1 == 48) continue;
		}

		if(ch == 50)															/*˵����Ϸ����*/
		{
			int n1;
			do
			{
				system("cls");
				printf("\n");
				printf("��ϷĿ�ģ������ܵ���ȥ���ݡ�\n\n");
				printf("          1.�������������������ͬ��ɫ������ʱ���ɽ�������ȥ\n");
				printf("          2.��������Ϊһ����������ɫ��Χ�ĵ�һ�����ݣ����޷���ȥ��\n");
				printf("          3.�·����ݱ���ȥ�����Ϸ����ݽ���ֱ���䣬��һ����ȫ����ȥ�������󷽵�����������������ƽ��һ�С�\n");
				printf("          4.����Ϸ���Ѿ�û�п�����ȥ������ʱ����Ϸ����\n");
				printf("          5.�÷ּ��㷽ʽ��һ�β�������x��������ͬɫ���ݣ���÷�Ϊx^2�����һ������ȥ����Խ��÷�Խ�ߡ�\n\n");
				printf("��0���ز˵���");
				n1 = getch();
				if(n1 == 48) break;
			}while(n1 != 48);
		}

		if(ch == 51)															/*�鿴�߷ְ�*/
		{
			int n1;
			do
			{
				system("cls");
				prtlist();
				printf("\n\n  ��0�����ز˵���");
				n1 = getch();
				if(n1 == 48) break;
			}while(n1 != 48);
		}

		if(ch == 52) break;
	}
	system("exit");
}
int game_start()																/*�˺���ʵ�ֿ���mat[22][22]������������ӡ*/
{
	system("cls");
	printf("�������������������ͬ��ɫ����������������ȥ:\n\n");

		i = 0;
		while(i<100*n*n)
		{
			j = i / (10*n) + 1;
			mat[(i%(10*n))+1][j] = rand()%4 + 1;
			switch(mat[(i%(10*n))+1][j])															  /*������ɫ����*/
			{
				case 1:
				{
					HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
					WORD att;  
					att = FOREGROUND_GREEN|FOREGROUND_INTENSITY;
					SetConsoleTextAttribute(handle, att);
					printf("��");
					break;
				}
				case 2:
				{
					HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
					WORD att;   
					att = FOREGROUND_RED|FOREGROUND_INTENSITY;
					SetConsoleTextAttribute(handle, att);
					printf("��");
					break;
				}
				case 3:
				{
					HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
					WORD att;  
					att = FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY;
					SetConsoleTextAttribute(handle, att);
					printf("��");
					break;
				}
				case 4:
				{
					HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
					WORD att;  
					att = FOREGROUND_BLUE|FOREGROUND_INTENSITY;
					SetConsoleTextAttribute(handle, att);
					printf("��");
					break;
				}
			}
			i++;
			if(i/(10*n)+1>j) printf("\n");
		}		
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);											 /*��������ɫ���ذ�ɫ*/
	WORD att;  
	att = FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY;
	SetConsoleTextAttribute(handle, att);
	return(0);
}
int mouse()														/*�˺���ʵ�ֹ���������ƶ�������������Ķ���(�˺�������%��ͷ��ע��Ϊ����ԭ��������)*/
{
    DWORD dwMode, dwOldMode;                                                          /* %ԭ����ģʽ����ģʽ */
    DWORD dwRead;																	  /* %�Ѿ���ȡ�������¼��� */
    int mouse_pos;																	  /* %���ڷ������λ�� */
    UINT count;																		  /* %����ѭ������ */
    INPUT_RECORD ir[128];															  /* %����̨�����¼ */
    CONSOLE_CURSOR_INFO cci, cciOld;												  /* %�����ص����� */
    COORD co;																		  /* %����ƶ�ʱ�������� */
    HANDLE hStdIn = NULL, hStdOut = NULL;											  /* %��׼����������  */


    hStdIn = GetStdHandle(STD_INPUT_HANDLE);										  /* %ȡ������������ */
    hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

    if(!GetConsoleMode(hStdIn, &dwOldMode))											  /* %ȡ�ÿ���̨ԭ����ģʽ */
    {
        fprintf(stderr, "GetConsoleMode ����:%d\n", GetLastError());
        goto _exit;
    }
    dwMode = dwOldMode | ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;
    if(!SetConsoleMode(hStdIn, dwMode))												  /* %��������¼� */
    {
        fprintf(stderr, "SetConsoleMode ����:%d\n", GetLastError());
        goto _exit;
    }

    GetConsoleCursorInfo(hStdOut, &cciOld);
    cci.bVisible = TRUE;															  /* %���ɼ� */
    cci.dwSize = 100;																  /* %��״ */
    if(!SetConsoleCursorInfo(hStdOut, &cci))
    {
        fprintf(stderr, "SetConsoleCursorInfo ����:%d\n", GetLastError());
        goto _exit;
    }

    for(;;)																			  /* %ѭ���ȴ��û��¼� */
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
                case MOUSE_MOVED:													  /* %�������λ�� */
                    co.X = ir[count].Event.MouseEvent.dwMousePosition.X;
                    co.Y = ir[count].Event.MouseEvent.dwMousePosition.Y;
                    SetConsoleCursorPosition(hStdOut, co);   
					i = co.X / 2 + 1;												  /*ȡ�����λ��*/
					j = co.Y - 1;
                    break;
                case 0:																  /*ȡ����굥���¼�*/
                    if(ir[count].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
                    {
						SetConsoleMode(hStdIn, dwOldMode);							  /* %��ԭԭ�������� */
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
int adjust()																	/*�˺���ʵ�����ݰ�����Ϸ����ĵ���*/
{
	int count=1, move, p, q, k;
	mat[i][j] = mat[i][j] - 8;
	while(1)																			/*���Ӧ��ȥ������*/
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
		if(k==count) break;															/*ѭ��ֱ��û���µ����ݱ����*/
	}
	score = score + count*count;													/*����÷�*/
	k = 0;
	do
	{
		for(p=10*n;p>0;p--)																/*����ȥ�Ŀ�λ����*/
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
	}while(k<9);																	/*���㷨����λ���������Ϸ���λΪֹ������������������������9��*/														
																			
	for(p=10*n;p>0;p--)																/*���п�����������������*/
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
int reprint(int *ps)																/*�˺������������mat[22][22]���´�ӡ*/
{
	system("cls");
	printf("�������������������ͬ��ɫ����������������ȥ:\n\n");

	i = 0;
	while(i<100*n*n)
	{
		j = i / (10*n) + 1;
		switch(mat[(i%(10*n))+1][j])															  /*������ɫ����*/
		{
			case 1:
			{
				HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
				WORD att;  
				att = FOREGROUND_GREEN|FOREGROUND_INTENSITY;
				SetConsoleTextAttribute(handle, att);
				printf("��");
				break;
			}
			case 2:
			{
				HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
				WORD att;   
				att = FOREGROUND_RED|FOREGROUND_INTENSITY;
				SetConsoleTextAttribute(handle, att);
				printf("��");
				break;
			}
			case 3:
			{
				HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
				WORD att;  
				att = FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY;
				SetConsoleTextAttribute(handle, att);
				printf("��");
				break;
			}
			case 4:
			{
				HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
				WORD att;  
				att = FOREGROUND_BLUE|FOREGROUND_INTENSITY;
				SetConsoleTextAttribute(handle, att);
				printf("��");
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
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);											 /*��������ɫ���ذ�ɫ*/
	WORD att;  
	att = FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY;
	SetConsoleTextAttribute(handle, att);
	printf("\n    �÷�:%d     ʹ�ò���:%d", score, *ps);
	return(0);
}
int judge()																	/*�˺����ж���Ϸ�Ƿ����*/
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
int wrtlist(int *ps)																/*�˺������߷ְ�������ṹ�������е���Ϣд���ⲿtxt�ļ�*/
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
int rdlist()																			/*�˺�����txt�д洢�ĸ߷ְ���Ϣ����ṹ�����飬��Ϊ��������Ĭ���ļ����ṹ������*/
{
	FILE *fp;
	char line[30];
	int k;

	fp = fopen("plist1.txt", "r");
	if(fp == NULL)																		/*���ļ�Ϊ���򴴽�����Ϊ"null"���÷��벽����Ϊ0�ĸ߷ְ���Ϣ�ļ�*/
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
int prtlist()																			/*�˺���ʵ�ָ߷ְ�Ĵ�ӡ*/
{
	printf("\t\t�߷ְ�\n\n\n");
	printf("\tС��:\n\n");
	if(ply1[0].score<=0) printf("\t�տ���Ҳ���Ͽ���һ�Ѱɣ�");
	else
	{
		printf("\t����\t����\t\t\t�÷�\t����\n");
		for(i=0;(ply1[i].score>100)&&(i<5);i++)											/*����������Ƴ��̷��࣬�Դﵽ��ӡ�����Ч��*/
		{
			if(strlen(ply1[i].name)<8) printf("\t%d\t%s\t\t\t%d\t%d\n", i+1, ply1[i].name, ply1[i].score, ply1[i].step);
			else if(strlen(ply1[i].name)<16) printf("\t%d\t%s\t\t%d\t%d\n", i+1, ply1[i].name, ply1[i].score, ply1[i].step);
			else printf("\t%d\t%s\t%d\t%d\n", i+1, ply1[i].name, ply1[i].score, ply1[i].step);
		}
	}
	printf("\n\n\t����:\n\n");
	if(ply2[0].score<=0) printf("\t�տ���Ҳ���Ͽ���һ�Ѱɣ�");
	else
	{
		printf("\t����\t����\t\t\t�÷�\t����\n");
		for(i=0;(ply2[i].score>100)&&(i<5);i++)
		{
			if(strlen(ply2[i].name)<8) printf("\t%d\t%s\t\t\t%d\t%d\n", i+1, ply2[i].name, ply2[i].score, ply2[i].step);
			else if(strlen(ply2[i].name)<16) printf("\t%d\t%s\t\t%d\t%d\n", i+1, ply2[i].name, ply2[i].score, ply2[i].step);
			else printf("\t%d\t%s\t%d\t%d\n", i+1, ply2[i].name, ply2[i].score, ply2[i].step);
		}
	}
	return(0);
}
int wrtjudge()																			/*�˺����ж�����Ƿ����߷ְ�*/
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