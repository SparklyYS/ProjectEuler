#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;
const int N = 10;
int d[N];

int findDigit(int idx)
{
	int level;
	for (int i = 0; i < N; i++)
	{
		if (d[i] > idx)
		{
			level = i;
			break;
		}
	}

	int start = 1;
	for (int i = 0; i < level-1; i++)
		start *= 10;

	int interval = (idx-d[level-1]-1) / level;
	int num = start + interval;
	int curr = d[level-1]+1+interval*level;
	string str = to_string(num);

	int ans;
	for (int i = 0; i < str.length(); i++, curr++)
	{
		if (curr == idx)
		{
			ans = str[i] - '0';
			break;
		}
	}
	return ans;
}

int main()
{
	memset(d, 0, sizeof(d));

	int lane = 9;
	for (int i = 1; i < 10; i++)
	{
		d[i] = d[i-1] + lane*i;
		lane *= 10;
	}	

	int a[] = {1, 10, 100, 1000, 10000, 100000, 1000000};
	int res = 1;

	for (int i = 0; i < 7; i++)
	{
		res *= findDigit(a[i]);
	}
	cout << "res: " << res << endl;

	return 0;

}
