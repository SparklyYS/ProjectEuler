#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;
const int MAXN = 1000000;
const int START = 999999;

int main()
{
	int d[MAXN];
	memset(d, 0, sizeof(d));
	
	int res;
	int Max = -1;
	for (int i = START; i >= 1; i--)
	{
		int cnt = 0;
		long long tmp = i;
		if (d[i] ==  0)
		{
			while(tmp > 1)
			{
				if (tmp % 2 == 0)
				{
					tmp /= 2;
					if (tmp < MAXN) d[tmp] = -1;
				}
				else
				{
					tmp = 3*tmp+1;
					if (tmp < MAXN) d[tmp] = -1;
				}
				cnt++;
			}
			if (cnt > Max)
			{
				Max = cnt;
				res = i;
			}
		}
	}

	cout << "res: " << res << "  " << "Max: " << Max << endl;
	return 0;
}
