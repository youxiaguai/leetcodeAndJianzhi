#pragma once
#include "common.h"
int maxProduct(vector<int>& nums) {
	//����ȡǰ�����
	sort(nums.begin(), nums.end());
	return (nums[nums.size() - 1] - 1) * (nums[nums.size() - 2] - 1);
}