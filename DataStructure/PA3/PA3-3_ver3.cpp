#include <stdio.h>
#include <stdlib.h>
#include "temperature.h"

//#define _CRTDBG_MAP_ALLOC
//#include <crtdbg.h>
//
//#define _DEBUG
//#ifdef _DEBUG
//   #ifndef DBG_NEW
//      #define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
//      #define new DBG_NEW
//   #endif
//#endif  // _DEBUG

using namespace std;

struct coord2D {
	int x;
	int y;
	coord2D() {
		x = 0; y = 0;
	}
	coord2D(int _x, int _y) {
		x = _x; y = _y;
	}
	coord2D(const coord2D & coord){
		x = coord.x; y = coord.y;
	}
	bool operator<(coord2D coord) {
		if (x < coord.x)
			return true;
		if (x == coord.x) {
			if (y < coord.y)
				return true;
		}
		return false;
	}
	bool operator==(coord2D coord) {
		if (x == coord.x && y == coord.y)
			return true;
		return false;
	}
	bool operator<=(coord2D coord) {
		if (x > coord.x)
			return false;
		if (x == coord.x && y > coord.y)
			return false;
		return true;
	}
};

struct YNode {
	int y;
	int temp;
	bool isEnd;
	YNode * lc;
	YNode * rc;
	YNode() {
		y = 0;
		temp = 0;
		lc = NULL;
		rc = NULL;		
		isEnd = false;
	}
	YNode(int _y, int _temp) {
		y = _y;
		temp = _temp;
		lc = NULL;
		rc = NULL;
		isEnd = false;
	}
};

struct XNode {
	YNode * yNodes;
	int lenYs;
	coord2D val;
	int numOfPoints;
	int tempSum;
	XNode(YNode * yn, int len, coord2D v) {
		yNodes = yn;
		lenYs = len;
		val = v;
		numOfPoints = 0;
		tempSum = 0;
	}
};

class RangeTree {
private:
	XNode ** _elem;
	int _N;
	int _n;
	coord2D * coords;			// Sorted
	int * temps;				// Unsorted
	int * indXSorted;			// Sorted

protected:
	void build(int lo, int hi, int ind, YNode * yNodes) {
		if ( hi - lo == 1)
		{
			_elem[ind] = new XNode(yNodes, 1, coords[lo]);
			return;
		}
		int mid = (lo + hi)>>1;

		int lcYlen = mid - lo;
		int * tmpYs = new int[lcYlen];
		int * indYSorted = new int[lcYlen];
		for (int i = 0; i < lcYlen; ++i)
		{
			tmpYs[i] = coords[lo + i].y;
			indYSorted[i] = indXSorted[lo + i];
		}
		quickSort(tmpYs, indYSorted, 0, lcYlen);
		YNode * lcYNodes = new YNode[lcYlen];
		for (int i = 0; i < lcYlen; ++i)
		{
			lcYNodes[i].y = tmpYs[i];
			lcYNodes[i].temp = temps[indYSorted[i]];
		}
		lcYNodes[lcYlen-1].isEnd = true;
		delete [] tmpYs;
		delete [] indYSorted;

		int rcYlen = hi - mid;		
		tmpYs = new int[rcYlen];
		indYSorted = new int[rcYlen];
		for (int i = 0; i < rcYlen; ++i)
		{
			tmpYs[i] = coords[mid + i].y;
			indYSorted[i] = indXSorted[mid + i];
		}
		quickSort(tmpYs, indYSorted, 0, rcYlen);
		YNode * rcYNodes = new YNode[rcYlen];
		for (int i = 0; i < rcYlen; ++i)
		{
			rcYNodes[i].y = tmpYs[i];
			rcYNodes[i].temp = temps[indYSorted[i]];
		}
		rcYNodes[rcYlen-1].isEnd = true;		
		delete [] tmpYs;
		delete [] indYSorted;

		// link the yNodes to children yNodes as proposed in
		// fractional cascading
		int leTop = 0;
		int riTop = 0;
		bool isBeyond = false;
		for (int i = 0; i < hi - lo; ++i)
		{
			while ( yNodes[i].y > lcYNodes[leTop].y ) {
				leTop++;
				if (leTop >= lcYlen)
				{
					isBeyond = true;
					break;
				}
			}
			if (isBeyond)
				break;
			yNodes[i].lc = &lcYNodes[leTop];
		}
		isBeyond = false;
		for (int i = 0; i < hi - lo; ++i)
		{
			while ( yNodes[i].y > rcYNodes[riTop].y ) {
				riTop++;
				if (riTop >= rcYlen)
				{
					isBeyond = true;
					break;
				}
			}
			if (isBeyond)
				break;
			yNodes[i].rc = &rcYNodes[riTop];
		}
		_elem[ind] = new XNode(yNodes, hi - lo, coords[mid]);

		build(lo, mid, lcInd(ind), lcYNodes);
		build(mid, hi, rcInd(ind), rcYNodes);
	}
	// get index
	inline int lcInd(int ind) {	return 2*ind + 1; }
	inline int rcInd(int ind) { return 2*ind + 2; }
	inline int paInd(int ind) { return (ind - 1) >> 1; }

