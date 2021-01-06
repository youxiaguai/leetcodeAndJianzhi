#pragma once
#include "common.h"
int lengthOfLIS(vector<int>& nums) {
	int n = nums.size();
	vector<int>result(n,0);
	if (n == 0)return 0;
	
	for (int i = 0; i < n; i++)
	{
		result[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (nums[j] < nums[i])
			{
				result[i] = max(result[i],result[j] + 1);
			}
		}
		
	}
	return *max_element(result.begin(), result.end());
}