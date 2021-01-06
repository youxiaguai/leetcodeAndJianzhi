#pragma once
#include "common.h"
int minPatches(vector<int>& nums, int n) {
	int patches = 0;
	long long x = 1;
	int length = nums.size();
	int index = 0;
	while (x<=n)
	{
		if (index < length && nums[index] <= x)
		{
			x += nums[index];
			index++;
		}
		else
		{
			x <<= 1;
			patches++;
		}
	}
	return patches;
	

}