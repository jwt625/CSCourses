# include<stdio.h>
using namespace std;

/* Bitmap Class
 This class implement a bitmap, and is largely
 based on code from Exercise x2.9 of Data Structure Text book.

 set() and clear() operations are all implemented
 clearAll() is added for O(1) initialization.
*/
class Bitmap{
private:
	int* F; int N;		//F denotes the order of labeled index
	int* T; int top;	//T is a stack of all index in F as time-ordered, top is the top of the stack
protected:
	inline bool valid(int r) { return ( 0 <= r )&&( r < top ); }
	inline bool erased(int k) {
		return valid(F[k])&& !(T[F[k]] + 1 + k );
	}
public:
	Bitmap(int n = 8){	//Initialize the Bitmap for given size
		N = n;
		F = new int[N];
		T = new int[N];
		top = 0;
	}
	~Bitmap(){delete [] F; delete [] T;}	//release memory when destroyed

	inline void set(int k) {
		if ( test(k) ) return;				//ignore if it's already labeled
		if ( !erased(k) ) F[k] = top++;		//if it's erased then recover
		T[F[k]] = k;
	}

	inline void clear(int k) {
		if ( test(k) ) {						//ignore if it's not labeled
			T[F[k]] = - 1 - k;
		}
	}

	inline void clearAll() {					//virtually clear the stack by setting the top to zero
		top = 0;
	}

	inline bool test(int k) {
		return valid( F[k] ) && ( k == T[F[k]] );
	}
};

/* ManageSystem Class
 This class implements the manage system for the company.
 Bitmap is used to track the status of every employer, and has O(1) initialization time.
 All the legal operations are implemented as methods.
*/
class ManageSystem{
private:
	Bitmap * _statusAll;		// status of every employer
	int _nMax;					// max number of employers
	int _nCurrent;				// current number of log-in employers
	int * _codes;				// storing the codes for every employer
public:
	ManageSystem(int n) {		//Initialization for n people
		_nMax = n;
		_statusAll = new Bitmap(_nMax);
		_codes = new int[_nMax];
		_nCurrent = 0;
	}
	~ManageSystem() {
		delete [] _codes;
		delete _statusAll;
	}
	inline void logIn(int i, int code) {
		if ( i >= _nMax ) return;		// ignore out-of-range i
		if ( !_statusAll->test(i) ){	// for unlogged-in employer, log it in
			_nCurrent++;
			_statusAll->set(i);
		}
		_codes[i] = code;				// renew the code
	}
	inline void logOut(int i) {
		if ( i >= _nMax ) return;		// ignore out-of-range i
		if ( _statusAll->test(i) ) {	// for logged-in employer, clear it
			_nCurrent--;
			_statusAll->clear(i);
		}
	}
	inline void close(){
		if ( _nCurrent == 0 ) return;	// ignore if no employer
		_nCurrent = 0;
		_statusAll->clearAll();
	}
	inline int query(int i){
		if ( i >= _nMax ) return -1;	// ignore out-of-range i
		if ( _statusAll->test(i) ) {
			return _codes[i];
		}
		return -1;
	}
	inline int getCurrentN(){
		return _nCurrent;
	}
};

int main(){
#ifndef _OJ_
	freopen( "input.txt", "r", stdin );
	freopen( "output.txt", "w", stdout );
#endif
	
	int n, m;

	scanf( "%d %d\n", &n, &m );
	// initialize the manage system
	ManageSystem manageSys(n);
	// output is used for the final output, worker and code are used for accepting input
	int output = 0, worker, code;
	// op is the operation from input		
	char op;

	for (int inputLine = 0; inputLine < m; ++inputLine)
	{
		scanf( "%c", &op );
		switch(op) {				// switch by the op and call the corresponded method,
		case 'I':					// log in
			scanf( "%d %d\n", &worker, &code );		// note that worker from input starts from 1, 
			manageSys.logIn( worker - 1, code );	// so we need to subtract 1 when passing it to the method.
			break;									
		case 'O':					// log out
			scanf( "%d\n", &worker );
			manageSys.logOut( worker - 1 );
			break;
		case 'C':					// close
			manageSys.close();
			break;
		case 'N':					// query current number of log-in employers
			output += manageSys.getCurrentN();
			break;
		case 'Q':					// query code of given employer
			scanf( "%d\n", &worker );
			output += manageSys.query( worker - 1 );
			break;
		default:				// for other case where op == '\n', '\t', etc, 
			inputLine--;		// continue the loop and prevent inputLine from being increased
			break;
		}
	}
	printf( "%d\n", output );
	return 0;
}
