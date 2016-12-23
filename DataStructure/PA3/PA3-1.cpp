#include <stdio.h>

using namespace std;

// This structure describe an Edge for a NeighborChart
// nextEdge is initialized as a NULL pointer
struct Edge {
	int _v;
	int _e;
	Edge * nextEdge;
	Edge(int v, int e) { _v = v; _e = e; nextEdge = NULL; }
};

// This is a basic Stack structure
// with usual pop, push, top method, etc.
class Stack {
private:
	int * _elem;
	int _N;
	int _top;
public:
	Stack(int N) { _N = N; _elem = new int[_N]; _top = 0; }
	~Stack() { delete [] _elem; }
	int pop() { return _elem[--_top]; }
	void push(int item) { _elem[_top++] = item; }
	const int getTop() { return _top; }
	const int operator[](int i) { return _elem[i]; }
	const int top() { return _elem[_top-1]; }
	const bool isEmpty() { return 0 == _top; }
};

// NeighborChart use a Chart to save the directed graph
// Method:
// 		addEdge
// 		getFirstEdge
// 		printGraph
// 		getTopoOrder
// 		inDeg
// 		outDeg
class NeighborChart {
private:
	int _numOfV;
	int _numOfE;
	Edge ** _allV;
public:
	NeighborChart(int v) {
		_numOfV = v;
		_numOfE = 0;
		_allV = new Edge*[_numOfV];
		for (int i = 0; i < _numOfV; ++i)
		{
			_allV[i] = NULL;
		}
	}
	~NeighborChart() {
		for (int i = 0; i < _numOfV; ++i)
		{
			delete _allV[i];
		}
		_allV = NULL;
	}
	// Add an edge to the current graph
	// newest edge always inserted as the first one
	void addEdge(int v1, int v2, int e) {
		Edge* arc = new Edge(v2, e);
		if (NULL == _allV[v1]) {
			_allV[v1] = arc;
		} else {
			arc->nextEdge = _allV[v1]->nextEdge;
			_allV[v1]->nextEdge = arc;
		}
		_numOfE++;
	}
	// Return the first edge of the chosen vertex
	// return a NULL pointer if the vertex has no outgoing edge
	Edge * getFirstEdge(int v) {
		return _allV[v];
	}
	// For testing the graph is correctly saved or not
	void printGraph() {
		for (int i = 0; i < _numOfV; ++i)
		{
			printf("%d: ", i + 1);
			Edge * tmpEdge = _allV[i];
			while (tmpEdge != NULL) {
				printf("v%d e%d, ", \
					tmpEdge->_v + 1, \
					tmpEdge->_e);
				tmpEdge = tmpEdge->nextEdge;
			}
			printf("\n");
		}
	}
	// This method compute the topology order of the graph
	// Use a graph with all edge inverted to get the inDegree
	// return the ordered vertex index
	int * getTopoOrder(NeighborChart * reversedNbChart) {
		int * inDegs = new int[_numOfV];
		int tmpV;
		Edge * currentEdge;
		Stack zeroInDegVert(_numOfV); 	// All discovered zero in degree vertex
		Stack topoOrder(_numOfV);			// All processed (in degree of its next vertex subtracted by one) zero in degree vertex
		for (int i = 0; i < _numOfV; ++i)
		{
			inDegs[i] = inDeg(reversedNbChart, i);
			if ( 0 == inDegs[i] )
			{
				zeroInDegVert.push(i);
			}
		}
		while(!zeroInDegVert.isEmpty()) {
			tmpV = zeroInDegVert.pop();
			topoOrder.push(tmpV);
			currentEdge = getFirstEdge(tmpV);
			while(NULL != currentEdge) {
				inDegs[currentEdge->_v]--;
				if(0 == inDegs[currentEdge->_v]) {
					zeroInDegVert.push(currentEdge->_v);
				}
				currentEdge = currentEdge->nextEdge;
			}
		}
		// Planned to return a Stack object, succeeded in VS2012
		// but compilation failed on OJ, hence changed to return
		// an array
		int * order = inDegs;    // rename the pointer to avoid confusion
		for (int i = 0; i < _numOfV; ++i)
		{
			order[i] = topoOrder[i];
		}
		return order;
	}
	// This method compute the in degree of the chosen vertex
	// Based on a reversed graph
	int inDeg(NeighborChart * reversedNbChart, int v) {
		Edge * currentEdge = reversedNbChart->getFirstEdge(v);
		int inDeg = 0;
		while(NULL != currentEdge) {
			inDeg++;
			currentEdge = currentEdge->nextEdge;
		}
		return inDeg;
	}
	// This method computes the out degree of chosen vertex
	int outDeg(int v) {
		int outDeg = 0;
		Edge * currentEdge = getFirstEdge(v);
		while(NULL != currentEdge) {
			outDeg++;
			currentEdge = currentEdge->nextEdge;
		}
		return outDeg;
	}
};


