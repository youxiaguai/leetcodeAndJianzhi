#pragma once
#include "common.h"
int longestCommonSubsequence(string text1, string text2) {
	int m = text1.size();
	int n = text2.size();
	vector<vector<int>>dp(m+1, vector<int>(n+1, 0));
	for (int i = 0; i <=m; i++)
	{
		dp[i][0] = 0;
		
	}
	for (int i = 0; i <=n; i++)
	{
		dp[0][i] = 0;
	}

	for (int i = 1; i < m; i++)
	{
		for (int j = 1; j < n; j++)
		{
			if (text1[i] == text2[j])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else
			{
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
			
		}
	}
	return dp[m][n];
	
}