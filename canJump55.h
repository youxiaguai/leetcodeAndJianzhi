#pragma once
#include "common.h"
bool canJump(vector<int>& nums) {
	int n = nums.size();
	int index = 0;//¼ÇÂ¼ÏÂ±ê
	for (int i = 0; i < n; i++)
	{
		if (i <= index)
		{
			index = max(index, i+nums[i]);
			if (index >= n - 1)
			{
				return true;
			}
		}
	}
	return false;
}