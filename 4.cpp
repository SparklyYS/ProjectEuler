#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

bool Judge(string s)
{
	int len = s.length();
	for (int i = 0; i < len/2; i++)
	{
		if (s[i] != s[len-1-i])
			return false;
	}
	return true;
}

int main()
{
	int Max = -1;
	for (int i = 100; i <= 999; i++)
	{
		for (int j = 100; j <= 999; j++)
		{
			int product = i*j;
			if (Judge(to_string(product)))
				Max = max(product, Max);
		}
	}

	cout << "Max: " << Max << endl;
	

	return 0;
}
