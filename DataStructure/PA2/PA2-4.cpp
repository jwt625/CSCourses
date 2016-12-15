#include <stdio.h>
#define MIN_INT -2147483648
using namespace std;

// Implement the Stack structure based on the given template
// No new public method added (except the constructor and the destructor)
class Stack
{
public:
	//注意：你不能添加更多的public函数或变量
	bool empty();
	void push(int);
	int pop();
	int top();
	~Stack();
	Stack();
private:
	//此处可以扩展
	int * _items;
	int _N;
	int _top;
};

Stack::Stack()
{
	_N = 1000001;
	_top = 0;
	_items = new int[_N];
}

Stack::~Stack()
{
	delete [] _items;
}

bool Stack::empty()
{
	return _top == 0;
}

void Stack::push(int value)
{
	_items[_top++] = value;
}

int Stack::pop()
{
	if ( _top > 0)
	{
		return _items[--_top];
	}
	return MIN_INT;
}

int Stack::top()
{
	if ( _top > 0)
	{
		return _items[_top-1];	
	}
	return MIN_INT;
}

// QuickMaxStack uses two Stack structure to implement an O(1) method
// for querying the max element
// The max element is always the top of the _maxStack 
class QuickMaxStack
{
private:
	Stack _stack;
	Stack _maxStack;
public:
	int pop();
	void push(int value);
	int top();
	int max();
	bool empty();
};

// Chech the element to push, if it's no less than the current
// max element, then also push it into the _maxStack
void QuickMaxStack::push(int value)
{
	_stack.push(value);
	if ( value >= _maxStack.top() )
	{
		_maxStack.push(value);
	}
}

// Check the element to pop, if it coincide with the top
// element of _maxStack, then it's the current max element,
// hence will be popped from _maxStack
int QuickMaxStack::pop()
{
	int toPop =  _stack.pop();
	if ( toPop == _maxStack.top() )
	{
		return _maxStack.pop();
	}
	return toPop;
}

// The max element is the top of the _maxStack
int QuickMaxStack::max()
{
	return _maxStack.top();
}

bool QuickMaxStack::empty()
{
	return _stack.empty();
}

int QuickMaxStack::top()
{
	return _stack.top();
}

// Queap uses two QuickMaxStack to simulate the Queap structure
// Elements are enqueapped into the _rightStack and dequeapped from the _leftStack
// 
// If _leftStack is empty, then all elements in _rightStack are
// popped and pushed into _leftStack, which is done by Queap::transfer()
class Queap
{
public:
	void enqueap(int);
	int dequeap();
	int max();
private:
	QuickMaxStack _leftStack;
	QuickMaxStack _rightStack;
protected:
	inline void transfer();
};

void Queap::enqueap(int value)
{
	_rightStack.push(value);
}

int Queap::dequeap()
{
	if (_leftStack.empty())
	{
		Queap::transfer();
	}
	return _leftStack.pop();
}

inline void Queap::transfer()
{
	while (!_rightStack.empty())
	{
		_leftStack.push(_rightStack.pop());
	}
}

// max() returns the max element in the Queap
// It causes O(1) time
int Queap::max()
{
	int leftMax = _leftStack.max();
	int rightMax = _rightStack.max();
	return leftMax > rightMax ? leftMax : rightMax;
}

int main()
{	
#ifndef _OJ_
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

	int n;
	scanf("%d\n", &n);
	if ( n == 0 )
	{
		return 0;
	}

	// Initialize Queap
	Queap queap;
	char op;
	int x;

	for (int i = 0; i < n; ++i)
	{
		// get the operation and switch according to it
		scanf("%c", &op);
		switch (op)
		{
			case 'E':
			scanf("%d\n", &x);
			queap.enqueap(x);
			break;
			case 'D':
			printf("%d\n", queap.dequeap());
			break;
			case 'M':
			printf("%d\n", queap.max());
			break;
			default:
			i--;
			break;
		}
	}

	return 0;
}

