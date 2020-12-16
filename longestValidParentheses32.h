#pragma once
#include <stack>
#include "common.h"
int longestValidParentheses(string s) {
	int n = s.length();
	int maxx = 0;
	vector<int>dp(n, 0);
	for (int i = 1; i < n; i++)
	{
		if (s[i] = ')')
		{
			if (s[i - 1] == '(')
			{
				dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
			}
			else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(')
			{
				dp[i] = dp[i - 1] + ((i - dp[i - 1]) >= 2 ? dp[i - dp[i - 1] - 2] : 0) + 2;
			}
			maxx = max(maxx, dp[i]);
		}
	}
		
	return maxx;
}