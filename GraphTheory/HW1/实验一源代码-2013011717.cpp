#include<iostream>
#include<cstdlib>
#include<fstream>
using namespace std;
ifstream infile("input.txt");
ofstream outfile("2013011717.txt");
void ofileM(int **, int , int);
void ofileA(int*, int);
void clear(int);
void add(int, int, int);
struct Node
{
	int nov, noe;
	Node* nextv;
	Node(int _nov = 0, int _noe= 0): nov(_nov), noe(_noe) {}
};
Node**LB;
int main()
{	
	int v, e = 0;							 //v为结点个数，e为边的条数
	if(!infile.is_open())				//判断打开文件是否成功并进行处理
	{
		cout<<"Could not open the file <input.txt>.\n";
		system("pause");
		exit(EXIT_FAILURE);
	}
	infile>>v;								//读入结点个数		
	int **QJ = new int*[v-1];			//定义权矩阵
    for(int i = 0 ; i<v ; i++)
        QJ[i] = new int[v-1];

	for(int i = 0 ; i<v ; i++)
	{
		for(int j = 0 ; j<v ; j++)
		{
			infile>>QJ[i][j];
			if(QJ[i][j] != 0)			
				e++;
		}
	}
	int **BB = new int*[2];			//定义边列表
	for(int i = 0; i<3 ; i++)
		BB[i] = new int[e-1];    
	e = 0;
	for(int i = 0 ; i<v ; i++)		//通过权矩阵计算边列表各项之值
	{
		for(int j = 0 ; j<v ; j++)
		{
			if(QJ[i][j] != 0)
			{
				BB[0][e] = i + 1;
				BB[1][e] = j + 1;
				BB[2][e] = QJ[i][j];
				e++;
			}
		}
	}
	int **GJ = new int*[v-1];			//定义关联矩阵
	for(int i = 0; i<v ; i++)
		GJ[i] = new int[e-1];
	for(int j = 0 ; j<e ; j++)			//通过边列表计算关联矩阵各项之值
	{
		for(int i = 0 ; i<v ; i++)
		{
			if((i+1) == BB[0][j])
				GJ[i][j] = 1;
			else if((i+1) == BB[1][j])
				GJ[i][j] = -1;
			else
				GJ[i][j] = 0;
		}
	}
	int *ZB1 = new int[v];				//定义正向表，ZB1，ZB2，ZB3分别为正向表的三个向量
	int *ZB2 = new int[e-1];
	int *ZB3 = new int[e-1];
	ZB1[0] = 1;
	for(int i = 0 ; i<v ; i++)
	{
		for(int j = 0 ; j<e ; j++)
		{
			if(BB[0][j] == i)
				ZB1[i]++;
		}
		ZB1[i+1] = ZB1[i];
	}
	ZB1[v] = e+1;
	for(int i = 0 ; i<e ; i++)				//按题中所述的边编号方式，正向表第二、三行恰与边列表的第二、三行相同
	{
		ZB2[i] = BB[1][i];
		ZB3[i] = BB[2][i];
	}	
		
	LB = new Node*[v-1];				//定义邻接表
	
	for(int i = e-1; i>=0 ; i--)				//根据边列表向邻接表中添加边
	{
		add( BB[0][i] - 1, BB[1][i], BB[2][i]);
	}

	ofileM(GJ, v, e);				//打印关联矩阵
	ofileM(BB, 3, e);				//打印边列表
	ofileA(ZB1, v+1);				//打印正向表	
	ofileA(ZB2, e);
	ofileA(ZB3, e);	
	for(int i = 0, j = 1; i<v ; i++)		//打印邻接表
	{
		Node*temp = LB[i];			
		while( j < ZB1[i+1])
		{			
			if(j+1<ZB1[i+1])
			{
				
				outfile<<temp->noe<<' ';			
				outfile<<temp->nov<<' ';		
			}
			else
			{
				outfile<<temp->noe<<' ';			
				outfile<<temp->nov;
			}
			temp = temp->nextv;			
			j++;
		}
		if(i<v-1)
			outfile<<endl;
	}

	infile.close();				//关闭文件
	outfile.close();
	return 0;
}
void ofileM(int ** M, int row, int col)			//打印二维数组的函数
{
	for(int i = 0 ; i<row ; i++)
	{
		for(int j = 0 ; j<col ; j++)
		{
			if(j<(col-1))
				outfile<<M[i][j]<<' ';
			else
				outfile<<M[i][j];
		}
		outfile<<endl;
	}
}
void ofileA(int*A, int len)				//打印数组的函数
{
	for(int i = 0 ; i<len ; i++)
	{
		if(i+1<len)
			outfile<<A[i]<<' ';
		else
			outfile<<A[i];
	}
	outfile<<endl;
}
void add(int beg, int end, int p)			//向邻接表中添加边的函数
{
	Node*temp = new Node( end, p);
	temp->nextv = LB[beg];
	LB[beg] = temp;
}