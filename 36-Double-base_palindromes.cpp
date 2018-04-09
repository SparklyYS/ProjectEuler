#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;
const int MAXN = 1000000;

bool JudgePalindrome(string s)
{
	int len = s.length();
	for (int i = 0; i < len/2; i++)
	{
		if (s[i] != s[len-1-i])
			return false;	
	}
	return true;
}

string dec2bin(int num)
{
	string res = "";
	int r = 0;
	while (num)
	{
		r = num % 2;
		res += to_string(r);
		num /= 2;
	}
	return res;
}


int main()
{
	int ans = 0;
	for (int i = 1; i < MAXN; i++)
	{
		string dec = to_string(i);
		if (!JudgePalindrome(dec))
			continue;
		string bin = dec2bin(i);
		if (!JudgePalindrome(bin))
			continue;
		ans += i; 
	}	
	cout << "ans: " << ans << endl;
	return 0;
}
