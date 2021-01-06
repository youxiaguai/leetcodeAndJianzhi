#pragma once
#include "common.h"
vector<int>cunt;
int dp(vector<int>& coins, int rem)
{
	if (rem < 0)return -1;
	if (0 == rem)return 0;
	if (cunt[rem - 1] != 0)return cunt[rem - 1];
	int Min = INT_MIN;
	for (int coin : coins)
	{
		int res = dp(coins, rem - coin);
		if (res >= 0 && res < Min)
		{
			Min = res + 1;
		}
	}
	cunt[rem - 1] = Min == INT_MIN ? -1 : Min;
	return cunt[rem - 1];
}
int coinChange(vector<int>& coins, int amount) {
	if (amount<1)
	{
		return 0;
	}
	cunt.resize(amount);
	return dp(coins, amount);
}
int coinChange(vector<int>& coins, int amount) {
	if (0 == amount)
	{
		return 0;
	}
	int n = coins.size();
	vector<long>dp(amount + 1, amount + 1);
	dp[0] = 0;
	for (const auto& coin : coins)
	{
		for(int j=1;j<=amount;j++)
		{
			if (j >= coin)
			{
				dp[j] = min(dp[j], dp[j - coin] + 1);
			}
		}
	}
	if (dp[amount] == amount + 1)
	{
		return -1;
	}
	return static_cast<int>(dp[amount]);
}