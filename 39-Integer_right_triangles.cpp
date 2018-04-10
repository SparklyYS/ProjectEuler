#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int main()
{
	int ans = 0, maxcnt = 0;
	for (int k = 12; k <= 1000; k++)
	{
		int cnt = 0;
		for (int c = k/3+1; c < k; c++)
		{
			for (int a = 1; a < k/3; a++)
			{
				int b = k-c-a;
				if (a < b && (a*a+b*b==c*c))
					cnt++;
			}
		}
		if (cnt > maxcnt)
		{
			maxcnt = cnt;
			ans = k;
		}
	}
	cout << "ans: " << ans << endl;
}
