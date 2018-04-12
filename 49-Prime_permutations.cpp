#include <cmath>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

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

bool judgeDigit(int a, int b)
{
	vector<int> v1, v2;
	while (a || b)
	{
		if (a)
		{
			v1.push_back(a % 10);
			a /= 10;
		}
		
		if (b)
		{
			v2.push_back(b % 10);
			b /= 10;
		}
	}
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());

	return v1 == v2;		
}

int main()
{
	vector<int> vec;	
	for (int i = 1000; i < 10000; i++)
	{
		if (isPrime(i))
			vec.push_back(i);
	}	

	for (int i = 0; i < vec.size()-2; i++)
	{
		for (int j = i+1; j < vec.size(); j++)
		{
			if (judgeDigit(vec[i], vec[j]))
			{
				int diff = vec[j] - vec[i];
				int num = vec[j] + diff;		 
				if (isPrime(num))
				{
					if (judgeDigit(vec[j], num))
						cout << vec[i] << vec[j] << num << endl;		
				}

			}	
		}
	}
	return 0;
}
