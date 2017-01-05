#pragma once


#ifndef DATASTRUCT_H_
#define DATASTRUCT_H_
#ifndef cout
#include<iostream>
#ifndef ifstream
#include<fstream>
#endif
using namespace std;
#endif

#ifndef MatrixXd
#include<Eigen/Dense>
using namespace Eigen;
using namespace Eigen::internal;
using namespace Eigen::Architecture;
#endif

//class Coord2D describes a 2-D coordinate
class Coord2D
{
private:
	int m_x;
	int m_y;
public:
	Coord2D(){m_x = 0; m_y = 0;}
	Coord2D(Coord2D & tempCO){m_x = tempCO.getX(); m_y = tempCO.getY();}
	Coord2D(int x, int y){m_x = x; m_y = y;}
	int getX(){return m_x;}
	int getY(){return m_y;}
	void operator=(Coord2D tempCO){m_x = tempCO.getX(); m_y = tempCO.getY();}
	bool operator==(Coord2D tempCO)
	{
		if(m_x == tempCO.getX()&&(m_y == tempCO.getY()))
			return true;
		return false;
	}
	//print the coordinate
	void print(){cout<<"x: "<<m_x<<", y: "<<m_y<<' ';}
};

//class OPERATION describes an operation to the puzzle, containing the position and the number to assign
class OPERATION
{
private:
	Coord2D m_CO;
	int m_num;
public:
	OPERATION(){m_num = 0;}
	OPERATION(int x, int y, int num){Coord2D tempCO(x, y); m_CO = tempCO; m_num = num;}
	OPERATION(Coord2D tempCO, int num){m_CO = tempCO; m_num = num;}
	OPERATION(OPERATION & tempOp){m_CO = tempOp.getCO(); m_num = tempOp.getNum();}
	int getNum(){return m_num;}
	Coord2D getCO(){return m_CO;}
	void operator=(OPERATION tempOp){m_CO = tempOp.getCO(); m_num = tempOp.getNum();}
	bool operator==(OPERATION tempOp)
	{
		if((m_CO == tempOp.getCO())&&(m_num == tempOp.getNum()))
			return true;
		return false;
	}
	//print the opertation
	void print(){m_CO.print();cout<<"num: "<<m_num<<endl;}
};

//Stack for int
//WARNING: the 0-th item is always a junk, so the first ordinary item is [1], and the Len is also one bigger than real.
//the above warning can be ignored if you won't use ro change anything related to a Stack
class numStack
//a stack of type int
{
private:
	int* numstack;
	int Len;
public:
	numStack(){numstack = new int[1]; Len = 1;}
	numStack(numStack & tempStack)
	{
		Len = tempStack.getLen();
		numstack = new int[Len];
		for(int i = 0; i < Len; i++)
			numstack[i] = tempStack[i];
	}
	int getLen(){return Len;}
	void push(int num);
	int pop();
	int &operator[](int n){return numstack[n];}
	void operator=(numStack tempStack)
	{
		delete [] numstack;
		Len = tempStack.getLen();
		numstack = new int[Len];
		for(int i = 0; i < Len; i++)
			numstack[i] = tempStack[i];
	}
	void print()
	{
		for(int i = 0; i < Len; i++)
			cout<<numstack[i]<<' ';
	}
	~numStack(){delete [] numstack;}
};

//iMAT class describes a 2-D dynamic-sized matrix of type int, inherited from MatrixXd
//WITH METHODS:
//int rows()
//int cols()
//bool findItem(int num)
//void print()
//void getInputFromFile(char* fileName = NULL),
//void outputToFile(char* fileName = NULL)
//void operator=(iMAT tempM)
//bool operator==(iMAT tempM)
//int & operator()(int i, int j)
class iMAT:public MatrixXi
{
public:
	iMAT():MatrixXi(){}
	/*iMAT(iMAT & tempM)
	{
		m_row = tempM.rows();
		m_col = tempM.cols();
		m_mat = new int*[m_row];
		for(int i = 0; i < m_row; i++)
			m_mat[i] = new int[m_col];
		for(int i = 0; i < m_row; i++)
		{
			for(int j = 0; j < m_col; j++)
				m_mat[i][j] = tempM(i, j);
		}
	}*/
	iMAT(int row, int col):MatrixXi(row, col){}
	//returns whether there is a num in the mat
	bool findItem(int num);
	//print the matrix
	void print();
	//get the mat items from a file named "fileName", with 81 numbers in 0~9, separated by a space, 0 for empty
	void getInputFromFile(char* fileName = NULL);
	//output the MAT to a file with name "fileName"
	void outputToFile(char* fileName = NULL, bool isNormal = false);
	//~iMAT(){/*cout<<"delete mat\n";*/if((m_row > 0)&&(m_col > 0)) delete [] m_mat;}
};

