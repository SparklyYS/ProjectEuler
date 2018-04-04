#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int main()
{
	long long ans = 1;
	int d[21];
	memset(d, 0, sizeof(d));	

	for (int i = 40; i >= 21; i--)
	{
		int tmp = i;
		for (int j = 20; j >= 1; j--)
		{
			if (!d[j] && (tmp % j == 0))
			{
				d[j] = 1;
				tmp /= j;
				break;
			}
		}
		ans *= tmp;
	}
	
	long long divider = 1;
	for (int i = 1; i <= 20; i++)
	{
		if (!d[i]) 
			divider *= i;
	}
	
	cout << ans / divider << endl;
	return 0;
}
