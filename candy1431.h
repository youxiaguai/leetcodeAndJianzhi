#pragma once
#include "common.h"
	vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) 
	{
		vector<bool> result(candies.size(), false);
		//�ҵ�����
		int maxx = 0;
		for (int i=0;  i<candies.size();i++)
		{
			maxx = max(candies[i], maxx);
		}

		//�ܴﵽ���ֵ����Сֵ
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