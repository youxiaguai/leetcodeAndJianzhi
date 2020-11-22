#pragma once
#include "common.h"
int minTimeToVisitAllPoints(vector<vector<int>>& points) {
	int m = points.size();
	int n = points[0].size();
	int result=0;
	for (int i = 0; i < m-1; i++)
	{
		
		int heng = abs(points[i][0] - points[i + 1][0]);
		int zong = abs(points[i][1] - points[i + 1][1]);
		result += max(heng, zong);
	}
	return result;
}