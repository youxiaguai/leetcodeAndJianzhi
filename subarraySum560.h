#pragma once
#include "common.h"
int subarraySum(vector<int>& nums, int k) {
	//前缀和
	int n = nums.size();
	vector<int>preSum(n + 1);
	preSum[0] = 0;
	for (int i = 0; i < n; i++)
	{
		preSum[i + 1] = preSum[i] + nums[i];
	}
	int res = 0;
	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (preSum[i] - preSum[j] == k)
			{
				res++;
			}
		}
	}
	return res;

	//优化后
	unordered_map<int, int>mp;
	mp[0] = 1;
	int sum0_i = 0, ans=0;
	//vector<int>Sum(n + 1);
	for (int i = 0; i < n; i++)
	{
		sum0_i+= nums[i];
		int sum0_j = sum0_i - k;
		if (mp.find(sum0_j) != mp.end())
		{
			ans += mp[sum0_j];
			mp[sum0_i] += 1;
		}
		mp[sum0_i] = 1;
	}
	return ans;
}