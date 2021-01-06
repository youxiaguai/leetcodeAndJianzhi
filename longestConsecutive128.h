#pragma once
#include <set>
#include "common.h"
int longestConsecutive(vector<int>& nums) {
	int result = 0;
	int n = nums.size();
	unordered_set<int>st;
	for (int i = 0; i < nums.size(); i++)
	{
		st.insert(nums[i]);
	}
	for (int i = 0; i < n; i++)
	{
		//int count = 0;
		
		if(!st.count(nums[i]))
		{
			int tmp = nums[i];
			int count = 1;
			while (st.count(nums[i]+1))
			{
				tmp += 1;
				count += 1;
			}
			result = max(result, count);
		}
		
	}
	return result;
}