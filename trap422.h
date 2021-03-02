#pragma once
#include "common.h"
int trap(vector<int>& height) {
	if (height.empty())return 0;
	int left = 0, right = height.size() - 1;
	int ans = 0;

	int l_max = height[0];
	int r_max = height[height.size() - 1];

	while (left<=right)
	{
		
		l_max = max(height[left], l_max);
		r_max = max(height[right], r_max);

		if (l_max < r_max)
		{
			ans += l_max - height[left];
			left++;
		}
		else {
			ans += r_max - height[right];
			right--;
		}
	}
	return ans;
}