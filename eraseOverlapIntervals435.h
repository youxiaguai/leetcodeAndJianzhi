#pragma once
#include "common.h"
static bool cmp(vector<int>a, vector<int>b)
{
	return a[1] < b[1];
}

int eraseOverlapIntervals(vector<vector<int>>& intervals) {
	if (intervals.empty())
	{
		return 0;
	}
	sort(intervals.begin(), intervals.end(), cmp);
	int end = intervals[0][1];
	int res = 0;
	for(int i = 1; i < intervals.size(); i++)
	{
		if (intervals[i][0] < end)//��һ���Ŀ�ʼ�ڵ���ǰһ�������ڵ�֮ǰ���н���
		{
			++res;
		}
		else
		{
			end = intervals[i][1];
		}
	}
	return res;
}