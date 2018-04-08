#include <set>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;
const int MAXN = 1000000;

int tags[MAXN];
int d[MAXN];
int main()
{
	for (int i = 2; i < MAXN; i++)
	{
		if (!tags[i])
		{
			for (int j = i+i; j < MAXN; j += i)
				tags[j] = 1;
		}
	}

	int ans = 0;
	set<int> v;
	for (int i = 2; i < MAXN; i++)
	{
		if (!tags[i] && !d[i])
		{		
			v.clear();
			string num = to_string(i);
			int len = num.length();
			bool flag = true;
			while (len--)
			{
				num = num.substr(1, num.length()) + num[0];
				int dnum = stoi(num);
				if (tags[dnum])
				{
					flag = false;
					break;
				}	
				v.insert(dnum);
			}
			if (flag)
			{
				for (auto dnum : v)
				{
					ans++;
					d[dnum] = 1;	
				}
			}	
		}
	}
	
	cout << "ans: " << ans << endl;
	return 0;	
}
