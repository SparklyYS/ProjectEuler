#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>

#define INF (1<<31)
using namespace std;
const int maxn = 1024;

int d[maxn];
int main()
{
	freopen("in.dat", "r", stdin);
	
	for (int i = 0; i < 1000; i++)
		scanf("%1d", &d[i]);

	long long Max = -INF;
	for (int i = 0; i < 988; i++)
	{
		long long tmp = 1;
		for (int j = 0; j < 13; j++)
		{
			tmp *= d[i+j];
		}
		Max = max(Max, tmp);
	}
	
	cout << "Max: " << Max << endl;
	return 0;
}

