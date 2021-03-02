#pragma once
#include "common.h"
int removeDuplicates(vector<int>& nums) {
	int n = nums.size();
	int slow = 0, fast = 1;
	if (n == 0)return 0;
	while (fast<n)
	{
		if (nums[slow] != nums[fast])
		{
			nums[slow] = nums[fast];
			slow++;
			fast++;
		}
		else
		{
			fast++;
		}
	}
	nums.resize(slow + 1);
	return slow+1;
}
