#pragma once
#include "common.h"
vector<int> twoSum(vector<int>& nums, int target) {
	unordered_map<int, int>ma;
	for (int i = 0; i < nums.size(); i++)
	{
		auto it = ma.find(target - nums[i]);
		if (it != ma.end())
		{
			return { it->second,i };
		}
		ma[nums[i]] = i;
	}
	return {};
}