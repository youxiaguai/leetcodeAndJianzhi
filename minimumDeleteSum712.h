#pragma once
#include "common.h"
int minimumDeleteSum(string s1, string s2) {
	
	int s1length = s1.length();
	int s2length = s2.length();
	vector<vector<int>>dp(s1length+1,vector<int>(s2length+1,0));
	for (int i = 1; i <= s1length; i++)
	{
		dp[i][0] = dp[i - 1][0] + (int)(s1[i - 1]);
	}
	for (int j = 1; j <= s2length; j++)
	{
		dp[0][j] = dp[0][j - 1] + (int)(s2[j - 1]);
	}
	for (int i = 1; i <= s1length; i++)
	{
		for (int j = 1; j <= s2length; j++)
		{
			dp[i][j] = min(dp[i - 1][j] + s1[i - 1], dp[i][j - 1] + s2[j - 1]);
			int re = (s1[i - 1] == s2[j - 1]) ? 0 : int(s1[i - 1] + s2[j - 1]);
			if (s1[i - 1] == s2[j - 1])
			{
				dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + re);
			}
		}
	}
	return dp[s1length][s2length];
}