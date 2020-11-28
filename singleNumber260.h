#pragma once
#include "common.h"
vector<int> singleNumber(vector<int>& nums) {
	int n = nums.size();
	vector<int>res(n,0);
	vector<int>temp(n,0);
	for (int i = 0; i < nums.size(); i++)
	{
		temp[nums[i]]++;
	}
	for (int i = 0; i < temp.size(); i++)
	{
		if (temp[i] == 1)
		{
			res.push_back(i);
		}
	} 
	return res;

}