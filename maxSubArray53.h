#pragma once
#include "common.h"
int maxSubArray(vector<int>& nums) {
	int maxx = nums[0];
	int result = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		
		result = max(nums[i], result + nums[i]);
		maxx = max(maxx, nums[i]);

	}
	return maxx;


	int pre = 0, maxAns = nums[0];
	for (const auto& x : nums) {
		pre = max(pre + x, x);
		maxAns = max(maxAns, pre);
	}
	return maxAns;

	

}