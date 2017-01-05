#include <stdio.h>
using namespace std;

#define _INT_MAX 2147483647

// complete binary heap
// only percolate down is required
class ComplHeap {
private:
	int * _elem;
	int _N;
protected:	
	// get index
	inline int leChInd(int ind) { return 2*ind + 1; }
	inline int riChInd(int ind) { return 2*ind + 2; }
	inline int parentInd(int ind) { return (ind - 1) >> 1; }
	// swap operation
	inline void swap(int i, int j) {
		int tmp = _elem[i];
		_elem[i] = _elem[j];
		_elem[j] = tmp;
	}
	// methods for convenience
	inline bool inHeap(int ind) { return ( -1 < ind && ind < _N); }
	inline int bigger(int i, int j) {
		return _elem[i] < _elem[j] ? j : i;
	}
	inline int properParent(int ind) {
		return ( inHeap(riChInd(ind)) ? bigger( bigger(ind, leChInd(ind)), riChInd(ind)) :\
				( inHeap(leChInd(ind)) ? bigger( ind, leChInd(ind)) : ind \
				)\
			);
	}
	// percolate down
	int percolateDown(int i) {
		int j;
		while( i != ( j = properParent(i) ) ) {
			swap(i, j);
			i = j;
		}
		return i;
	}
public:
	ComplHeap(int n) {
		_N = n;
		_elem = new int[n];
		for (int i = 0; i < n; ++i)
		{
			_elem[i] = _INT_MAX;
		}
	}
	int getMax() { return _elem[0]; }
	// delete max, insert new element as root and
	// percolate down
	int delMaxInsert(int item) {
		int maxElem = _elem[0];
		_elem[0] = item;
		percolateDown(0);
		return maxElem;
	}
};

int main() {	
#ifndef _OJ_
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

	int n; int k;
	fread(&n, sizeof(int), 1, stdin);
	fread(&k, sizeof(int), 1, stdin);

	// only create a heap with size = k
	// i.e., only tracking the k smallest elements
	ComplHeap complHeap(k);
	for (int i = 0; i < n; ++i)
	{
		fread(&k, sizeof(int), 1, stdin);
		// if new element k is smaller than the k-th smallest
		// element, insert it into the heap
		if ( k < complHeap.getMax() )
		{
			complHeap.delMaxInsert(k);
		}
	}
	printf("%d\n", complHeap.getMax() );

	return 0;
}
