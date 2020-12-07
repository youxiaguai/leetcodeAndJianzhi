#pragma once
#include "common.h"
int maxProfit(vector<int>& prices, int fee) {
	if (prices.size() < 2)
	{
		return 0;
	}
	int n = prices.size();
	vector<vector<int>>dp(n, vector<int>(2, 0));
	dp[0][0] = 0;
	dp[0][1] = -prices[0] - fee;
	for (int i = 1; i < n; i++)
	{
		dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);//当天不持股，可以由上一天不持股和持股而来，上一天持股今天不持股，则意味着今天秒掉了 要加上今天的价钱
		dp[i][1] = max(dp[i - 1][0] - prices[i] - fee, dp[i - 1][1]);//当天持股，如果上一天持股，则啥也没做，上一天没持股则要买入，
	}
	/*
	dp[1] = -prices[0];
	for (int i = 1; i < n - 1; i++)
	{
		vector<int>temp(dp);
		dp[0] = max(temp[0], temp[1] + prices[i] - fee);
		dp[1] = max(temp[0] - prices[i], temp[1]);
	}
	return max(dp[0], dp[1] + prices[n - 1] - fee);
	*/
	return dp[n - 1][0];
}