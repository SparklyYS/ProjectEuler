#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;
const long long MAXN = (1 << 25);
const int LIMIT = 1000;


int tags[MAXN];
int p[MAXN];

int main()
{
	long long cnt = 0;
	for (long long i = 2; i < MAXN; i++)
	{
		if (!tags[i])
		{
			for (long long j = i+i; j < MAXN; j+=i)
				tags[j] = 1;
			if (i <= LIMIT)
				p[cnt++] = i;
		}
	}

	int MaxLen = -1;
	int ra, rb;
	for (long long a = -999; a < 1000; a++)
	{
		for (long long b = 0; b < cnt; b++)
		{
			int n = 1, len = 1;
			while(true)
			{
				long long tmp = n*n + a*n + p[b];
				if (tmp < 0 || tags[tmp])
					break;
				n++;
				len++;
			}
			if (MaxLen < len)
			{
				MaxLen = len;
				ra = a;
				rb = p[b];
			}
		}
	}
	
	cout << "res: " << ra*rb << endl;

	return 0;
}
