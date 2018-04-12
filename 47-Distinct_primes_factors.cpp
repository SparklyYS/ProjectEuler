#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

bool Judge(int num)
{
	int cnt = 0;
	
	if (num % 2 == 0)
	{
		do
		{
			num /= 2;
		}while(num % 2 == 0);
		cnt++;
	}

	int factor = 3;
	int upper = (int)sqrt(num);

	while (num > 1 && factor <= upper)
	{
		if (num % factor == 0)
		{
			do
			{
				num /= factor;
			}while(num % factor == 0);
			cnt++;
			upper = (int)sqrt(num);
		}
		factor += 2;
	}

	if (num != 1)
		cnt++;

	return (cnt == 4);
}

int main()
{
	int tot = 0, ans;
	for (int i = 2; ; i++)
	{
		if (Judge(i))
		{
			tot++;
			if (tot == 1)
				ans = i;
			if (tot == 4)
				break;
		}	
		else
			tot = 0;
	}	
	
	cout << "ans: " << ans << endl;

	return 0;
}
