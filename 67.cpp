#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
const int MAXN = 100;

int main()
{
	int d[MAXN][MAXN];
	freopen("p067_triangle.txt", "r", stdin);

	for (int i = 0; i < MAXN; i++)
		for (int j = 0; j < i+1; j++)
			cin >> d[i][j];

	for (int i = MAXN-2; i >= 0; i--)
		for (int j = 0; j < i+1; j++)
			d[i][j] += max(d[i+1][j], d[i+1][j+1]);

	cout << d[0][0] << endl;
	return 0;
}

