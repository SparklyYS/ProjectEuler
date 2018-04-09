#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;
const int MAXN = 1000000;

int tags[MAXN];

bool dfs(string s, int flag)
{
	int num = stoi(s);
	if (tags[num])
		return false;
	if (s.length() == 1)
		return true;

	if (flag == 0)
		return dfs(s.substr(1, s.length()), flag);
	else
		return dfs(s.substr(0, s.length()-1), flag);

}

int main()
{
	memset(tags, 0, sizeof(tags));
	tags[0] = 1;
	tags[1] = 1;
	for (int i = 2; i < MAXN; i++)
	{
		if (!tags[i])
		{
			for (int j = i+i; j < MAXN; j += i)
				tags[j] = 1;
		}
	}

	int cnt = 0, ans = 0;
	for (int i = 10; i < MAXN; i++)
	{
		string s = to_string(i);
		if (dfs(s, 0) && dfs(s, 1))
		{
			cnt++;
			ans += i;
		}		
	}
	cout << "cnt: " << cnt << endl;
	cout << "ans: " << ans << endl;
	return 0;
}
