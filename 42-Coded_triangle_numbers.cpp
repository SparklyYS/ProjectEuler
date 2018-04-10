#include <map>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;
int main()
{
	freopen("p042_words.txt", "r", stdin);

	vector<string> vec;
	string wordslist, word = "";
	bool beg = false;
	
	cin >> wordslist;
	for (int i = 0, l = wordslist.length(); i < l; i++)
	{
		if (beg == false)
		{
			if (wordslist[i] == '"')
			{
				beg = true;
				word = "";
			}
		}
		else
		{
			if (wordslist[i] == '"')
			{
				beg = false;
				vec.push_back(word);
			}
			else
				word += wordslist[i];
		}
	}

	map<int, int> mp;
	for (int i = 1; i <= 1000; i++)
	{
		int val = i*(i+1) / 2;
		mp[val] = 1;
	}

	int cnt = 0;
	for (int i = 0, l = vec.size(); i < l; i++)
	{
		string stmp = vec[i];
		int score = 0;
		for (int k = 0, len = stmp.length(); k < len; k++)
			score += (stmp[k] - 'A' + 1);
		if (mp[score] == 1)
			cnt++;
	}
	
	cout << "cnt: " << cnt << endl;
	return 0;
}
