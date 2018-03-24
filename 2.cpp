#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

void CalFibonacci(int &a, int &b)
{
	int c = a + b;
	a = b;
	b = c;
}

int main()
{
	int sum = 2;
	int a = 1, b = 2;
	while(true)
	{
		CalFibonacci(a, b);
		if (b > 4000000)
			break;
		if (b % 2 == 0) 
		{
			sum += b;
		}
	}
	printf("%d\n", sum);

	return 0;
}
