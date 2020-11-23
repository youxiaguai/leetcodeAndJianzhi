#pragma once
#include "common.h"
int maxProduct(vector<int>& nums) {
	//排序，取前两最大
	sort(nums.begin(), nums.end());
	return (nums[nums.size() - 1] - 1) * (nums[nums.size() - 2] - 1);
}