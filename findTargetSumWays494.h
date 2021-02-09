#pragma once
#include "common.h"
#include <string>
int result = 0;
int backtrack(vector<int>& nums, int i, int rest)
{
	unordered_map<string, int>memo;
	if (i == nums.size())
	{
		if (rest == 0)
		{
			result++;
		}
		return;
	}
	string string_i = to_string(i);
	string string_rest = to_string(rest);
	string key =  string_i+ "," + string_rest;
	if (memo.count(key))
	{
		return memo[key];
	}
	int result = backtrack(nums, i + 1, rest - nums[i]) + backtrack(nums, i + 1, rest + nums[i]);
	memo[key] = result;
	return result;
	rest += nums[i];
	backtrack(nums, i + 1, rest);
	rest -= nums[i];

	rest -= nums[i];
	backtrack(nums, i + 1, rest);
	rest += nums[i];
}
int findTargetSumWays(vector<int>& nums, int S) {
	if (nums.size() == 0)return 0;
	backtrack(nums, 0, S);
	return result;
}