#pragma once
#include "common.h"
int minCount(vector<int>& coins)
{
	int result = 0;
	for (int i = 0; i < coins.size(); i++)
	{
		result += coins[i] / 2;
		if (coins[i] % 2 == 1)
		{
			result += 1;
		}
	}
	return result;
}