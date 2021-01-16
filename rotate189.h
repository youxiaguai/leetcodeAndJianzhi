#pragma once
#include "common.h"
void reverse(vector<int>& nums, int begin, int end)
{
	while (begin<end)
	{
		swap(nums[begin], nums[end]);
		begin += 1;
		end -= 1;
	}
}
void rotate(vector<int>& nums, int k) {
	k %= nums.size();
	reverse(nums, 0, nums.size()-1);
	reverse(nums, 0, k-1);
	reverse(nums, k, nums.size()-1);
}