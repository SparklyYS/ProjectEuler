#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;
const int MAXN = 1000000;

bool isPrime(int num)
{
	if (num % 2 == 0)
		return false;

	for (int i = 3; i < (int)sqrt(num)+1; i += 2)
	{
		if (num % i == 0)
			return false;
	}
	return true;
}

bool Judge(int num)
{
	int i = 1;
	int t;
	while((t = (num-2*i*i)) > 0)
	{
		if (isPrime(t))
			return true;
		i++;
	}
	return false;
}


int main()
{
	for (int i = 13; i < MAXN; i += 2)
	{
		if (!isPrime(i) && !Judge(i))
		{
			cout << "ans: " << i << endl;
			break;
		}
	}
	return 0;
}
