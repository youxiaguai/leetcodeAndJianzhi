#pragma once
#include "common.h"
int maxProduct(vector<int>& nums) {
	int n = nums.size();
	vector<int>minn(n);
	vector<int>maxx(n);
	int ans = nums[0];
	minn[0] = maxx[0] = nums[0];
	for (int i = 1; i < n; i++)
	{
		maxx[i] = max( maxx[i - 1] * nums[i],max(nums[i],minn[i-1]*nums[i]));
		minn[i] = min(minn[i - 1] * nums[i], min(nums[i], maxx[i - 1] * nums[i]));
		ans = max(maxx[i], ans);
	}
	return ans;
}