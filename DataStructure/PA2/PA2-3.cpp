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
	bool isEmpty() { return _top == 0; }
};

int PA23() 
{
#ifndef _OJ_
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	
	int n;
	scanf("%d\n", &n);

	// lists to save the two input lists,
	// the index of nodes in the inorder list
	// and the result of the postorder list
	int * preorderNodes = new int[2*n];
	int * inorderNodes = new int[2*n];
	int * postorderNodes = new int[2*n];
	int * indOfNodes = new int[2*n];
	// read in data
	for (int i = 0; i < n; ++i)
	{
		if ( i < n - 1 )
		{
			scanf("%d ", &preorderNodes[i]);
		}else
		{
			scanf("%d\n", &preorderNodes[i]);
		}
	}
	for (int i = 0; i < n; ++i)
	{
		scanf("%d ", &inorderNodes[i]);
		indOfNodes[ inorderNodes[i] ] = i;
	}

	// the lo index of all nodes of the current subtree in the three lists
	int lo_pre = 0, lo_in = 0, lo_post = 0;
	int len = n, v, ind_v;		// v are the number of current parent node and
								// ind_v are the index of it in the inorder list

	// these Stack are for saving all the lo index and length
	// instead of using recurrence function
	Stack loStack_pre = Stack(2*n);
	Stack loStack_in = Stack(2*n);
	Stack loStack_post = Stack(2*n);
	Stack lenStack = Stack(2*n);

	// push the initial tree
	loStack_pre.push(lo_pre);
	loStack_in.push(lo_in);
	loStack_post.push(lo_post);
	lenStack.push(len);

	while ( !lenStack.isEmpty() )
	{
		lo_pre = loStack_pre.pop();
		lo_in = loStack_in.pop();
		lo_post = loStack_post.pop();
		len = lenStack.pop();

		if ( len == 1 )
		{
			postorderNodes[lo_post] = preorderNodes[lo_pre];
			continue;
		}else if ( len == 0 )
		{
			continue;
		}

		v = preorderNodes[lo_pre];
		ind_v = indOfNodes[v];
		// test the validity of the index of node v
		// If it's out of current range of the nodes,
		// then it's not the same binary tree
		if ( ind_v < lo_in || ind_v >= lo_in + len )
		{
			printf("%d", -1);
			return 0;
		}
		postorderNodes[lo_post+len-1] = v;

		loStack_pre.push( lo_pre + 1 );		// lo index of left child in preorder list
		loStack_in.push( lo_in );			// lo index of left child in inorder list
		loStack_post.push( lo_post );		// lo index of left child in postorder list
		lenStack.push( ind_v - lo_in );		// length of nodes of left child

		lenStack.push( len - ind_v + lo_in - 1 );		// length of nodes of right child
		loStack_pre.push( lo_pre + ind_v - lo_in + 1 );	// lo index of right child in preorder list
		loStack_in.push( ind_v + 1 );					// lo index of right child in inorder list
		loStack_post.push( lo_post + ind_v - lo_in );	// lo index of right child in postorder list
	}

	// print the postorder list
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", postorderNodes[i]);
	}

	return 0;
}

