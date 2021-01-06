#pragma once
#include "common.h"
int minCostClimbingStairs(vector<int>& cost) {
	int n = cost.size();
	vector<int>dp(n, 0);
	dp[0] = cost[0];
	dp[1] = min(cost[0], cost[1]);
	for (int i = 2; i < n; i++)
	{
		dp[i] = min(dp[i-2]+cost[i-2],cost[i-1]+dp[i-1]);
	}
	return dp[n-1];
}