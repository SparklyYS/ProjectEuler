#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>

using namespace std;
typedef long long LL;

LL MaxPrimeFactor(LL number)
{
	LL MaxFactor = 1;
	
	while(number % 2 == 0)
	{
		number /= 2;
		MaxFactor = 2;
	}

	LL Factor = 3;
	while(number > 1)
	{
		while(number % Factor == 0)
		{
			number /= Factor;
			MaxFactor = Factor;
		}
		Factor += 2;
	}
	return MaxFactor;
}


int main()
{
	cout << MaxPrimeFactor(600851475143) << endl;
	
	return 0;	
}
