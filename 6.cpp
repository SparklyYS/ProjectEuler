#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int main()
{
	long long sum = 0;
	long long sqsum = 0;
	for (int i = 1; i <= 100; i++)
	{
		sum += i*i;
		sqsum += i;
	}
	sqsum = sqsum*sqsum;
	
	cout << sqsum - sum << endl;
}
