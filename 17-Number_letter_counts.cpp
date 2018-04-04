#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;
int parseDigit(int num);

/*
one two three four five six seven eight nine ten
eleven twelve thirteen fourteen fifteen sixteen seventeen eighteen nineteen
twenty thirty forty fifty sixty seventy eighty ninety
hundred 
thousand
and
*/
int a[] = {0, 3, 3, 5, 4, 4, 3, 5, 5, 4, 3, 6, 6, 8, 8, 7, 7, 9, 8, 8};
int b[] = {0, 0, 6, 6, 5, 5, 5, 7, 6, 6};
int hdigit = 7;
int tdigit = 8;
int key = 3;

int main()
{
	int digitsum = 0;
	for (int i = 1; i <= 1000; i++)
	{
		digitsum += parseDigit(i);
	}
	
	cout << "sum: " << digitsum << endl;
	return 0;
}

int parseDigit(int num)
{
	int ans = 0;

	int digit = num / 1000; // 1000
	if (digit)
	{
		ans += a[digit];
		ans += tdigit;
	}
	
	bool flag = false; // mark the hundred
	num %= 1000;
	digit = num / 100; // 999
	if (digit)
	{
		ans += a[digit];
		ans += hdigit; 
		flag = true;
	}

	num %= 100; // 99 1
	if (num >= 20)
	{
		ans += b[num / 10];
		ans += a[num % 10];	
		if (flag)
			ans += key;
	}	
	else
	{
		if (num > 0)
		{
			ans += a[num];
			if (flag)
				ans += key;
		}
	}
	
	return ans;
}
