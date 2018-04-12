#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;
const int MAXN = 3096;

class BigNum
{
	char s[MAXN];
	int num[MAXN];
	int len;

public:
	BigNum()
	{
		memset(num, 0, sizeof(num));
		len = 0;
	}

	BigNum(int number)
	{
		len = sprintf(s, "%d", number);
		for (int i = 0; i < len/2; i++)
			swap(s[i], s[len-1-i]);
		str_to_num();	
	}
	
	void str_to_num()
	{
		memset(num, 0, sizeof(num));
		for (int i = 0; i < len; i++)
			num[i] = s[i] - '0';
	}
	
	BigNum operator += (const BigNum& b)
	{
		int l = max(len, b.len);
		for (int i = 0; i < l; i++)
		{
			num[i] += b.num[i];
			if (num[i] >= 10)
			{
				num[i+1] += (num[i] / 10);
				num[i] %= 10;
			}
		}
		len = l + 3;
		while (!num[len])
			len--;
		len++;

		return *this;
	}

	BigNum operator *= (const BigNum& b)
	{
		int blen = b.len;
		int tmp[MAXN];
		memset(tmp, 0, sizeof(tmp));
		
		for (int i = 0; i < len; i++)
		{
			for (int j = 0; j < blen; j++)
			{
				tmp[i+j] += (num[i]*b.num[j]);
				if (tmp[i+j] >= 10)
				{
					tmp[i+j+1] += (tmp[i+j] / 10);
					tmp[i+j] %= 10;
				}
			}
		}
		
		len = len + blen + 10;
		while (!tmp[len])
			len--;
		len++;

		for (int i = 0; i < len; i++)
			num[i] = tmp[i];

		return *this;
	}

	void printLastDigit()
	{
		for (int i = 9; i >= 0; i--)
			cout << num[i];
		cout << endl;
	}
	
	void print()
	{
		for (int i = len-1; i >= 0; i--)
			cout << num[i];
		cout << endl;
	}
};

int main()
{
	BigNum ans(0);
	for (int i = 1; i <= 1000; i++)
	{
		BigNum tmp(i);
		for (int j = 1; j < i; j++)
		{
			tmp *= BigNum(i);
		}	
		ans += tmp;
	}

	ans.printLastDigit();
	return 0;
}


