#pragma once
#include "common.h"
int search(vector<int>& nums, int target) {
	//二分法 看左右部分哪部分有序
	int n = nums.size();
	if (n == 0)
	{
		return -1;
	}
	if (n == 1 )
	{
		return target==nums[0]?0:-1;
	}
	
	int left = 0, right = n - 1;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (nums[mid] == target)
		{
			return mid;
		}
		if (nums[0] <= nums[mid])
		{
			if (nums[0] <= target && target < nums[mid])
			{
				right = mid - 1;
			}
			else
			{
				left = mid + 1;
			}
		}
		else
		{
			if (nums[mid] < target && target <= nums[n-1])
			{
				left = mid + 1;
			}
			else
			{
				right = mid - 1;
			}
		}
	}
	
	return -1;
}
