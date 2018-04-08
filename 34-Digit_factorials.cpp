#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;
const int LIMIT = 1000000;

int d[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
int main()
{
	int ans = 0;
	for (int i = 3; i <= LIMIT; i++)
	{
		int tmp = i;
		int tot = 0;
		while (tmp)
		{
			tot += d[tmp%10];
			tmp /= 10;
		}
		if (tot == i)
			ans += tot;
	}
	
	cout << "ans: " << ans << endl;
	return 0;
}
