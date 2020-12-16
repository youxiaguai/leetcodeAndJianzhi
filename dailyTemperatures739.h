#pragma once
#include <stack>
#include "common.h"
vector<int> dailyTemperatures(vector<int>& T) {
	int n = T.size();
	vector<int>result(n, 0);
	stack<int>s;
	for (int i =0;i<n;i++)
	{
		while (!s.empty() && T[i] > T[s.top()])
		{
			int pre = s.top();
			result[pre] = i - pre;
			s.pop();
		}
		s.push(i);
	}
	return result;
}