	inline coord2D nodeVal(int ind) { 
		if (_elem[ind] == NULL)
			return coord2D(0,0);
		return _elem[ind]->val; 
	}
	inline int nodeYNodesLen(int ind) { 
		if (_elem[ind] == NULL)
			return 0;
		return _elem[ind]->lenYs;
	}
	inline YNode * nodeYNodes(int ind) {
		if (_elem[ind] == NULL)
			return NULL;
		return _elem[ind]->yNodes;
	}
	// implement quickSort according to location Xs.
	// The weights are also changed the same way at the same time.
	template <typename T1, typename T2>
	void quickSort(T1* toSort, T2 * toFollow, int lo, int hi) {
		if (hi - lo < 2) return;

		// The function call stack will overflow,
		// hence I rewrite the quickSort without recursion
		// a stack-like int array is used for storing 
		// the lo and hi for those sub-intervals
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
		delete [] lohiStack;
	}

	// version A pf partition
	template <typename T1, typename T2>
	int partition(T1* toSort, T2 * toFollow, int lo, int hi) {		
		int indSwap = lo + rand() % ( hi - lo + 1 );
		swap(toSort, lo, indSwap);
		if (NULL != toFollow)
			swap(toFollow, lo, indSwap);
		T1 pivot = toSort[lo];
		T2 pivotFollow;
		if (NULL != toFollow)
			pivotFollow = toFollow[lo];
		while (lo < hi ) {
			while ( (lo < hi) && ( pivot <= toSort[hi]) )
				hi--;
			toSort[lo] = toSort[hi];
			if (NULL != toFollow)
				toFollow[lo] = toFollow[hi];
			while( (lo < hi) && ( toSort[lo] <= pivot) )
				lo++;
			toSort[hi] = toSort[lo];
			if (NULL != toFollow)
				toFollow[hi] = toFollow[lo];
		}// assert: lo == hi
		toSort[lo] = pivot;
		if (NULL != toFollow)
			toFollow[lo] = pivotFollow;
		return lo;
	}

	template <typename T>
	void swap(T* toSwap, int i, int j){
		T tmp = toSwap[i];
		toSwap[i] = toSwap[j];
		toSwap[j] = tmp;
	}

	void reportSubTree(int ind, YNode * yNode, int y2,
		int * tempSum, int * pointNum) {
		if (NULL == yNode) {
			return;
		}
		while ( yNode->y <= y2 ) {
			*tempSum = *tempSum + yNode->temp;
			*pointNum = *pointNum + 1;
			if ( yNode->isEnd )
			{
				break;
			}
			yNode++;
		}
	}

	void lQuery(int ind, coord2D xmin,
		YNode * yNode, int y2, int * tempSum, int * pointNum) {
		if (NULL == yNode) {
			return;
		}
		if ( yNode->y > y2 ) {
			return;
		}
		if ( nodeYNodesLen(ind) == 1 )
		{
			if ( !(nodeVal(ind) < xmin) )
			{
				reportSubTree(ind, yNode, y2, tempSum, pointNum);
				return;
			} else {
				return;
			}
		}
		if ( nodeVal(ind) == xmin ) {
			reportSubTree(rcInd(ind), yNode->rc, y2, tempSum, pointNum);
			return;
		}
		if ( xmin < nodeVal(ind))
		{
			int ltempSum = 0, lpointNum = 0, 
				rtempSum = 0, rpointNum = 0;
				lQuery(lcInd(ind), xmin, yNode->lc, y2,
					&ltempSum, &lpointNum);
				reportSubTree(rcInd(ind), yNode->rc, y2,
					&rtempSum, &rpointNum);
			// }
			*pointNum = *pointNum + lpointNum + rpointNum;
			*tempSum = *tempSum + ltempSum + rtempSum;
			return;
		} else {
			lQuery(rcInd(ind), xmin, yNode->rc, y2,
				tempSum, pointNum);
			return;
		}
		return;
	}

