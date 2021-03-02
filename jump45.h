#pragma once
#include "common.h"
vector<int>memo;
int dp(vector<int>& nums, int p)
{
	int n = nums.size();
	if (p >= n-1)
	{
		return 0;
	}
	if (memo[p] != n)
	{
		return memo[p];
	}
	int steps = nums[p];
	for (int i = 1; i <= steps; i++)
	{
		int subProblem = dp(nums, p + i);
		memo[p] = min(memo[p], subProblem + 1);
	}
	return memo[p];
}
int jump(vector<int>& nums) {
	//动态规划
	/*int n = nums.size();
	memo = vector<int>(n,n);
	return dp(nums, 0);*/
	//贪心算法
	int n = nums.size();
	int end = 0;
	int far = 0;
	int jumps = 0;
	for (int i = 0; i < n; i++)
	{
		far = max(nums[i] + i, far);
		if (i == end)
		{
			jumps++;
			end = far;
		}
	}
	return jumps;
}