int PA3_1() {	
#ifndef _OJ_
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int n, m;
	scanf("%d %d\n", &n, &m);

	// Initialize the two Neighbor Chart
	NeighborChart neighborChart(n);
	NeighborChart neighborChartInv(n);

	int tmpV1, tmpV2, tmpE;
	// read the graph information
	for (int i = 0; i < m; ++i)
	{
		scanf("%d %d %d\n", &tmpV1, &tmpV2, &tmpE);
		neighborChart.addEdge(tmpV1 - 1, tmpV2 - 1, tmpE);
		neighborChartInv.addEdge(tmpV2 - 1, tmpV1 - 1, tmpE);
	}

	// get the topologic ordered vertex index
	int * topoOrder = neighborChart.getTopoOrder(&neighborChartInv);

	// valuesOfVert saves the value of each vertex, starting from
	// the end of the topoOrder to the beginning.
	// The value of each vertex is the largest sum of edge weights
	// to the end
	int * valuesOfVert = new int[n];
	// Index of next vertex in the max weight path of the chosen vertex
	int * nextMaxWeightPathVert = new int[n];

	int indV, val, indNextV;
	Edge * currentEdge;

	// label each vertex with the max value to the end of possible paths
	// starting from the last vertex in the topological order
	// values of each vertex saved in valuesOfVert, while
	// next vertex of each vertex saved in nextMaxWeightPathVert, hence
	// the whole path can be quickly revived
	for (int i = 0; i < n; ++i)
	{
		val = 0;
		indNextV = -1;  			// -1 means no next vertex
		indV = topoOrder[n-1-i];    // Iterate starting from the end of the topoOrder
		currentEdge = neighborChart.getFirstEdge(indV);
		while( NULL != currentEdge ) {
			// if a path with larger value is found, update val and indNextV
			if ( val < currentEdge->_e + valuesOfVert[currentEdge->_v] )
			{
				val = currentEdge->_e + valuesOfVert[currentEdge->_v];
				indNextV = currentEdge->_v;
			} else if ( val == currentEdge->_e + valuesOfVert[currentEdge->_v] ) {
				// The dictionary order is considered here
				if ( indNextV > currentEdge->_v )
				{
					indNextV = currentEdge->_v;
				}
			}
			currentEdge = currentEdge->nextEdge;
		}
		valuesOfVert[indV] = val;
		nextMaxWeightPathVert[indV] = indNextV;
	}

	// Choose and print resulting path
	val = 0;
	for (int i = 0; i < n; ++i)
	{
		// check all starting paths
		if ( 0 == neighborChart.inDeg(&neighborChartInv, i) )
		{
			// For the case of equal value, since the starting vertex
			// is examed from small to large, hence the dictionary order
			// is automatically satisfied for equal case
			if ( valuesOfVert[i] > val )
			{
				indV = i;		// change starting vertex and update val
				val = valuesOfVert[indV];
			}
		}
	}
	printf("%d", indV + 1);
	indNextV = nextMaxWeightPathVert[indV];
	while( -1 != indNextV ) {
		printf("\t%d", indNextV + 1);
		indNextV = nextMaxWeightPathVert[indNextV];
	}
	return 0;
}