#pragma once
#include "common.h"
#include <string>
vector<string> summaryRanges(vector<int>& nums) {
	int n = nums.size();
	vector<string>result;
	
	int i = 0;
	while (i<n)
	{
		int left = i;
		i++;
		while (i<n&&nums[i]==nums[i-1]+1)
		{
			i++;
		}
		int right = i - 1;
		string temp = to_string(nums[left]);
		if (left < right)
		{
			temp.append("->");
			temp.append(to_string(nums[right]));
		}
		result.push_back(move(temp));
	}
	return result;
}