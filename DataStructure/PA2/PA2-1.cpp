#include <stdio.h>

using namespace std;

// class describing a 2D vector with only basic functionality
class Vector2D
{
private:
	unsigned long long int _x, _y;
public:
	Vector2D() { _x = 0; _y = 0; }
	Vector2D(unsigned long long int x, unsigned long long int y) { _x = x; _y = y; }
	unsigned long long int getX() { return _x; }
	unsigned long long int getY() { return _y; }
};

// This function determines whether the given point is on the left side
// of the given IR line.
bool isLeftSide(Vector2D point, Vector2D IRLine)
{
	if ( point.getX() >= IRLine.getX() )
		return false;
	if ( point.getY() >= IRLine.getY() )
		return false;

	// Now the two vector to compare by vector product is
	// (x1, y1) = (point.x - line.x, point.y) 
	// and
	// (x2, y2) = (-line.x, line.y)
	// where both the two vectors have negative x component
	// Hence I compare minusx1y2 and minusx2y1 to avoid the sign issue
	unsigned long long int minusx1y2 = IRLine.getY()*( IRLine.getX() - point.getX() );
	unsigned long long int minusx2y1 = IRLine.getX()*point.getY() ;
	return minusx2y1 < minusx1y2;
}

int PA21() 
{
#ifndef _OJ_
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

	int n, m;
	scanf("%d %d\n", &n, &m);

	Vector2D * IRLines = new Vector2D[n];
	Vector2D * Points = new Vector2D[m];
	unsigned long long int tmpX, tmpY;

	// Read coordinates of IR lines
	for (int i = 0; i < n; ++i)
	{
		scanf("%llu %llu\n", &tmpX, &tmpY);
		IRLines[i] = Vector2D(tmpX, tmpY);
	}
	// Read coordinates of points
	for (int i = 0; i < m; ++i)
	{
		scanf("%llu %llu\n", &tmpX, &tmpY);
		Points[i] =Vector2D(tmpX, tmpY);
	}

	for (int i = 0; i < m; ++i)
	{
		// Use two-divide version C for finding the line which:
		// 		has smallest index
		// 		and
		// 		the given point is to the left side of it
		int lo = 0, hi = n;
		while ( lo < hi )
		{
			int mi = ( lo + hi ) >> 1;
			isLeftSide(Points[i], IRLines[mi]) ? hi = mi : lo = mi + 1;
		}
		printf("%d\n", lo);
	}
	return 0;
}

