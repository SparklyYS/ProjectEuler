#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int gcd(int a, int b)
{
	if (a < b)
		swap(a, b);

	int r = 0;
	while (b)
	{
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main()
{ 
	int a = 1, b = 1;
	for (int i = 1; i <= 9; i++)
	{
		for (int j = 1; j <= 9; j++)
		{
			for (int k = 1; k <= 9; k++)
			{
				int u = i*10 + j;
				int v = j*10 + k;
				if (i == j || i > k)
					continue;
				if (u*k == i*v)
				{
					a *= i; 
					b *= k;
				}
			}
		}
	}
	int ans = b / gcd(a, b);
	cout << "ans: " << ans << endl;
	return 0;
}
