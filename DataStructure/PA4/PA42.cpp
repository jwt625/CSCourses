#include <stdio.h>
using namespace std;


// structure describing an dictionary item
struct DictItem {
	char * str;
	unsigned short int len;
	unsigned int hashVal;

	// initialization
	// only the minimal expression for
	// the cyclic string is considered and saved,
	// along with the hashVal for fast comparison
	DictItem(char * _str, int _len, int disp = 0) {
		len = _len;
		str = new char[len];
		for (int i = 0; i < len; i++) {
			str[i] = _str[(i+disp)%len];
		}
		hashVal = hash(str);
	}
	// string compare
	bool equal(char * _str) {
		for (int i = 0; i < len; i++) {
			if (str[i] != _str[i])
				return false;
		}
		return true;
	}
	// hashing
	// using the polynomial method with seed 13131
	unsigned int hash(char * ch) {
		unsigned int seed = 13131;
		unsigned int h = 0;
		for (int i = 0; i < len; ++i) {
			h = h * seed + ch[i];
		}
		return h;
	}
	// operator for equality
	// use hash value first and then directly compare the string
	bool operator==(DictItem item) {
		if (item.hashVal != hashVal) {
			return false;
		}
		return equal(item.str);
	}
};



// function for finding the index
// of the minimal expression for the
// cyclic string
int minExpInd(const char* str, int len)
{
    if (len <= 1)
        return 0;

    int indLo = 0, indHi = 1;
    while (indLo < len && indHi < len) {
        if (str[indLo] < str[indHi]) {
            indHi++;
        }else if (str[indLo] > str[indHi]) {
            indLo = indHi;
            indHi++;
        }else {
            int i, lo = indLo, hi = indHi;
            for (i = 0; i < len; i++) {
                if (str[lo%len] < str[hi%len]) {
                    indHi = hi;
                    break;
                } else if (str[lo%len] > str[hi%len]) {
                    indLo = indHi;
                    indHi = hi%len;
                    break;
                }
                lo++; hi++;
            }
            if (i == len)
                break;
        }
    }
    return indLo;
}


int main() {	
#ifndef _OJ_
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

	int m, n;
	scanf("%d %d\n", &m, &n);
	char* str = new char[n];
	DictItem** dict = new DictItem*[m];
	for (int i = 0; i < m; ++i)
		dict[i] = NULL;

	for (int i = 0; i < m; ++i) {
		scanf("%s\n", str);
		dict[i] = new DictItem(str, n, minExpInd(str, n));
		bool found = false;
		for (int j = 0; j < i; ++j) {
			// compare with existing items
			if (*dict[i] == *dict[j]) {
				printf("%d\n", j);
				found = true;
				break;
			}
		}
		if (!found)
			printf("%d\n", i);
	}

	return 0;
}
