#include<iostream>
#include<fstream>
using namespace std;
int FindMin(int*, int*, int);
int SUM(int*, int);
int main()
{
	ifstream infile("input.txt");
	ofstream outfile("2013011717.txt");
	if(!infile.is_open())				//判断打开文件是否成功并进行处理
	{
		cout<<"Could not open the file <input.txt>.\n";
		system("pause");
		exit(EXIT_FAILURE);
	}

	int v, node;

	infile>>v;								//读入结点个数		
	int **QJ = new int*[v];			//定义权矩阵
    for(int i = 0 ; i<v ; i++)
        QJ[i] = new int[v];

	int*PathCost = new int[v];			//定义最短路径值数组

	int*S = new int[v];						//初始化S，记录所有节点是否已找到最短路径，已找到的值为一

	for(int i = 0 ; i<v ; i++)				//读入权矩阵
	{
		for(int j = 0 ; j<v ; j++)
		{
			infile>>QJ[i][j];
		}
	}
	infile>>node;								//读入起始节点
	if(node > v)
	{
		cout<<"Warning: node beyond range.\n";
		system("pause");
		exit(EXIT_FAILURE);
	}
	node = node - 1;

	for(int i = 0; i < v; i++)				//初始化PathCost数组
	{
		if(QJ[node][i] != 0)
			PathCost[i] = QJ[node][i];
		else
			PathCost[i] = 101*v;
	}

	for(int i = 0; i < v; i++)				//初始化S[i]数组
	{
		if(i == node)
			S[i] = 1;
		else
			S[i] = 0;
	}
	/*for(int i = 0; i < v; i++)
	{
		outfile<<PathCost[i]<<' ';
	}
	outfile<<endl;
	for(int i = 0; i < v; i++)
	{
		outfile<<S[i]<<' ';
	}*/
	//outfile<<endl;
	//outfile<<"inside the loop: "<<endl;
	
	while(1)
	{
		int tempSum = SUM(S, v);
		int j;
		j = FindMin(PathCost, S, v);				//修改数组S的操作在函数FindMin()中完成
		if((SUM(S, v) == v)||(tempSum == SUM(S, v)))
			break;
		for(int i = 0; i < v; i++)
		{
			if(S[i] == 0)
			{
				if(QJ[j][i] != 0)
					PathCost[i] = min(PathCost[i], PathCost[j] + QJ[j][i]);
			}
		}
		/*for(int i = 0; i < v; i++)
		{
			outfile<<PathCost[i]<<' ';
		}
		for(int i = 0; i < v; i++)
		{
			outfile<<S[i]<<' ';
		}
		outfile<<endl;*/
	}

	
	//outfile<<"output: "<<endl;
	int count = 0;
	for(int i = 0; i < v; i++)
	{
		if(i != node)										//判断若i为起始节点则不输出PathCost[i]的值
		{
			count++;
			if(PathCost[i] <= 100*v)					//若Cost小于等于100*v则输出Cost，否则代表不连通，输出-1
			{
				if(count < v - 1)
					outfile<<PathCost[i]<<' ';
				else
					outfile<<PathCost[i];
			}
			else
			{
				if(count < v - 1)
					outfile<<-1<<' ';
				else
					outfile<<-1;
			}
		}
	}
	
	infile.close();				//关闭文件
	outfile.close();
	return 0;
}
int FindMin(int*PathCost, int*S, int v)
{
	int minnode = 0;
	for(int i = 0; i < v; i++)
	{
		if(S[i] == 0)
			minnode = PathCost[i] >= PathCost[minnode]? minnode : i;
	}
	S[minnode] = 1;
	return minnode;
}
int SUM(int*S, int v)
{
	int sum = 0;
	for(int i = 0; i < v; i++)
	{
		sum = sum + S[i];
	}
	return sum;
}