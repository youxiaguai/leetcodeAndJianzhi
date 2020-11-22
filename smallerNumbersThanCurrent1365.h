#pragma once
#include "common.h"
vector<int> smallerNumbersThanCurrent(vector<int>& nums)
{
	//��һ������洢ÿһ��Ԫ�س��ֵĴ���
	vector<int>count(101, 0);
	for (int i = 0; i < nums.size(); i++)
	{
		count[nums[i]]++;
	}
	for (int i = 1; i < 101; i++)
	{
		count[i] += count[i - 1];
	}
	vector<int> ret;
	for (int i = 0; i < nums.size(); i++) {
		ret.push_back(nums[i] == 0 ? 0 : count[nums[i] - 1]);
	}
	return ret;

	
}