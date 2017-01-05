#include<iostream>
#include<fstream>
using namespace std;
int FindMin(int*, int*, int);
int SUM(int*, int);
int main()
{
	ifstream infile("input.txt");
	ofstream outfile("2013011717.txt");
	if(!infile.is_open())				//�жϴ��ļ��Ƿ�ɹ������д���
	{
		cout<<"Could not open the file <input.txt>.\n";
		system("pause");
		exit(EXIT_FAILURE);
	}

	int v, node;

	infile>>v;								//���������		
	int **QJ = new int*[v];			//����Ȩ����
    for(int i = 0 ; i<v ; i++)
        QJ[i] = new int[v];

	int*PathCost = new int[v];			//�������·��ֵ����

	int*S = new int[v];						//��ʼ��S����¼���нڵ��Ƿ����ҵ����·�������ҵ���ֵΪһ

	for(int i = 0 ; i<v ; i++)				//����Ȩ����
	{
		for(int j = 0 ; j<v ; j++)
		{
			infile>>QJ[i][j];
		}
	}
	infile>>node;								//������ʼ�ڵ�
	if(node > v)
	{
		cout<<"Warning: node beyond range.\n";
		system("pause");
		exit(EXIT_FAILURE);
	}
	node = node - 1;

	for(int i = 0; i < v; i++)				//��ʼ��PathCost����
	{
		if(QJ[node][i] != 0)
			PathCost[i] = QJ[node][i];
		else
			PathCost[i] = 101*v;
	}

	for(int i = 0; i < v; i++)				//��ʼ��S[i]����
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
		j = FindMin(PathCost, S, v);				//�޸�����S�Ĳ����ں���FindMin()�����
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
		if(i != node)										//�ж���iΪ��ʼ�ڵ������PathCost[i]��ֵ
		{
			count++;
			if(PathCost[i] <= 100*v)					//��CostС�ڵ���100*v�����Cost�����������ͨ�����-1
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
	
	infile.close();				//�ر��ļ�
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