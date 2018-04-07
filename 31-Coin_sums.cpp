#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int dfs(int f, vector<int> a)
{
	if (f == 0 || a.size() == 1)
		return 1;

	int largest = a[a.size()-1];
	int uses = f / largest;
	a.pop_back();
	int cnt = 0;
	for (int i = 0; i <= uses; i++)
	{
		cnt += dfs(f-i*largest, a);	
	}
	return cnt;
}


int main()
{
	int d[] = {1, 2, 5, 10, 20, 50, 100, 200};
	vector<int> a(d, d+8);
	int f = 200;
	cout << "ans: " << dfs(f, a) << endl;	
	
	return 0;
}
