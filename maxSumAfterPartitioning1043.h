#pragma once
#include "common.h"
class Solution {
public:
	int maxSumAfterPartitioning(vector<int>& arr, int k) {
		int n = arr.size();
		vector<int>dp(n+1, 0);
	
		
		for (int i = 1; i <=n; i++)
		{
			int maxv = -1;
			for (int j = i - 1; j >= max(i - k, 0); j--)
			{
				maxv = max(maxv, arr[j]);
				dp[i] = max(dp[i], dp[j] + (i - j) * maxv);
			}
		}
		
		return dp[n];
	}
};