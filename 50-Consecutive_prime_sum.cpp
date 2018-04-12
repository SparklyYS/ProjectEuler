#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;
const int MAXN = 1000024;
const int LIMIT = 1000000;

int tags[MAXN];
int primes[MAXN];
int main()
{
	int cnt = 0;
	for (int i = 2; i < MAXN; i++)
	{
		if (!tags[i])
		{
			for (int j = i+i; j < MAXN; j += i)
				tags[j] = 1;
			primes[cnt++] = i;	
		}
	}

	int sum = 0, tot = 0;
	int res, ans = -1;
	for (int i = 2; i < cnt; i++)
	{
		sum = 0;
		tot = 0;

		for (int j = i; j < cnt; j++)
		{
			sum += primes[j];
			tot++;

			if (sum > LIMIT)
				break;
			if (!tags[sum] && tot > ans)
			{
				ans = tot;
				res = sum;
			}
		}
	}
	cout << "ans: " << ans << endl;
	cout << "res: " << res << endl;	

	return 0;
}
