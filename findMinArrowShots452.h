#pragma once
#include "common.h"
int findMinArrowShots(vector<vector<int>>& points) {
	//比较一个坐标的左坐标与前一个的右左标比较，如果小于则减去
	if (points.empty())return 0;
	//开始坐标如果相同则用结束坐标排序，否则就用开始坐标排序
	sort(points.begin(), points.end(), [](const vector<int>& v1, const vector<int>& v2)
	{
		return v1[0] == v2[0] ? v1[1] < v2[2] : v1[0] < v2[0];
	}); 
	int res = 1,maxright=points[0][1];
	for (int i = 1; i < points.size(); i++)
	{
		//若存在开始坐标小于结束坐标
		if (points[i][0] > maxright)
		{
			res++;
			maxright = points[i][1];
		}
		else
		{
			//若不存在则更新最右值为结束坐标的最小值
			maxright = min(maxright, points[i][1]);
		}
	}
	return res;
}