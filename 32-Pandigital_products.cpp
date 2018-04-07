#include <set>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

bool Judge(string str)
{
	int d[10] = {0};
	int len = str.length();
	if (len != 9)
		return false;
	for (int i = 0; i < len; i++)
	{
		int digit = str[i] - '0';
		if (digit == 0 || d[digit])
			return false;
		d[digit] = 1;
	}
	return true;
}

int main()
{
	int sum = 0;
	set<int> s;
	for (int i = 1; i < 100; i++)
	{
		for (int j = 100; j < 9999; j++)
		{
			int tmp = i*j;
			string ri = to_string(i);
			string rj = to_string(j);
			string rtmp = to_string(tmp);

			if (Judge(ri+rj+rtmp))
				s.insert(tmp);
		}
	}

	for (auto num : s)
		sum += num;
	cout << "sum: " << sum << endl;
	return 0;
}
