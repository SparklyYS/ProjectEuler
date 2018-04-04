#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int maxn = 1024000;

int tags[maxn]; 
int main()
{
	int cnt = 0;
	int ans = 0;
	memset(tags, 0, sizeof(tags));

	for (int i = 2; i < maxn; i++)
	{
		if (!tags[i])
		{
			for (int j = i+i; j < maxn; j += i)
			{
				tags[j] = 1;
			}
			cnt++;
		}
		if (cnt == 10001)
		{
			ans = i;
			break;
		}
	}
	cout << ans << endl;
	
	return 0;
}
