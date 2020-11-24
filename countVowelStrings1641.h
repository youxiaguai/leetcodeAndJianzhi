#pragma once
#include "common.h"
int countVowelStrings(int n) {
	vector<vector<int>>dp(n+1, vector<int>(5, 0));
	for (int i = 0; i < 5; i++)
	{
		dp[1][i] = 1;
		
	}
	for (int i = 2; i < n+1; i++)
	{
		dp[i][4] = dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][3] + dp[i - 1][4];
		dp[i][3] = dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][3];
		dp[i][2] = dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2];
		dp[i][1] = dp[i - 1][0] + dp[i - 1][1];
		//长度i的以a结尾的字符串只能由长度i-1的以a结尾的字符串结尾加个a得到
		dp[i][0] = dp[i - 1][0];

	}
	return dp[n][0] + dp[n][1] + dp[n][2] + dp[n][3] + dp[n][4];
}