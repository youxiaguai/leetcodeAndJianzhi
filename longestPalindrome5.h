#pragma once
#include "common.h"
string longestPalindrome(string s) {
	int n = s.size();
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
}