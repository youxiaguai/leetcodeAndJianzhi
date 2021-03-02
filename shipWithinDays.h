#pragma once
#include "common.h"
int sum(vector<int>& weights)
{
	int res = 0;
	for (auto n : weights)
	{
		res += n;
	}
	return res;
}
//每天运weight 运D是否可以运完
bool canFinish(vector<int>& weights, int D, int weight)
{
	int i = 0;
	for (int day=0; day <D; day++)
	{
		int maxWeight = weight;
		while ((maxWeight-=weights[i])>=0)
		{
			i++;
			if (i == weights.size())
			{
				return true;
			}
		}
		
	}return false;
}
int shipWithinDays(vector<int>& weights, int D) {
	vector<int>::iterator iter = weights.begin();
	int n = weights.size();
	int left = *max_element(iter, iter + n);
	int right = sum(weights);
	while (left<right)
	{
		int mid = left + (right - left) / 2;
		if (canFinish(weights,D,mid))
		{
			right = mid;
		}
		else
		{
			left = mid + 1;
		}
	}
	return left;
}