template<class Type>
//a stack template
//WARNING: the 0-th item is always a junk, so the first ordinary item is [1], and the Len is also one bigger than real.
//the above warning can be ignored if you won't use or change anything related to a Stack
class Stack
{
private:
	Type* stack;
	int Len;
public:
	Stack(){stack = new Type[1]; Len = 1;}
	Stack(Stack & tempStack)
	{
		Len = tempStack.getLen();
		stack = new Type[Len];
		for(int i = 0; i < Len; i++)
			stack[i] = tempStack[i];
	}
	int getLen(){return Len;}
	void push(Type tempType);
	Type pop();
	Type &operator[](int n){return stack[n];}
	void print()
	{
		for(int i = 0; i < Len; i++)
			stack[i].print();
	}
	//removes all tempType from Stack
	void moveOff(Type tempType);
	//returns the order of tempType in Stack, 0 if non
	int findItem(Type tempType)
	{
		for(int i = 1; i < Len; i++)
		{
			if(stack[i] == tempType)
				return i;
		}
		return 0;
	}
	void operator=(Stack tempStack)
	{
		delete [] stack;
		Len = tempStack.getLen();
		stack = new Type[Len];
		for(int i = 0; i < Len; i++)
			stack[i] = tempStack[i];
	}
	~Stack(){delete [] stack;}
};
template <class Type>
void Stack<Type>::push(Type tempType)
{
	Type* tempList = new Type[Len + 1];
	int i = 0;
	for(i = 0; i < Len; i++)
		tempList[i] = stack[i];
	tempList[i] = tempType;
	delete [] stack;
	stack = tempList;
	Len++;
}
template <class Type>
Type Stack<Type>::pop()
{
	if(Len == 1)
	{
		cout<<"WARNING: poping from empty stack!\n";
		system("pause");
	}
	Type* tempList = new Type[Len - 1];
	int i = 0;
	for(i = 0; i < Len-1; i++)
		tempList[i] = stack[i];
	Type tempOp(stack[i]);
	delete [] stack;
	stack = tempList;
	Len--;
	return tempOp;
}
template <class Type>
void Stack<Type>::moveOff(Type tempType)
{
	Type* tempstack = new Type[Len - 1];
	int i = 0;
	int j = 0;
	for(i = 0; i < Len; i++)
	{
		if(stack[i] == tempType)
			continue;
		else
		{
			tempstack[j] = stack[i]; 
			j++;
		}
	}
	Len--;
	delete [] stack;
	stack = tempstack;
}

//a queue template
//WARNING: the 0-th item is always a junk, so the first ordinary item is [1], and the Len is also one bigger than real.
//the above warning can be ignored if you won't use or change anything related to a Stack
template<class Type2>
class Queue
{
private:
	Type2* queue;
	int Len;
public:
	Queue(){queue = new Type2[1]; Len = 1;}
	Queue(Queue & tempQueue)
	{
		Len = tempQueue.getLen();
		queue = new Type2[Len];
		for(int i = 0; i < Len; i++)
			queue[i] = tempQueue[i];
	}
	void push(Type2 tempGS);
	Type2 pop();
	Type2 & operator[](int n){return queue[n];}
	int findItem(Type2 tempType)
	{
		if(Len == 1)
			return 0;
		for(int i = 1; i < Len; i++)
		{
			if(queue[i] == tempType)
				return i;
		}
		return 0;
	}
	void operator=(Queue tempQueue)
	{
		delete [] queue;
		Len = tempQueue.getLen();
		queue = new Type2[Len];
		for(int i = 0; i < Len; i++)
			queue[i] = tempQueue[i];
	}
	int getLen(){return Len;}
	~Queue(){delete [] queue;}
};
template<class Type2>
void Queue<Type2>::push(Type2 tempGS)
{
	Type2* tempList = new Type2[Len + 1];
	int i = 0;
	for(i = 0; i < Len; i++)
		tempList[i] = queue[i];
	tempList[i] = tempGS;
	delete [] queue;
	queue = tempList;
	Len++;
}
template<class Type2>
Type2 Queue<Type2>::pop()
{
	if(Len == 1)
	{
		cout<<"WARNING: poping from empty queue!\n";
		system("pause");
	}
	Type2* tempQueue = new Type2[Len - 1];
	Type2 tempGS(queue[1]);
	for(int i = 1; i < Len - 1; i++)
		tempQueue[i] = queue[i + 1];
	delete [] queue;
	queue = tempQueue;
	Len--;
	return tempGS;
}

//Stack for OPERATION
//WARNING: the 0-th item is always a junk, so the first ordinary item is [1], and the Len is also one bigger than real.
//the above warning can be ignored if you won't use or change anything related to a Stack
typedef Stack<OPERATION> OprtStack;
//Stack for Coord2D
//WARNING: the 0-th item is always a junk, so the first ordinary item is [1], and the Len is also one bigger than real.
//the above warning can be ignored if you won't use or change anything related to a Stack
typedef Stack<Coord2D> coordStack;
//Stack for iMAT
//WARNING: the 0-th item is always a junk, so the first ordinary item is [1], and the Len is also one bigger than real.
//the above warning can be ignored if you won't use or change anything related to a Stack
typedef Stack<iMAT> matStack;
//Queue for Coord2D
//WARNING: the 0-th item is always a junk, so the first ordinary item is [1], and the Len is also one bigger than real.
//the above warning can be ignored if you won't use or change anything related to a Stack
typedef Queue<Coord2D> coordQueue;
//Queue for iMAT
//WARNING: the 0-th item is always a junk, so the first ordinary item is [1], and the Len is also one bigger than real.
//the above warning can be ignored if you won't use or change anything related to a Stack
typedef Queue<iMAT> matQueue;
//Queue for int
//WARNING: the 0-th item is always a junk, so the first ordinary item is [1], and the Len is also one bigger than real.
//the above warning can be ignored if you won't use or change anything related to a Stack
typedef Queue<int> numQueue;
//class OprtStack
//{
//private:
//	OPERATION* OLIST;
//	int Len;
//public:
//	OprtStack(){OLIST = new OPERATION[1]; Len = 1;}
//	int getLen(){return Len;}
//	void push(OPERATION tempOp);
//	OPERATION pop();
//	OPERATION &operator[](int n){return OLIST[n];}
//	void print()
//	{
//		for(int i = 0; i < Len; i++)
//			OLIST[i].print();
//	}
//};

#endif// DATASTRUCT_H_