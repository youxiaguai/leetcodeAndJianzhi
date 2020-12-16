#pragma once
#include <stack>
#include "common.h"
int trap(vector<int>& height) {
	//暴力解法
	int ans = 0;
	int n = height.size();
	vector<int>left_max(n), right_max(n);
	left_max[0] = height[0];
	for (int i = 1; i < n - 1; i++)
	{
		left_max[i] = max(height[i], left_max[i - 1]);
	}
	right_max[n - 1] = height[n - 1];
	for (int i = n - 2; i >= 0; i--)
	{
		right_max[i] = max(height[i], right_max[i + 1]);
	}
	for (int i = 1; i < n - 1; i++)
	{
		ans += min(left_max[i], right_max[i]) - height[i];
	}
	return ans;
	//栈的应用
	int ans = 0, current = 0;
	int size = height.size();
	stack<int>stac;
	while (current<size)
	{
		while (!stac.empty()&&height[current]>height[stac.top()])
		{
			int top = stac.top();
			stac.pop();
			if (stac.empty())
			{
				break;
			}
			int distance = current - stac.top() - 1;
			int bound_height=min(height[current],height[stac.top()])
		}
	}
}