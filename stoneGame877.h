#pragma once
#include "common.h"
bool stoneGame(vector<int>& piles) {
	//dp[i][j]表示当剩下的石子堆为下标i到下标j时，当前玩家与另一个玩家的石子数量之差的最大值
	int n = piles.size();
	vector<vector<int>>dp(n, vector<int>(n,0));
	for (int i = 0; i < n; i++) {
		dp[i][i] = piles[i];
	}
	for (int j=1;j<n;j++)
	{
		for (int i=j-1;i>=0;i--)
		{
			
			dp[i][j] = max(piles[i] - dp[i+1][j], piles[i]-dp[i][j - 1]);
			
		}
	}
	return dp[0][n - 1] > 0;

}