#include <cmath>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

bool JudgePrime(int num)
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



int main()
{
	int ans = -1;
	int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	
	for (int i = 2; i < 10; i++)
	{
		do
		{
			int num = 0;
			for (int k = 0; k < i; k++)
				num = num*10 + a[k];
			
			if (JudgePrime(num))
				ans = max(ans, num);

		}while(next_permutation(a, a+i));
	}

	cout << "ans: " << ans << endl;
	
	return 0;
}

