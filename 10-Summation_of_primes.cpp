#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;
const int maxn = 2048000;
const int LIMIT = 2000000;

int tags[maxn];
int main()
{
	long long ans = 0;
	memset(tags, 0, sizeof(tags));
	
	for (int i = 2; i < maxn; i++)
	{
		if (!tags[i])
		{
			for (int j = i+i; j < maxn; j += i)
			{
				tags[j] = 1;	
			}
			if (i < LIMIT)
				ans += i;
		}
	}

	cout << "ans: " << ans << endl;
	
	return 0;
}
