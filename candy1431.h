#pragma once
#include "common.h"
	vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) 
	{
		vector<bool> result(candies.size(), false);
		//找到最大的
		int maxx = 0;
		for (int i=0;  i<candies.size();i++)
		{
			maxx = max(candies[i], maxx);
		}

		//能达到最大值的最小值
		int minn = maxx - extraCandies;
		for (int i = 0; i < candies.size(); i++)
		{
			if (candies[i] < minn)
			{
				result[i] = false;
			}
			else
			{
				result[i] = true;
			}
			if (i == 0)
			{
				cout << "[" << result[i] << ",";
			}
			else if (i == candies.size() - 1)
			{
				cout << result[i] << "]";
			}
			else
			{
				cout << result[i] << ",";
			}
		}
		return result;
	}