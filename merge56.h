#pragma once
#include "common.h"
vector<vector<int>> merge(vector<vector<int>>& intervals) {
	int n = intervals.size();
	if (n == 1)
	{
		return intervals;
	}
	if (n < 1)
	{
		return {};
	}
	sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b)
	{
		return a[0] < b[0];
	});
	vector<vector<int>>result;
	
	for (int i = 0; i < intervals.size(); i++)
	{
		int L = intervals[i][0];
		int R = intervals[i][1];
		if ( !result.size() ||result.back()[1]<L)
		{
			
			result.push_back({L,R});
		}
		else
		{
			
			result.back()[1] = max(result.back()[1], R);
		}
	}
	return result;
} 