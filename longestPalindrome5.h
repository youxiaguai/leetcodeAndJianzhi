#pragma once
#include "common.h"
string palindrome(string& s, int l, int r)
{
	while (l>=0&&r<s.size()&&s[l]==s[r])
	{
		l++;
		r--;
	}
	return s.substr(l + 1, r - l + 1);
}
string longestPalindrome(string s) {
	/*int n = s.size();
	vector<vector<int>>dp(n, vector<int>(n, 0));
	string ans;
	for (int l = 0; l < n; l++)
	{
		for (int i = 0; i + 1 < n; i++)
		{
			int j = i + 1;
			if (l == 0)
			{
				dp[i][j] = 1;
			}
			else if(l==1)
			{
				dp[i][j] = (s[i] == s[j]);
			}
			else
			{
				dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);
			}
			if (dp[i][j] && l + 1 > ans.size())
			{
				ans = s.substr(i, l + 1);
			}
		}
	}
	return ans;
}*/
	int n = s.size();
	string res;
	for (int i = 0; i < n; i++)
	{
		string s1 = palindrome(s, i, i);
		string s2 = palindrome(s, i, i + 1);
		res = res.size() > s1.size() ? res : s1;
		res = res.size() > s2.size() ? res : s2;

	}
	return res;
}