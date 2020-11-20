#pragma once
#include "common.h"
	int xorOperation(int n, int start)
	{
		vector<int>nums(n, 0);
		int result=start;
		
		for (int i = 1; i < n; i++)
		{
			nums[i] = start + 2 * i;
			result ^= nums[i];
		}
		return result;
	}