#pragma once
#include "common.h"
int candy(vector<int>& ratings) {
	int n = ratings.size();

	int result = 0;
	vector<int>left(n, 0);
	for (int i = 0; i < n; i++)
	{
		if (i>0&&ratings[i] > ratings[i - 1] )
		{
			left[i] = left[i - 1] + 1;
		}
		else
		{
			left[i] = 1;
		}
	}

	int right = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		if (i<n - 1 && ratings[i]>ratings[i + 1])
		{
			right++;
		}
		else
		{
			right = 1;
		}
		result += max(left[i], right);
	}
	return result;
}