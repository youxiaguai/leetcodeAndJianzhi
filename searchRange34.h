#pragma once
#include "common.h"
vector<int> searchRange(vector<int>& nums, int target) {
	int start = 0;
	int end = nums.size() - 1;
	int mid = (start + end) / 2;
	bool flag = false;
	
	while (start <= end)
	{
		 mid = (start+end) / 2;
		if (nums[mid] < target)
		{
			start = mid + 1;
		}
		else if (nums[mid] > target)
		{
			end = mid - 1;
		}
		else 
		{
			flag = true;
			break;
		}
	}
	if (flag)
	{
		int left = mid;
		int right = mid;
		while (left-1>=0&&nums[left-1]==target)
		{
			left--;
		}
		while (right+1<=nums.size()-1&&nums[right+1]==target)
		{
			right++;
		}
		return vector<int>{left, right};
	}
	return vector<int>{-1, -1};
}
