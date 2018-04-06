#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;
const int MAXN = 1000000;

int main()
{
	int ans = 0;
	for (int i = 2; i < MAXN; i++)
	{
		int tmp = i, sum = 0;
		while(tmp)
		{
			int remain = tmp % 10;
			sum += pow(remain, 5);
			tmp /= 10;
		}
		if (sum == i)
			ans += i;	
	}

	cout << "ans: " << ans << endl;
	return 0;
}
