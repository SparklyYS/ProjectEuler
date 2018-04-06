#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
const int MAXN = 1000000;

int main()
{
	int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	
	int cnt = 1;
	while (next_permutation(a, a+10))
	{
		cnt++;
		if (cnt == MAXN)
		{
			for (int i = 0; i < 10; i++)
				cout << a[i];
			cout << endl;
			break;
		}
	}
	return 0;
}
