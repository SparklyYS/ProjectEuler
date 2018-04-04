#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int d[15][15];
	freopen("in.dat", "r", stdin);
	
	for (int i = 0; i < 15; i++)
		for (int j = 0; j < i+1; j++)
			cin >> d[i][j];
	
	for (int i = 13; i >= 0; i--)
		for (int j = 0; j < i+1; j++)
			d[i][j] += max(d[i+1][j], d[i+1][j+1]);

	cout << d[0][0] << endl;
	return 0;
}
