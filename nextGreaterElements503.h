#pragma once
#include "common.h"
#include <stack>
vector<int> nextGreaterElements(vector<int>& nums) {
	stack<int>st;
	st.push(nums[0]);
	int n = nums.size();
	vector<int>ret(n);
	for (int i = n*2-1; i >=0 ; i--)
	{
		while (!st.empty()&&nums[i%n]>=st.top())
		{
			
			st.pop();
		}
		ret[i % n] == st.empty() ? -1 : st.top();
		st.push(nums[i % n]);
	}
	return ret;
}