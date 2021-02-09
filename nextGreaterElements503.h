#pragma once
#include "common.h"
#include <stack>
vector<int> nextGreaterElements(vector<int>& nums) {
	stack<int>st;
	int n = nums.size();
	vector<int>res(n);
	for (int i =2* nums.size()-1; i >= 0; i--)
	{
		while (!st.empty()&&st.top()<nums[i%n])
		{
			st.pop();
		}
		res[i%n] = st.empty() ? -1 : st.top();
		st.push(nums[i%n]);
	}
	return res;
}