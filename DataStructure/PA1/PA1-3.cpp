#include <stdio.h>
using namespace std;

/* class RoundTableChair
   This class simulate the round table by a cyclic chain.
   Methid insert will insert a new chair to the chair chain according to the rule.
*/
class RoundTableChair {
private:
	int _chairID;
	RoundTableChair* _nextChair;
public:
	RoundTableChair(int id) {		// initialization, where the next chair pointed to self
		_chairID = id;
		_nextChair = this;
	}
	inline void insert(int m, RoundTableChair* toInsert) {
		RoundTableChair* insertRight = this;	// for m = 1, toInsert will be insert right to this
		for (int i = 0; i < m - 1; ++i)			// move to next m - 1 chair if m > 1
		{
			insertRight = insertRight->_nextChair;
		}
		toInsert->_nextChair = insertRight->_nextChair;		//insert toInsert between insertRight and the one next to insertRight
		insertRight->_nextChair = toInsert;
	}
	inline RoundTableChair* getNextChair() {
		return _nextChair;
	}
	inline int getID() {
		return _chairID;
	}
};

int main() {
#ifndef _OJ_
	freopen( "input.txt", "r", stdin );
	freopen( "output.txt", "w", stdout );
#endif

	int n, m;
	scanf("%d %d\n", &n, &m);
	int id;
	int * orderedIDs = new int[n];
	scanf("%d ", &id);
	RoundTableChair* latestChair = new RoundTableChair(id);

	// read id and insert, starting from latestChair and according to m
	for (int i = 0; i < n - 1; ++i)
	{
		scanf("%d ", &id);			
		RoundTableChair* currentChair = new RoundTableChair(id);
		latestChair->insert(m, currentChair);
		latestChair = currentChair;	// the next insertion will start from the previous inserted chair
	}

	// read all IDs by order of chairs， starting from the last inserted chair
	for (int i = 0; i < n; ++i)		
	{
		orderedIDs[i] = latestChair->getID();	
		latestChair = latestChair->getNextChair();
	}

	// output by the reversed direction, as required
	printf("%d ", orderedIDs[0]);		
	for (int i = 0; i < n - 1; ++i)
	{
		printf("%d ", orderedIDs[n - 1 - i]);
	}
}