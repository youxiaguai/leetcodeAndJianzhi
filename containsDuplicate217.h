#pragma once
#include <set>
#include "common.h"
bool containsDuplicate(vector<int>& nums) {
	unordered_set<int>se;
	for (int i = 0; i < nums.size(); i++)
	{
		se.insert(nums[i]);
	}
	if (se.size() == nums.size())
	{
		return false;
	}
	return true;
}