#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;
const int MAXDIGIT = 50;

int main()
{
	freopen("in.dat", "r", stdin);
	int res[500];
	string str;

	memset(res, 0, sizeof(res));	
	while(getline(cin, str))
	{
		for (int i = 0; i < MAXDIGIT; i++)
			res[i] += (str[MAXDIGIT-1-i] - '0');
	}
	
	int len = 0;
	while (res[len])
	{
		if (res[len] >= 10)
		{
			res[len+1] += (res[len] / 10);
			res[len] %= 10;		
		}
		len++;
	}
	
	for (int i = 0; i < 10; i++)
	{
		cout << res[len-1-i];
	}
	cout << endl;
	return 0;
}
