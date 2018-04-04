#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
int a[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool JudgeLeapYear(int year)
{
	return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

int main()
{
	int remain = 1;
	int ans = 0;
	for (int i = 1901; i <= 2000; i++)
	{
		if (JudgeLeapYear(i))
			a[1] = 29;
		else
			a[1] = 28;

		for (int j = 0; j < 12; j++)
		{
			remain = (remain + a[j]) % 7;
			if (remain == 6)
				ans++;
		}
	}	

	cout << "ans: " << ans << endl;
	return 0;
}
