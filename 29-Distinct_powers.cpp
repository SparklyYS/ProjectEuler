#include <set>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;
const int MAXN = 10240;

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

	BigNum operator = (int number)
	{
		memset(s, 0, sizeof(s));
		len = sprintf(s, "%d", number);
		for (int i = 0; i < len/2; i++)
			swap(s[i], s[len-1-i]);
		str_to_num();
		
		return *this;
	}

	bool operator < (const BigNum& b) const
	{
		int l = max(len, b.len);
		for (int i = l-1; i >= 0; i--)
		{
			if (num[i] < b.num[i])
				return true;
			if (num[i] > b.num[i])
				return false;	
		}
		return false;
	}
    
    void print()
    {
        cout << len << endl;
        for (int i = len-1; i >= 0; i--)
            cout << num[i];
        cout << endl;
    }
};

set<BigNum> distinct_set;
	
int main()
{
	for (int i = 2; i <= 100; i++)
	{
		BigNum c = BigNum(i);
		for (int j = 2; j <= 100; j++)
		{
			c *= BigNum(i);
			distinct_set.insert(c);
		}
	}

	cout << "distinct_num: " << distinct_set.size() << endl;
	return 0;
}		
