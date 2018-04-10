#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int d[] = {2, 3, 5, 7, 11, 13, 17};
	string str = "0123456789";

	long sum = 0;
	do
	{
		bool flag = true;
		for (int i = 0, cur = 1; i < 7; i++, cur++)
		{
			string ss = str.substr(cur, 3);
			int num = stoi(ss);
			if (num % d[i] != 0)
			{
				flag = false;
				break;
			}	
		}
		if (flag)
			sum += stol(str); 

	}while(next_permutation(str.begin(), str.end()));

	cout << "sum: " << sum << endl;
	return 0;
}
