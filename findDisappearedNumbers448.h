#pragma once
#include "common.h"
vector<int> findDisappearedNumbers(vector<int>& nums) {
	unordered_map<int, int>ma;
	vector<int>result;
	for (int i = 0; i < nums.size(); i++)
	{
		ma[nums[i]]++;
	}
	for (int i = 1; i <= nums.size(); i++)
	{
		if (ma.find(i) == ma.end())
		{
			result.push_back(i);
		}	
	}
	return result;
}