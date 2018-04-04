#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
const int MAXN = 25;

int rightProduct(int i, int j);
int downProduct(int i, int j);
int rightdProduct(int i, int j);
int leftdProduct(int i, int j);

int d[MAXN][MAXN];

int main()
{
	freopen("in.dat", "r", stdin);
	
	for (int i = 3; i < 23; i++)
	{
		for (int j = 3; j < 23; j++)
		{
			cin >> d[i][j];
		}
	}

	int Max = -1;
	for (int i = 3; i < 23; i++)
	{
		for (int j = 3; j < 23; j++)
		{
			Max = max(Max, rightProduct(i, j));
			Max = max(Max, downProduct(i, j)); 
			Max = max(Max, rightdProduct(i, j));
			Max = max(Max, leftdProduct(i, j));
		}
	}
	
	cout << "Max: " << Max << endl;
	return 0;
}

int rightProduct(int i, int j)
{
	int res = 1;
	for (int k = 0; k < 4; k++)
		res *= d[i][j+k];
	return res;
}	

int downProduct(int i, int j)
{
	int res = 1;
	for (int k = 0; k < 4; k++)
		res *= d[i+k][j];
	return res;
}

int rightdProduct(int i, int j)
{
	int res = 1;
	for (int k = 0; k < 4; k++)
		res *= d[i+k][j+k];
	return res;
}

int leftdProduct(int i, int j)
{
	int res = 1;
	for (int k = 0; k < 4; k++)
		res *= d[i+k][j-k];
	return res;
}


