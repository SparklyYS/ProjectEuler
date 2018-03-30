#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int n = 8;
int main()
{
	int primes[] = {2, 3, 5, 7, 11, 13, 17, 19};
	int cnt[n];
	
	memset(cnt, 0, sizeof(cnt));

	for (int i = 2; i <= 20; i++)
	{
		int tmp = i;
		for (int j = 0; j < n; j++)
		{
			int tick = 0;
			while(tmp % primes[j] == 0)
			{
				tick++;
				tmp /= primes[j];
			}
			cnt[j] = max(tick, cnt[j]);
		}
	}
	
	long long ans = 1;
	for (int i = 0; i < n; i++)
	{
		ans *= ((long long)(pow(primes[i], cnt[i])));
	}
	cout << ans << endl;
	
	return 0;
}
