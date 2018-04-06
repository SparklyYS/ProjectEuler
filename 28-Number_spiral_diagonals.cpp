#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int main()
{
	long long sum = 1;
	int start = 1;
	for (int i = 1; i <= 500; i++)
	{
		int interval = i*2;
		for (int k = 0; k < 4; k++)
		{
			start += interval;
			sum += start;
		}	
	}
	cout << "sum: " << sum << endl;
	return 0;
}
