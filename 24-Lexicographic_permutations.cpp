#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
const int MAXN = 1000000;

int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
int d[10];
int cnt = 0;
// next_permutation solution
void solve()
{
	do
	{
		if ((++cnt) == MAXN)
		{
			cout << "res: ";
			for (int i = 0; i < 10; i++)
				cout << a[i];
			cout << endl;
			break;
		}	

	}while(next_permutation(a, a+10));
}

// dfs solution
void dfs(string str, int level)
{
	for (int i = 0; i < 10; i++)
	{
		if (!d[i])
		{
			d[i] = 1;
			string digit = to_string(i);
			dfs(str+digit, level+1);
			d[i] = 0;
		}
	}	
	if (level == 10)
	{
		if ((++cnt) == MAXN)
			cout << "res: " << str << endl; 
	}
	return;
}


int main()
{
	dfs("", 0);
	return 0;
}
