#include <set>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
const int MAXN = 10000;

void split_digit(int num, vector<int>& v)
{
	string nstr = to_string(num);
	for (int i = 0; i < nstr.length(); i++)
	{
		int digit = nstr[i] - '0';
		v.push_back(digit);
	}
}

int main()
{
	vector<int> v;

	int MaxNum = 0;
	for (int i = 1; i < MAXN; i++)
	{
		v.clear();
		int n = 1;

		while (n <= 9)
		{
			int num = n*i;
			split_digit(num, v);

			if (v.size() == 9)
			{
				set<int> s(v.begin(), v.end());
				if (s.size() == 9)
				{
					if (s.find(0) != s.end())
						continue;
					
					int res = 0;
					for (auto d : v)
						res = res*10 + d;
					MaxNum = max(MaxNum, res);
				}
			}
			
			if (v.size() > 9)
				break;
			n++;
		}
	}
	cout << "Max: " << MaxNum << endl;
	return 0;
}
