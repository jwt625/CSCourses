#include <stdio.h>
using namespace std;

// structure describing an dictionary item
struct DictItem {
	char * str;
	unsigned short int count;
	DictItem * nextItem;
	// initialization
	DictItem(char * _str) {
		count = 1;
		nextItem = NULL;
		str = new char[9];
		for (int i = 0; i < 9; i++)
		{
			str[i] = _str[i];
			if (str[i] == '\0')
				break;
		}
	}
	// string compare
	bool equal(char * _str) {
		for (int i = 0; i < 9; i++)
		{
			if (str[i] == '\0' && _str[i] == '\0')
				break;
			if (str[i] != _str[i])
				return false;
		}
		return true;
	}
};

// hashing
// using the polynomial method with seed 13131
unsigned int hash(char * ch) {
	unsigned int seed = 13131;
	unsigned int h = 0;
	for (int i = 0; i < 8; ++i)
	{
		if (ch[i] == '\0')
			break;
		h = h * seed + ch[i];
	}
	return h;
}

int mainPA34() {	
#ifndef _OJ_
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int n;
	scanf("%d", &n);

	char str[9];

	int ind = 0;
	int len = 479909;
	DictItem * newItem = NULL;
	DictItem ** allItems = new DictItem*[len+1];
	for (int i = 0; i < len; i++)
	{
		allItems[i] = NULL;
	}
	for (int i = 0; i < n; i++)
	{
		scanf("%s", str);
		ind = hash(str)%len;
		if (NULL == allItems[ind]) {
			allItems[ind] = new DictItem(str);
		} 
		else
		// go through the list to find coincidence 
		{
			DictItem * prevItem = NULL;
			DictItem * currentItem = allItems[ind];
			do{
				if ( currentItem->equal(str) )
				{
					currentItem->count++;
					break;
				}
				prevItem = currentItem;
				currentItem = currentItem->nextItem;
			} while ( NULL != currentItem );
			// if no coinciidence, add the new item at the end
			if ( NULL == currentItem ) {
				prevItem->nextItem = new DictItem(str);
			}
		}
	}

	// find the item with max count	
	char * maxQueried = NULL;
	int maxCount = 0;
	for (int i = 0; i < len; i++)
	{
		if (NULL != allItems[i])
		{
			DictItem * currentItem = allItems[i];
			while (currentItem != NULL) {
				if (currentItem->count > maxCount) {
					maxCount = currentItem->count;
					maxQueried = currentItem->str;
				}
				currentItem = currentItem->nextItem;
			}
		}
	}
	printf("%s %d\n", maxQueried, maxCount);

	return 0;
}



