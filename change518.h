#pragma once
#include "common.h"
int change(int amount, vector<int>& coins) {
	int n = coins.size();
	vector<vector<int>>dp(n+1, vector<int>(amount+1, 0));
	for (int i = 0; i <= amount; i++)
	{
		dp[0][i] = 0;
	}
	for (int j = 0; j <= n; j++)
	{
		dp[j][0] = 1;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= amount; j++)
		{
			if (j - coins[i - 1] > 0)
			{
				dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i - 1]];
			}
			else
			{
				dp[i][j] = dp[i - 1][j];
			}
			
		}
	}
	return dp[n][amount];
	//一维数组解法
	vector<int>dpp(amount, 0);
	dpp[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= amount; j++)
		{
			if (j - coins[i - 1] >=0)
			{
				dpp[j] = dpp[j-1] + dpp[j - coins[i - 1]];
				
			}
			else
			{
				dpp[j] = dpp[j - 1];
			}
			
		}
		
	}
	return dpp[amount];
}