	void rQuery(int ind, coord2D xmax,
		YNode * yNode, int y2, int * tempSum, int * pointNum) {
		if (NULL == yNode) {
			return;
		}
		if ( yNode->y > y2 ) {
			return;
		}
		if ( nodeYNodesLen(ind) == 1 )
		{
			if ( !(xmax < nodeVal(ind)) )
			{
				reportSubTree(ind, yNode, y2,
					tempSum, pointNum);
				return;
			} else {
				*tempSum = 0;
				*pointNum = 0;
				return;
			}
		}
		if ( !( xmax < nodeVal(ind) ) )
		{
			int ltempSum = 0, lpointNum = 0, 
				rtempSum = 0, rpointNum = 0;
				rQuery(rcInd(ind), xmax, yNode->rc, y2,
					&rtempSum, &rpointNum);
				reportSubTree(lcInd(ind), yNode->lc, y2,
					&ltempSum, &lpointNum);
			*pointNum = *pointNum + lpointNum + rpointNum;
			*tempSum = *tempSum + ltempSum + rtempSum;
			return;
		} else {
			rQuery(lcInd(ind), xmax, yNode->lc, y2,
				tempSum, pointNum);
			return;
		}
		return;
	}

public:
	RangeTree(int n, coord2D * _coords, int * _temps) {
		int tmpn = n;
		_n = n;
		coords = _coords;
		//ys = _ys;
		temps = _temps;
		indXSorted = new int[_n];
		for (int i = 0; i < _n; ++i)
		{
			indXSorted[i] = i;
		}

		quickSort(coords, indXSorted, 0, _n);

		_N = 1;
		while ( tmpn > 0) {
			tmpn = tmpn >> 1;
			_N = _N << 1;
		}
		_N = _N << 1;		
		_elem = new XNode*[_N];
		// initialize the pointer array
		for (int i = 0; i < _N; ++i)
		{
			_elem[i] = NULL;
		}

		int * tmpYs = new int[_n];
		int * indYSorted = new int[_n];
		for (int i = 0; i < _n; ++i)
		{
			tmpYs[i] = coords[i].y;
			indYSorted[i] = i;
		}

		quickSort(tmpYs, indYSorted, 0, _n);

		YNode * yNodes = new YNode[_n];
		for (int i = 0; i < _n; ++i)
		{
			yNodes[i].y = tmpYs[i];
			yNodes[i].temp = temps[indYSorted[i]];
		}
		yNodes[_n-1].isEnd = true;
		// yNodes is not linked to yNodes in the two subtree,
		// which is going to be done in the build function
		delete [] tmpYs;
		delete [] indYSorted;
		build(0, _n, 0, yNodes);
	}
	// deconstruction
	~RangeTree() {		
		for (int i = 0; i < _N; ++i)
		{
			if (NULL != _elem[i])
			{
				delete [] _elem[i]->yNodes;
				delete _elem[i];				
			}
		}
		delete [] indXSorted;
		_elem = NULL;
	}
	void print() {
		for (int i = 0; i < _N; ++i)
		{
			if ( NULL != _elem[i] ) {
				printf("ind=%d val=%d,%d\n", i, nodeVal(i).x, nodeVal(i).y);
				YNode * tmpYNodes = nodeYNodes(i);
				printf("\t%d YNodes: \n\t\t", _elem[i]->lenYs);
				for (int j = 0; j < nodeYNodesLen(i); ++j)
				{
					printf("%d ", (tmpYNodes + j)->y);
					if ( NULL != (tmpYNodes + j)->lc)
					{
						printf("lc=%d ", (tmpYNodes + j)->lc->y);
					}
					if ( NULL != tmpYNodes[j].rc)
					{
						printf("rc=%d ", (tmpYNodes + j)->rc->y);
					}
					printf(" t=%d\n\t\t", (tmpYNodes + j)->temp);
				}
				printf("\n");
			}
		}
	}
	int query(int x1, int y1, int x2, int y2) {
		coord2D coord1(x1, y1);
		coord2D coord2(x2, y2);
		bool lrCoexist = true;
		int ind = 0;
		while (lrCoexist) {
			if ( nodeYNodesLen(ind) == 1 )
			{
				YNode * yNode = nodeYNodes(ind);
				if ( x1 <= nodeVal(ind).x && x2 >= nodeVal(ind).x
					&& y1 <= yNode-> y && y2 >= yNode->y)
				{
					return yNode->temp;
				}
				return 0;
			}
			if ( coord2 < nodeVal(ind) )
			{
				ind = lcInd(ind);
				continue;
			}
			if ( !( coord1 < nodeVal(ind) ) )
			{
				ind = rcInd(ind);
				continue;
			} else {
				lrCoexist = false;
			}
		}
		// search for first y_ind which is no less than y1
		int loIndY = 0, hiIndY = nodeYNodesLen(ind), midIndY;
		bool indY1Found = false;
		while (hiIndY - loIndY > 1) {
			midIndY = (hiIndY + loIndY)>>1;
			if ( y1 <= (nodeYNodes(ind) + midIndY)->y )
			{
				hiIndY = midIndY;
				while (y1 <= (nodeYNodes(ind) + midIndY)->y) {
					midIndY = (midIndY + loIndY)>>1;
					if (midIndY == loIndY) {
						indY1Found = true;
						if ( y1 > (nodeYNodes(ind) + midIndY)->y )
							midIndY++;
						break;
					}
				}
				if (indY1Found)
					break;
				loIndY = midIndY;
			} else {
				while ( y1 > (nodeYNodes(ind) + midIndY)->y ) {
					midIndY = (midIndY + hiIndY)>>1;
					if (midIndY == hiIndY - 1) {
						indY1Found = true;
						if ( y1 > (nodeYNodes(ind) + midIndY)->y )
							midIndY = hiIndY;
						break;
					}
				}
				if (indY1Found)
					break;
				hiIndY = midIndY;
			}
		}
		int ltempSum = 0, rtempSum = 0, 
			lpointNum = 0, rpointNum = 0;
		lQuery(lcInd(ind), coord1,
			(nodeYNodes(ind) + midIndY)->lc, y2,
			&ltempSum, &lpointNum);
		rQuery(rcInd(ind), coord2,
			(nodeYNodes(ind) + midIndY)->rc, y2,
			&rtempSum, &rpointNum);
			
		if (lpointNum + rpointNum == 0)
		{
			return 0;
		}
		return (ltempSum + rtempSum)/(lpointNum + rpointNum);
	}

};
//
//int testCoord2D() {
//	coord2D coord1 = coord2D(1, 2);
//	coord2D coord2 = coord2D(1, 3);
//	coord2D cd3 = coord1;
//	bool tmp = coord1 < coord2;
//	printf("%d\n", tmp);
//	printf("x=%d y=%d\n", cd3.x, cd3.y);
//	return 0;
//}

int main() {	
#ifndef _OJ_
	freopen("input.txt","r",stdin);
#ifndef _debug_
	freopen("output.txt","w",stdout);
#endif
#endif
	int n = GetNumOfStation();
	coord2D * coords = new coord2D[n];
	int * temps = new int[n];

	for (int i = 0; i < n; ++i)
	{
		GetStationInfo(i, &coords[i].x, &coords[i].y, temps + i);
	}

	RangeTree rangeTree(n, coords, temps);

#ifdef _debug_
	rangeTree.print();
#endif
	rangeTree.print();
	int x1, x2, y1, y2, state;

	while(true) {
		state = GetQuery(&x1, &y1, &x2, &y2);
		Response(rangeTree.query(x1, y1, x2, y2));
		if (!state)
			break;
	};
	delete [] coords;
	delete [] temps;

	//_CrtDumpMemoryLeaks();


	return 0;
}



