#include <map>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
const int N = 10000 + 10;

int main()
{
	int d[N];

	int ans = -1;
	for (int i = 1; i < N; i++)
	{
		d[i] = i*(3*i-1) / 2;
		for (int j = 1; j < i; j++)
		{
			if (binary_search(d+1, d+1+i, d[i]-d[j]) && binary_search(d+1, d+1+i, d[i]-2*d[j]))
			{
				ans = d[i] - 2*d[j];
				break;
			}
		}
		if (ans != -1)
			break;
	}

	cout << "ans: " << ans << endl;
	return 0;
}

