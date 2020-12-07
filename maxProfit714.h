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
		dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);//���첻�ֹɣ���������һ�첻�ֹɺͳֹɶ�������һ��ֹɽ��첻�ֹɣ�����ζ�Ž�������� Ҫ���Ͻ���ļ�Ǯ
		dp[i][1] = max(dp[i - 1][0] - prices[i] - fee, dp[i - 1][1]);//����ֹɣ������һ��ֹɣ���ɶҲû������һ��û�ֹ���Ҫ���룬
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