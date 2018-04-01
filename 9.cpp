#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int main()
{
	bool found = false;
	int ans = 1;

	for (int i = 1; i < 500; i++)
	{	
		for (int j = 1; j < 500; j++)
		{
			int k = 1000 - i - j;
			if ((i*i + j*j) == (k*k))
			{
				ans = i*j*k;
				found = true;
				break;
			}
		}
		if (found)
			break;
	}
	
	cout << "ans: " << ans << endl;
	return 0;
}
