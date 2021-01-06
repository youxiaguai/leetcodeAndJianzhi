#pragma once
#include "common.h"
int numSquares(int n) {
	vector<int>dp;
	for (int i = 0; i <=n; i++)
	{
		dp[i] = i;
		for (int j = 1; i - j * j >= 0; j++)
		{
			dp[i] = min(dp[i], dp[i - j * j] + 1);
		}
	}
	return dp[n];
}