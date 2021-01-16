#pragma once
#include <stack>
#include "common.h"
int findUnsortedSubarray(vector<int>& nums) {
	stack<int>sk;
	int n = nums.size();
	int r = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		while (!sk.empty()&&nums[sk.top()]>nums[i])
		{
			n = min(n, sk.top());
			sk.pop();
		}
		sk.push(i);
	}
	for (int i = nums.size() - 1; i >= 0; i--)
	{
		while (!sk.empty()&&nums[sk.top()]<nums[i])
		{
			r = max(r, sk.top());
			sk.pop();
		}
		sk.push(i);
	}
	return r - n > 0 ? r - n + 1 : 0;
}