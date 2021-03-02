#pragma once
#include "common.h"
int intervalSchedule(vector<vector<int>>& intvs)
{
	if (intvs.size() == 0)return 0;
	sort(intvs.begin(), intvs.end(), [](const vector<int>& a, const vector<int>& b)
	{
		return a[1] < b[1];
	});
	int count = 1;
	int x_end = intvs[0][1];
	for (auto interval : intvs)
	{
		int start = interval[0];
		if (start >= x_end)
		{
			count++;
			x_end = interval[1];
		}
	}
	return count;
}