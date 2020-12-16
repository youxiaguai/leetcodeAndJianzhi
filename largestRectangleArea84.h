#pragma once
#include <stack>
#include "common.h"
int largestRectangleArea(vector<int>& heights) {
	int n = heights.size();
	//±©Á¦½â·¨

	int maxx = 0;
	for (int i = 0; i < n; i++)
	{
		int minn = INT_MAX;
		for (int j = i; j < n; j++)
		{
			minn = min(minn, heights[j]);
			
			
			maxx = max(maxx, (j-i+1)*minn);
		}
	}
	return maxx;
	vector<int>left(n), right(n,n);
	stack<int>ministack;

	for (int i = 0; i < n; ++i)
	{
		while (!ministack.empty()&&heights[ministack.top()]>=heights[i])
		{
			right[ministack.top()] = i;
			ministack.pop();
		}
		left[i] = (ministack.empty() ? -1 : ministack.top());
		ministack.push(i);
	}
	
	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		ans = max((right[i] - left[i] - 1) * heights[i], ans);
	}
	return ans;
}