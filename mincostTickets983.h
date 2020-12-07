#pragma once
#include "common.h"
int mincostTickets(vector<int>& days, vector<int>& costs) {
	int n = days[days.size()-1];
	vector<int>dp(n + 1, 0);
	int a, b, c;
	for (int i = 0; i < days.size(); i++)
	{
		dp[days[i]] = -1;
	}
	for (int i = 1; i <=n; i++)
	{
		if (dp[i] == 0)
		{
			dp[i] = dp[i - 1];
		}
		else
		{
			a = dp[i - 1] + costs[0];
			if (i - 7 >= 0)
			{
				b = dp[i - 7] + costs[1];
			}
			else
			{
				b = costs[1];
			}
			if (i - 30 >= 0)
			{
				c = dp[i - 30] + costs[2];
			}
			else
			{
				c = costs[2];
			}
			dp[i] = min(a, b);
			dp[i] = min(dp[i], c);
		}
		return dp[n];
	}
}