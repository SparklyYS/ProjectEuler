#include <map>
#include <cstdio>
#include <cstring>
#include <climits>
#include <iostream>

using namespace std;

int main()
{
	unsigned long long i = 1, pen = 1;
	unsigned long long j = 1, hex = 1;

	int cnt = 0;
	while (pen < LLONG_MAX)
	{
		while (hex < pen)
		{
			hex += (4*j + 1);
			j++;
		}

		if (hex == pen)
		{
			cnt++;
			cout << i << " " << j << ": " << hex << endl;
			if (cnt == 3)
				break;
		}

		pen += (3*i + 1);
		i++;
	}
	
	return 0;
}
