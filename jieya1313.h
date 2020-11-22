#pragma once
#include "common.h"
	vector<int> decompressRLElist(vector<int>& nums) {
		vector<int>result;
		//每两个两个的一起看
		for (int i = 0; i < nums.size() - 1; i+=2)
		{
			int num = nums[i];
			int times = nums[i+1];
			for (int j = 0; j < num; j++)
			{
				result.push_back(times);
			}
		}
		return result;
}