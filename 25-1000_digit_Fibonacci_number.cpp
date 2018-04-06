#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;
const int MAXN = 1024;
const int DIGIT = 1000;

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
	
	BigNum(int num)
	{
		len = sprintf(s, "%d", num);
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


	BigNum operator = (const BigNum& b)
	{
		memset(num, 0, sizeof(num));
		len = b.len;
		for (int i = 0; i < len; i++)
			num[i] = b.num[i];
		return *this;
	}
	
	void print()
	{
		for (int i = len-1; i >= 0; i--)
			cout << num[i];
		cout << endl;
	}
	
	int getlength()
	{
		return len;
	}
};

int main()
{
	BigNum a(1);
	BigNum b(2);
	BigNum c;

	int cnt = 3;
	while(true)
	{
		a += b;
		cnt++;
		if (a.getlength() == DIGIT)
		{
			break;	
		}
		c = a;
		a = b;
		b = c;
	}
	cout << "res: " << cnt << endl;
	return 0;
}
