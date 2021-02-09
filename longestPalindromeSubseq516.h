#pragma once
#include "common.h"
int longestPalindromeSubseq(string s) {
	//二维动态规划
	int n = s.size();
	vector<vector<int>>dp(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++)
	{
		dp[i][i] = 1;
		for (int j = n-2; j >= 0; j--)
		{
			if (s[i] == s[j])
			{
				dp[i][j] = dp[i + 1][j - 1]+2;
			}
			else
			{
				dp[i][j] = max(dp[i + 1][j],dp[i][j + 1]);
			}
		}
		return dp[0][n - 1];
	}
	//一维动态规划
	int m = s.size();
	vector<int>dp2(n, 1);
	for (int i = n - 2; n >= 0; n--)
	{
		int pre = 0;
		for (int j = i + 1; j < n; j++)
		{
			int temp = dp2[j];
			if (s[i] == s[j])
			{
				dp2[i] = pre + 2;

			}
			else
			{
				dp2[j] = max(dp2[j], dp2[j - 1]);
			}
			pre = temp;
		}
	}
	return dp2[n - 1];
}