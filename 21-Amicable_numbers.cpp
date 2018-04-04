#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;
void JudgeAmicable(int num);

const int MAXN = 10240;
const int LIMIT = 10000;

int d[MAXN];
int main()
{
	memset(d, 0, sizeof(d));

	int sum = 0;
	for (int i = 2; i < LIMIT; i++)
	{
		if (!d[i])
		{
			JudgeAmicable(i);	
		}	
	}

	for (int i = 2; i < LIMIT; i++)
	{
		if (d[i])
			sum += i;
	}

	cout << "sum: " << sum << endl;
	return 0;
}

void JudgeAmicable(int num)
{
	int rev = 1;
	for (int i = 2; i < num; i++)
	{
		if (num % i == 0)
		{
			rev += i;
		}
	}

	int rev_num = 1;
	for (int i = 2; i < rev; i++)
	{
		if (rev % i == 0)
		{
			rev_num += i;
		}
	}

	if (num != rev && rev_num == num)
	{
		d[num] = d[rev_num] = 1;
	}
}
