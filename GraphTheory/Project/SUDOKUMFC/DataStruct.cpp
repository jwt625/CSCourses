#include "StdAfx.h"
#include"DataStruct.h"


//void OprtStack::push(OPERATION tempOp)
//{
//	OPERATION* tempList = new OPERATION[Len + 1];
//	int i = 0;
//	for(i = 0; i < Len; i++)
//		tempList[i] = OLIST[i];
//	tempList[i] = tempOp;
//	delete [] OLIST;
//	OLIST = tempList;
//	Len++;
//}
//OPERATION OprtStack::pop()
//{
//	OPERATION* tempList = new OPERATION[Len - 1];
//	int i = 0;
//	for(i = 0; i < Len-1; i++)
//		tempList[i] = OLIST[i];
//	OPERATION tempOp(OLIST[i]);
//	delete [] OLIST;
//	OLIST = tempList;
//	Len--;
//	return tempOp;
//}

void numStack::push(int num)
{
	int* tempList = new int[Len + 1];
	int i = 0;
	for(i = 0; i < Len; i++)
		tempList[i] = numstack[i];
	tempList[i] = num;
	delete [] numstack;
	numstack = tempList;
	Len++;
}
int numStack::pop()
{
	int* tempList = new int[Len - 1];
	int i = 0;
	for(i = 0; i < Len-1; i++)
		tempList[i] = numstack[i];
	int tempNum = numstack[i];
	delete [] numstack;
	numstack = tempList;
	Len--;
	return tempNum;
}

bool iMAT::findItem(int num)
{
	int row = iMAT::rows();
	int col = iMAT::cols();
	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < col; j++)
		{
			if(iMAT::coeff(i, j)== num)
				return true;
		}
	}
	return false;
}
bool iMAT::operator==(iMAT tempM)
{
	for(int i = 0; i < m_row; i++)
	{
		for(int j = 0; j < m_col; j++)
		{
			if(tempM(i, j) != m_mat[i][j])
				return false;
		}
	}
	return true;
}
void iMAT::print()
{
	int row = iMAT::rows();
	int col = iMAT::cols();
	for(int i = 0; i < row; i++)
	{
		if(i%3 == 0)
			cout<<"-----------------------\n";
		for(int j = 0; j < col; j++)
		{
			if(j%3 == 0)
				cout<<'|'<<' ';
			cout<<iMAT::coeff(i, j)<<' ';
		}
		cout<<endl;
	}
	cout<<"-----------------------\n";
}
void iMAT::getInputFromFile(char* fileName)
{
	if(fileName == NULL)
	{
		char ch[] = "input.txt";
		fileName = ch;
	}
	ifstream inFileTemp(fileName, ios::in);
	if(!inFileTemp.is_open())					//判断打开文件是否成功
	{
		//cout<<"Could not open the file input.txt\n";
		//system("pause");
		//exit(EXIT_FAILURE);
		for(int i = 0; i < 9; i++)
		{
			for(int j = 0; j < 9; j++)
				iMAT::operator()(i, j) = 0;
		}
	}
	int temp;
	int i = 0;
	int j = 0;
	while(inFileTemp && !inFileTemp.eof())
	{
		inFileTemp>>temp;
		iMAT::operator()(i, j) = temp;
		j++;
		if(j == 9)
		{
			i++;
			j = 0;
		}
		if(i == 9)
			break;
	}
	inFileTemp.close();
}
void iMAT::outputToFile(char* fileName, bool isNormal)
{
	if(fileName == NULL)
	{
		char ch[] = "output.txt";
		fileName = ch;
	}
	ifstream inFileTemp(fileName, ios::in);
	if(!inFileTemp.is_open())					//判断打开文件是否成功
	{
		inFileTemp.close();
		ofstream outFile(fileName);
		if(isNormal)
		{
			for(int i = 0; i < 9; i++)
		{
			for(int j = 0; j < 9; j++)
			{
				outFile<<iMAT::coeff(i, j)<<' ';
			}		
			outFile<<endl;
		}
		}
		else
		{
		for(int i = 0; i < 9; i++)
		{
			if(i%3 == 0)
				outFile<<"-----------------------\n";
			for(int j = 0; j < 9; j++)
			{
				if(j%3 == 0)
					outFile<<'|'<<' ';
				outFile<<iMAT::coeff(i, j)<<' ';
			}		
			outFile<<endl;
		}
		outFile<<"-----------------------\n";
		}
	}
	else if((fileName[0] == 'B')&&(fileName[1] == 'F')&&(fileName[2] == 'S'))
	{
		inFileTemp.close();
		ofstream outFile(fileName, ios_base::app);
		if(isNormal)
		{
			for(int i = 0; i < 9; i++)
		{
			for(int j = 0; j < 9; j++)
			{
				outFile<<iMAT::coeff(i, j)<<' ';
			}		
			outFile<<endl;
		}
		}
		else
		{
		for(int i = 0; i < 9; i++)
		{
			if(i%3 == 0)
				outFile<<"-----------------------\n";
			for(int j = 0; j < 9; j++)
			{
				if(j%3 == 0)
					outFile<<'|'<<' ';
				outFile<<iMAT::coeff(i, j)<<' ';
			}		
			outFile<<endl;
		}
		outFile<<"-----------------------\n";
		}
	}
	else
	{
		inFileTemp.close();
		ofstream outFile(fileName);
		if(isNormal)
		{
			for(int i = 0; i < 9; i++)
		{
			for(int j = 0; j < 9; j++)
			{
				outFile<<iMAT::coeff(i, j)<<' ';
			}		
			outFile<<endl;
		}
		}
		else
		{
		for(int i = 0; i < 9; i++)
		{
			if(i%3 == 0)
				outFile<<"-----------------------\n";
			for(int j = 0; j < 9; j++)
			{
				if(j%3 == 0)
					outFile<<'|'<<' ';
				outFile<<iMAT::coeff(i, j)<<' ';
			}		
			outFile<<endl;
		}
		outFile<<"-----------------------\n";
		}
	}
}
//void iMAT::operator=(iMAT tempM)
//	{
//		if((m_row > 0)&&(m_col > 0)) delete [] m_mat;
//		m_row = tempM.rows();
//		m_col = tempM.cols();
//		m_mat = new int*[m_row];
//		for(int i = 0; i < m_row; i++)
//			m_mat[i] = new int[m_col];
//		for(int i = 0; i < m_row; i++)
//		{
//			for(int j = 0; j < m_col; j++)
//				m_mat[i][j] = tempM(i, j);
//		}
//	}
//bool iMAT::operator==(iMAT tempM)
//	{
//		if((m_row != tempM.rows())||(m_col != tempM.cols()))
//			return false;
//		if((m_row == 0)&&(m_col == 0))
//			return true;
//		for(int i = 0; i < m_row; i++)
//		{
//			for(int j = 0; j < m_col; j++)
//			{
//				if(m_mat[i][j] != tempM(i, j))
//					return false;
//			}
//		}
//		return true;
//	}