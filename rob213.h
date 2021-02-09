#pragma once
#include "common.h"
int robchage(vector<int>& nums, int start, int end)
{
	int n = nums.size();
	int dp_i_1 = 0, dp_i_2 = 0;
	int dp_i = 0;
	for (int i = n - 1; i >= start; i--)
	{
		dp_i = max(dp_i_1, nums[i] + dp_i_2);
		dp_i_2 = dp_i_1;
		dp_i_1 = dp_i;
	}
	return dp_i;
}
int rob(vector<int>& nums) {
	int n = nums.size();
	int result = 0;
	result = max(robchage(nums, 0, n - 2), robchage(nums, 1, n - 1));
	return result;
}