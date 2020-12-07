#pragma once
#include "common.h"
vector<int> productExceptSelf(vector<int>& nums) {
	int length = nums.size();
	vector<int>left(length, 0);
	vector<int>right(length, 0);
	vector<int>result(length);
	left[0] = 1;
	for (int i = 1; i < length; i++)
	{
		left[i] = left[i - 1] * nums[i - 1];
	}
	right[length - 1] = 1;
	for (int i = length - 2; i >= 0; i--)
	{
		right[i] = right[i + 1] * nums[i + 1];
	}
	for (int i = 0; i < length; i++)
	{
		result[i] = left[i] * right[i];
	}
	return result;
}