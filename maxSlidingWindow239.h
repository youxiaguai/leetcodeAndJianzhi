#pragma once
#include <queue>
#include "common.h"
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
	/*暴力解法
	int n = nums.size();
	if (n == 0)
	{
		return {};
	}
	vector<int>ans(n-k+1);
	

	for (int i=0;i<n-k;i++)
	{
		int maxx = INT_MIN;
		for (int j = 0; j < k; j++)
		{
			if (nums.at(i + j) > maxx)
			{
				maxx = nums.at(i + j);
			}
		}
		ans.push_back(maxx);
	}
	return ans;
	*/
	/*队列解法*/
	int n = nums.size();
	vector<int>ans;
	if (k == 0)
	{
		return nums;
	}
	deque<int>q;
	int right = 0;
	while (right<n)
	{
		if (!q.empty()&&q.front()<=right-k)
		{
			q.pop_front();
		}
		while (!q.empty()&&nums[right]>nums[q.back()])
		{
			q.pop_back();
		}
		q.push_back(right);
		right++;
		if (right >= k)ans.push_back(nums[q.front()]);
	}
	return ans;
}