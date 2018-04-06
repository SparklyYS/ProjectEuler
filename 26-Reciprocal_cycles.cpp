#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;
const int MAXN = 1000;

int CalCycles(int n)
{
	int d[MAXN] = {0};
	int ind = 1, ret = 1;
	while (!d[ret] && ret)
	{
		d[ret] = ind++;
		ret *= 10;
		ret %= n;
	}
	return ret ? ind - d[ret] : 0;
}

int main()
{
	int MaxLen = -1;
	int ans = 0;
	for (int i = 2; i < 1000; i++)
	{
		int len = CalCycles(i);
		if (len > MaxLen)
		{
			MaxLen = len;
			ans = i;
		}
	}
	cout << "MaxLen: " << MaxLen << endl;
	cout << "ans: " << ans << endl;

	return 0;
}
