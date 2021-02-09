#pragma once
#include "common.h"
int minInsertions(string s) {
	//¶þÎ¬dp
	int n = s.size();
	vector<vector<int>>dp(n, vector<int>(n, 0));
	for (int i = n - 2; i >= 0; i--)
	{
		dp[i][i] = 0;
	}
	for (int i = n - 2; i >= 0; i--)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (s[i] == s[j])
			{
				dp[i][j] = dp[i + 1][j - 1];
			}
			else
			{
				dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]);
			}

		}
	}
	return dp[0][n - 1];
	//Ò»Î¬dp
	vector<int>dp(n, 0);
	int temp = 0;
	for (int i = n - 2; i >= 0; i--)
	{
		int pre = 0;
		for (int j = i + 1; j < n; j++)
		{
			if (s[i] == s[j])
			{
				
			}
		}
	}

}