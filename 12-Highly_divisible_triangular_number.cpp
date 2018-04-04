#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;
const int MAXN = 150000;

int tags[MAXN];
int primes[MAXN];

int CalFactor(int tri_number);

int main()
{
	memset(primes, 0, sizeof(primes));
	int cnt = 0;

	for (int i = 2; i < MAXN; i++)
	{
		if (!tags[i])
		{
			primes[cnt++] = i;
			for (int j = i+i; j < MAXN; j += i)
			{
				tags[j] = 1;
			}
		}

	} 
	cout << "Over..." << endl;

	int k = 1;
	while(true)
	{
		int tri_number = k*(k+1)/2;
		int res = CalFactor(tri_number);
		if (res > 500)
		{
			printf("%d\n", tri_number);
			break;
		}	
		k++;
	}
	return 0;

}

int CalFactor(int tri_number)
{
	int ans = 1;
	int k = 0, cnt = 0;
	while(tri_number > 1)
	{
		cnt = 0;
		while(tri_number % primes[k] == 0)
		{
			tri_number /= primes[k];
			cnt++;
		}
		k++;
		ans *= (cnt+1);
	}
	return ans;
}
