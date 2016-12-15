#include <stdio.h>

using namespace std;

// class Stack describes a stack
// with only basic method of push and pop
// added a method checkNum to check the size of the stack
class Stack
{
private:
	int * _items;
	int _N;
	int _top;
public:
	Stack(int len) 
	{
		_N = len;
		_top = 0;
		_items = new int[_N];
	}
	~Stack() { delete [] _items; }
	void push(int item) { _items[_top++] = item; }
	int pop() {	return _items[--_top]; }
	int getTop() { return _top; }

	// check the number of current items
	// TRUE if it's larger than m
	bool checkNum(int m) { return _top > m + 1; }
};

int PA22() 
{
#ifndef _OJ_
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

	int n, m;
	scanf("%d %d\n", &n, &m);

	// S saves the current items in S, 
	// including the one that is leaving immediately
	Stack S = Stack(n);

	int Bi;		// for accepting the input of Bi
	int currentItemFromA = 1;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d ", &Bi);
		// If the aim is not smaller than the newest item from A, then
		// push the item from A into S
		while (currentItemFromA <= Bi)
		{
			S.push(currentItemFromA++);
			// Check the size of S to be no larger than m + 1
			if ( S.checkNum(m) )
			{
				printf("No");
				return 0;
			}
		}
		// if the aim is smaller than the newest item from A, then 
		// it must be already in S. If it's not the item that S could pop,
		// then the sequence is impossible.
		if (S.pop() != Bi)
		{
			printf("No");
			return 0;
		}
	}

	// print "Yes" if all Bi's can be pop from S
	printf("Yes");
	return 0;
}

