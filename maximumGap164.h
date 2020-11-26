#pragma once
#include "common.h"
int maximumGap(vector<int>& nums) {
	sort(nums.begin(), nums.end());
	int maxx = 0;
	for (int i = 1; i < nums.size(); i++)
	{
		maxx = max(maxx, nums[i] - nums[i - 1]);
	}
	return maxx;
}