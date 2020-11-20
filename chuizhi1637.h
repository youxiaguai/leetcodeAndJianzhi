#pragma once
#include "common.h"
int maxWidthOfVerticalArea(vector<vector<int>>& points) {
	int result = 0;
	int n = points.size();
	vector<int> t(n, 0);
	for (int i = 0; i < n; i++)
	{
		t[i] = points[i][0];

	}
	sort(t.begin(),t.end());
	for (int i = 1; i < t.size(); i++)
	{
		result = max(result, t[i] - t[i-1]);
	}
	return result;
}