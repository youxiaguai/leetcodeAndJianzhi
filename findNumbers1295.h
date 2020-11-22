#pragma once
#include "common.h"
int findNumbers(vector<int>& nums) {
	int result = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		int geshu = 0;
		while (nums[i]!=0)
		{
			
			geshu += 1;
			nums[i] /= 10;
		}
		if (geshu % 2 == 0)
		{
			result++;
		}
	}
	return result;
}