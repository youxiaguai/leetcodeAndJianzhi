#pragma once
#include "common.h"
int maxProfit(vector<int>& prices) {
	int n = prices.size();
	vector<int>buy(n, 0);
	vector<int>sell(n, 0);
	buy[0] = -prices[0];
	sell[0] = 0;
	for (int i = 1; i < n; i++)
	{
		buy[i] = min(sell[i - 1] - prices[i], buy[i - 1]);
		sell[i] = max(buy[i] + prices[i], sell[i - 1]);
	}
	return sell[n - 1];
}