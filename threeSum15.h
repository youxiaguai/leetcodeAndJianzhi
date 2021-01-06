#pragma once
#include "common.h"
vector<vector<int>> threeSum(vector<int>& nums) {
	//固定一个数，找剩下的中能和其相加得到0的两个数
	int n = nums.size();
	sort(nums.begin(), nums.end());
	vector<vector<int>>ans;
	for (int first = 0; first < n; first++)
	{
		if (first > 0 && nums[first] == nums[first - 1])
		{
			continue;
		}
		int third = n - 1;
		int target = -nums[first];
		for (int second = first + 1; second < n; second++)
		{
			if (second > first + 1 && nums[second] == nums[second - 1])
			{
				continue;
			}
			while (second<third&&nums[second]+nums[third]>target)
			{
				--third;
			}
			if (second == target)
			{
				break;
			}
			if (nums[second] + nums[third] == target)
			{
				ans.push_back({ nums[first],nums[second],nums[third] });
			}
		}
		
	}
	return ans;
}