#include <stdio.h>

using namespace std;

// NodeData structure
// saves required information for a node in the binary tree
// lo & hi: interval edges
// count: number of down facing pokefaces within this interval
// coherence: count of two children agree with this node or not
// 			if not, children is going to be updated
struct NodeData {
	int lo;
	int hi;
	int count; 			// number of down pokefaces
	bool coherence;
	NodeData(int _lo, int _hi) { 
		lo = _lo; hi = _hi;
		count = 0;
		coherence = true;
	}
};

// BSST is a binary tree structure
// saved as an pointer array
class BSST {
private:
	NodeData ** _elem;
	int _N;
protected:
	// build the binary tree recursively
	void build(int lo, int hi, int ind) {
		_elem[ind] = new NodeData(lo, hi);
		int mid = (lo+hi)>>1;
		if ( mid > lo ) {
			build(lo, mid, leChInd(ind));
		} else {
			_elem[leChInd(ind)] = new NodeData(lo, lo);
		}
		if ( hi > mid + 1 ) {
			build(mid+1, hi, riChInd(ind));			
		} else {
			_elem[riChInd(ind)] = new NodeData(hi, hi);
		}
	}
	// get index
	inline int leChInd(int ind) {	return 2*ind + 1; }
	inline int riChInd(int ind) { return 2*ind + 2; }
	inline int parentInd(int ind) { return (ind - 1) >> 1; }
	// get node interval length (hi - lo)
	inline int nodeLength(int ind) 
	{ return _elem[ind]->hi - _elem[ind]->lo;}
	inline int nodeMid(int ind) 
	{ return (_elem[ind]->hi + _elem[ind]->lo)>>1; }
	// get and set coherence status
	inline bool isCohere(int ind) { return _elem[ind]->coherence; }
	inline void decohere(int ind) { _elem[ind]->coherence = false; }
	inline void cohere(int ind) { _elem[ind]->coherence = true; }
	// revert the current node, update count and change coherent status
	inline void revert(int ind) {
		_elem[ind]->count = nodeLength(ind) + 1 - _elem[ind]->count;
		// do not change coherent status for length==1 node
		if ( nodeLength(ind) > 0 ) {
			if ( isCohere(ind) ) {
				decohere(ind);
			} else {
				cohere(ind);
			}
		}
	}
	// update the count value of the chosen node
	// according to the count value of the two children
	inline void updateCount(int ind) {
		_elem[ind]->count = _elem[leChInd(ind)]->count 
			+ _elem[riChInd(ind)]->count;
	}
	// revert and update children nodes when an incoherent
	// node is visited
	inline void updateDownDecohere(int ind) {
		if ( !isCohere(ind) ) {
			revert( leChInd(ind) );
			revert( riChInd(ind) );
			cohere(ind);
		}
	}
	// search down i
	// if i == lo,
	// revert current interval and update count up to root
	// if i == hi,
	// go right child until reaching a leaf and then
	// revert and update up
	// else,
	// find the correct sub interval and recursion
	void iHandWaveDown(int i, int ind) {
		// update the decoherence status to the two children
		updateDownDecohere(ind);
		if ( i == _elem[ind]->lo ) {
			revert(ind);
			handWaveUp(ind);
			return;
		}
		// fast down, not necessary
		if ( i == _elem[ind]->hi ) {
			while ( nodeLength(ind) > 0 ) {
				ind = riChInd(ind);
				updateDownDecohere(ind);
			}
			revert(ind);
			handWaveUp(ind);
			return;
		}
		if ( i <= nodeMid(ind) ) {
			// revert right child if i is within left child
			revert(riChInd(ind));
			iHandWaveDown(i, leChInd(ind));
		} else {
			iHandWaveDown(i, riChInd(ind));
		}
	}
	// search down j
	// if j == hi,
	// revert current interval and update count up to root
	// if j == lo,
	// go left child until reaching a leaf and then
	// revert and update up
	// else,
	// find the correct sub interval and recursion
	void jHandWaveDown(int j, int ind) {
		// update the decoherence status to the two children
		updateDownDecohere(ind);
		if ( j == _elem[ind]->hi ) {
			revert(ind);
			handWaveUp(ind);
			return;
		}
		// continue going left child when j == lo
		if ( j == _elem[ind]->lo )
		{
			while ( nodeLength(ind) > 0 ) {
				ind = leChInd(ind);
				updateDownDecohere(ind);
			}
			revert(ind);
			handWaveUp(ind);
			return;
		}
		if ( j > nodeMid(ind) ) {
			revert(leChInd(ind));
			jHandWaveDown(j, riChInd(ind));
		} else {
			jHandWaveDown(j, leChInd(ind));
		}
	}
	// update the count value from current node to root
	void handWaveUp(int ind) {
		if ( 0 == ind) {
			return;
		}
		updateCount(parentInd(ind));
		if (0 != parentInd(ind)){
			handWaveUp(parentInd(ind));
		}
	}
	// query i independently
	// if i==lo,
	// return count of current interval
	// if i==hi,
	// go right child until reaching a leaf and
	// return count (which is 0 or 1)
	// else,
	// find correct sub interval and recursion
	// (add the count of right child if going into left child)
	int iQuery(int i, int ind) {
		// update the decoherence status to the two children
		updateDownDecohere(ind);
		if ( i == _elem[ind]->lo ) {
			return _elem[ind]->count;
		}
		// fast down, not necessary
		if ( i == _elem[ind]->hi ) {
			while ( nodeLength(ind) > 0 ) {
				ind = riChInd(ind);
				updateDownDecohere(ind);
			}
			return _elem[ind]->count;
		}
		if ( i <= nodeMid(ind) ) {
			return iQuery(i, leChInd(ind)) + _elem[riChInd(ind)]->count;
		} else {
			return iQuery(i, riChInd(ind));
		}
	}
	// query j independently
	// if j==hi,
	// return count of current interval
	// if j==lo,
	// go left child until reaching a leaf and
	// return count (which is 0 or 1)
	// else,
	// find correct sub interval and recursion
	// (add the count of left child if going into right child)
	int jQuery(int j, int ind) {
		// update the decoherence status to the two children
		updateDownDecohere(ind);
		if ( j == _elem[ind]->hi ) {
			return _elem[ind]->count;
		}
		// fast down, not necessary
		if ( j == _elem[ind]->lo ) {
			while ( nodeLength(ind) > 0 ) {
				ind = leChInd(ind);
				updateDownDecohere(ind);
			}
			return _elem[ind]->count;
		}
		if ( j > nodeMid(ind) ) {
			return _elem[leChInd(ind)]->count + jQuery(j, riChInd(ind));
		} else {
			return jQuery(j, leChInd(ind));
		}
	}
public:
	// construction
	BSST(int N) {
		int tmpn = N;
		_N = 1;
		while ( tmpn > 0) {
			tmpn = tmpn >> 1;
			_N = _N << 1;
		}
		_N = _N << 1;
		_elem = new NodeData*[_N];
		// initialize the pointer array
		for (int i = 0; i < _N; ++i)
		{
			_elem[i] = NULL;
		}
		// build the binary tree (recursively)
		build(0, N-1, 0);
	}
	// deconstruct
	~BSST() {
		for (int i = 0; i < _N; ++i)
		{
			delete _elem[i];
		}
		_elem = NULL;
	}
	// print the tree, for debug visualization
	void print() {
		for (int i = 0; i < _N; ++i)
		{
			if ( NULL != _elem[i] ) {
				printf("ind=%d %d~%d count=%d isCohe=%d\n",
					 i, _elem[i]->lo, _elem[i]->hi, _elem[i]->count, _elem[i]->coherence);
			} else {
				printf("ind=%d null\n", i);
			}
		}
	}
	// method for the H operation
	// update the decoherence status to children nodes
	// when stepping onto a node
	// first search down i & j at the same time, return if them
	// match the interval edges;
	// when i & j go to different intervals, call
	// iHandWaveDown and jHandWaveDown to search down i & j,
	// revert bypassed intervals within i~j and update decoherence status
	void handWave(int i, int j) {
		bool ijCoexist = true;
		int ind = 0;
		NodeData * currentNode = _elem[ind];
		while (ijCoexist) {
			// update the decoherence status to the two children
			updateDownDecohere(ind);
			if ( currentNode->lo == i && currentNode->hi == j ) {
				revert(ind);
				handWaveUp(ind);	// remember to update up the count value!
				return;
			}
			if ( j <= nodeMid(ind) ) {
				ind = leChInd(ind);
				currentNode = _elem[ind];
				continue;
			} else if ( i > nodeMid(ind) ) {
				ind = riChInd(ind);
				currentNode = _elem[ind];
				continue;
			} else {
				ijCoexist = false;
			}
		}
		iHandWaveDown(i, leChInd(ind));
		jHandWaveDown(j, riChInd(ind));
	}
	// method for the Q operation
	// update the decoherence status to children nodes
	// when stepping onto a node
	// first search down i & j at the same time, return if them
	// match the interval edges;
	// when i & j go to different intervals, call
	// iQuery and jQuery to query the count
	// note that iQuery and jQuery returns number of 
	// pokefaces facing down, hence use the length of 
	// the querying to subjract those two value
	int query(int i, int j) {
		bool ijCoexist = true;
		int ind = 0;
		NodeData * currentNode = _elem[ind];
		while (ijCoexist) {
			// update the decoherence status to the two children
			updateDownDecohere(ind);
			if ( currentNode->lo == i && currentNode->hi == j ) {
				return j - i + 1 - currentNode->count;
			}
			// go to left child if i & j both in it
			if ( j <= nodeMid(ind) ) {
				ind = leChInd(ind);
				currentNode = _elem[ind];
				continue;
			}
			// go to right child if i & j both in it 
			else if ( i > nodeMid(ind) ) {
				ind = riChInd(ind);
				currentNode = _elem[ind];
				continue;
			} else {
				ijCoexist = false;
			}
		}
		return j - i + 1 - iQuery(i, leChInd(ind)) - jQuery(j, riChInd(ind));
	}

};


int main() {	
#ifndef _OJ_
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int n, m;
	scanf("%d %d\n", &n, &m);

	BSST bsst(n);

	char op;
	int ind_i, ind_j;
	for (int i = 0; i < m; ++i)
	{
		scanf("%c %d %d\n", &op, &ind_i, &ind_j);
		// switch between two options
		switch (op) {
			case 'H':
			bsst.handWave(ind_i-1, ind_j-1);
			break;
			case 'Q':
			printf("%d\n", bsst.query(ind_i-1, ind_j-1));
			break;
			default:
			i--;
			break;
		}
	}

	return 0;
}