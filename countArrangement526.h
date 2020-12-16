#pragma once
#include "common.h"
class A {
	int count = 0;
	void permute(vector<int>& nums, int l)
	{
		if (l == nums.size() - 1)
		{
			for (int i = 1; i <= nums.size(); i++)
			{
				if (i % nums[i - 1] != 0 && nums[i - 1] % i != 0)
				{
					break;
				}
			}
			if (l > nums.size())
			{
				count++;
			}
		}
		for (int i = 1; i < nums.size(); i++)
		{
			swap(nums, i, l);
			permute(nums, l + 1);
			swap(nums, i, l);
		}
	}
	void swap(vector<int>& nums, int l, int r)
	{
		int temp = nums[l];
		nums[l] = nums[r];
		nums[r] = temp;
	}
	int countArrangement(int N) {
		int count = 0;
		vector<int>nums(N, 0);
		for (int i = 1; i <= N; i++)
		{
			nums[i - 1] = i;
		}
		permute(nums, 0);
		return count;

	}
};
