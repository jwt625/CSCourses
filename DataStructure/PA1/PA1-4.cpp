#include <stdio.h>
#include <stdlib.h>
using namespace std;


int partition(int* toSort, int* toFollow, int lo, int hi);

void quickSort(int* toSort, int* toFollow, int lo, int hi);

void swap(int* toSwap, int i, int j);

int main() {
#ifndef _OJ_
	freopen( "input.txt", "r", stdin );
	freopen( "output.txt", "w", stdout );
#endif

	int n;
	scanf("%d\n", &n);

	int* allWs = new int[n];
	int* allXs = new int[n];
	long long int sumW = 0;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d %d\n", &allXs[i], &allWs[i]);
		sumW += (long long int)allWs[i];
	}

	// From mathematical analysis, the location of the hospital should make the sum of weight of
	// counties on the left side of it to be less than the sum of counties on the right side of it.
	// Hence we sort the counties by X first and then count the sum from left to right.
	quickSort(allXs, allWs, 0, n);

	long long int sumWLeft = 0; int indX = 0;
	do {
		sumWLeft += (long long int)allWs[indX];
		indX++;
	} while(sumWLeft*2 < sumW);

	// now the total weight sum is at least not decreasing from position allXs[indX-1] to allXs[indX]
	// hence the hospital should be located at allXs[indX-1]
	indX--;

	printf("%d\n", allXs[indX]);	// print the position of the hospital

	long long int sumWD = 0;
	// calculate the weight sum
	for (int i = 0; i < n; ++i)
	{
		sumWD += ( (long long int) abs(allXs[i] - allXs[indX]) )*( (long long int) allWs[i] );
	}

	printf("%lld\n", sumWD);

	return 0;
}

// implement quickSort according to location Xs. The weights are also changed the same way at the same time.
void quickSort(int* toSort, int* toFollow, int lo, int hi) {
	if (hi - lo < 2) return;
	//int mi = partition(toSort, toFollow, lo, hi - 1);	// construct pivot
	//quickSort(toSort, toFollow, lo, mi);				// sort left portion
	//quickSort(toSort, toFollow, mi + 1, hi);			// sort right portion

	// The function call stack will overflow, hence I rewrite the quickSort without recursion
	// a stack-like int array is used for storing the lo and hi for those sub-intervals
	int* lohiStack = new int[hi];
	int top = 0;
	lohiStack[top++] = lo;
	lohiStack[top++] = hi;
	int mi, subLo, subHi;
	while (top > 0)
	{
		subHi = lohiStack[--top];
		subLo = lohiStack[--top];
		mi = partition(toSort, toFollow, subLo, subHi - 1);
		if (subLo < mi - 1) {
			lohiStack[top++] = subLo;
			lohiStack[top++] = mi;
		}
		if (subHi > mi + 1) {
			lohiStack[top++] = mi + 1;
			lohiStack[top++] = subHi;
		}
	}
}

int partition(int* toSort, int* toFollow, int lo, int hi) {		// version A pf partition
	int indSwap = lo + rand() % ( hi - lo + 1 );
	swap(toSort, lo, indSwap);
	swap(toFollow, lo, indSwap);
	int pivot = toSort[lo];
	int pivotFollow = toFollow[lo];
	while (lo < hi ) {
		while ( (lo < hi) && ( pivot <= toSort[hi]) )
			hi--;
		toSort[lo] = toSort[hi];
		toFollow[lo] = toFollow[hi];
		while( (lo < hi) && ( toSort[lo] <= pivot) )
			lo++;
		toSort[hi] = toSort[lo];
		toFollow[hi] = toFollow[lo];
	}// assert: lo == hi
	toSort[lo] = pivot;
	toFollow[lo] = pivotFollow;
	return lo;
}

void swap(int* toSwap, int i, int j){
	int tmp = toSwap[i];
	toSwap[i] = toSwap[j];
	toSwap[j] = tmp;
}



