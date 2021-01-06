#pragma once
#include "common.h"
int findTargetSumWays(vector<int>& nums, int S) {
	int n = nums.size();
	vector<vector<int>>dp(n, vector<int>(2001, 0));
	dp[0][nums[0] + 1000] = 1;
	dp[0][-nums[0] + 1000] += 1;
	for (int i = 1; i < n; i++)
	{
		for (int sum = -1000; sum <= 1000; sum++)
		{
			if (dp[i - 1][sum + 1000] > 0)
			{
				dp[i][sum + nums[i] + 1000] += dp[i - 1][sum + 1000];
			}
		}
	}
}