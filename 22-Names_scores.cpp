#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

vector<string> v;
int main()
{
	freopen("in.dat", "r", stdin);

	string namelist, name = "";
	cin >> namelist;

	bool beg = false;
	for (int i = 0, len = namelist.length(); i < len; i++)
	{
		if (beg == false)
		{
			if (namelist[i] == '"')
			{
				beg = true;
				name = "";
			}
		}
		else
		{
			if (namelist[i] == '"')
			{
				beg = false;
				v.push_back(name);
			}
			else
				name += namelist[i];
		}
	}
	
	sort(v.begin(), v.end());
	long long tot_scores = 0;
	for (int i = 0; i < v.size(); i++)
	{
		int tmp_score = 0;
		for (int j = 0, l = v[i].length(); j < l; j++)
		{
			tmp_score += (v[i][j] - 'A' + 1);	
		}
		tot_scores += (tmp_score * (i+1));
	}
	
	cout << "scores: " << tot_scores << endl;
	return 0;
}
