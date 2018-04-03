#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;
const int MAXN = 1024;

class BigNum
{
	char s[MAXN];
	int num[MAXN];
	int len;

public:
	BigNum() 
	{
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
		for (int i = 0; i < len; i++)
			num[i] = s[i] - '0';
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

	void print()
	{
		cout << len << endl;
		for (int i = len-1; i >= 0; i--)
			cout << num[i];
		cout << endl;
	}

	void digitsum()
	{
		int ans = 0;
		for (int i = 0; i < len; i++)
			ans += num[i];	
		cout << ans << endl;
	}
	
};

int main()
{
	BigNum ans(1024);
	BigNum a(1024);
	for (int i = 1; i < 100; i++)
		ans *= a;
		
	ans.digitsum();
	return 0;
}
