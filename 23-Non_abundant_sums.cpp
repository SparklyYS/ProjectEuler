#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;
bool Judge(int num);
const int MAXN = 28123+1;

int d[MAXN];
int p[MAXN];

int main()
{
	int ans = 0, cnt = 0;
	
	for (int i = 12; i < MAXN; i++)
	{
		if (Judge(i))
			p[cnt++] = i;			
	}

	for (int i = 0; i < cnt; i++)
	{
		for (int j = i; j < cnt; j++)
		{
			int tmp = p[i] + p[j];
			if (tmp < MAXN)
				d[tmp] = 1;
		}
	}

	for (int i = 1; i < MAXN; i++)
	{
		if (!d[i])
			ans += i;
	}
	cout << "ans: " << ans << endl;
	return 0;	
}

bool Judge(int num)
{
	int tot = 0;
 	for (int i = 1; i <= num/2; i++)
	{
		if (num % i == 0)
			tot += i;
	}
	
	return (num < tot);
}

