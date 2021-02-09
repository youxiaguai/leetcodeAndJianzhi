#pragma once
#include "common.h"
int rob(vector<int>& nums) {
	if (nums.empty())
	{
		return 0;
	}
	int n = nums.size();
	if (n == 1)
	{
		return nums[0];
	}
	vector<int>dp(n, 0);
	
	dp[0] = nums[0];
	dp[1] = max(nums[0],nums[1]);
	for (int i = 2; i < n; i++)
	{
		dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
	}
	return dp[n-1];
	//一维数组解法
	vector<int>dpp(n, 0);
	int dp_i_1 = 0, dp_i_2 =1;
	int dp_i = 0;
	for (int i = n-1; i >=0; i--)
	{
		dp_i = max(dp_i_1, nums[i] + dp_i_2);
		dp_i_1 = dp_i_2;
		dp_i_2 = dp_i;
	}
}