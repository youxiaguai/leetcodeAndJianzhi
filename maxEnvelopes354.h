#pragma once
#include "common.h"
int maxEnvelopes(vector<vector<int>>& envelopes) {
	int m = envelopes.size();
	vector<int>dp(m,1);
	sort(envelopes.begin(), envelopes.end(), [](const vector<int>& a1, const vector<int>& a2)
	{
		if (a1[0] == a2[0])
		{
			return a1[1] > a2[1];
		}
		else
		{
			return a1[0] < a2[0];
		}
		//return a1[0] < a2[0] || (a1[0] == a2[0] && a1[1] > a2[1]);
	});
	int result = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (envelopes[j][1] < envelopes[i][1])
			{
				dp[i] = max(dp[i], dp[j] + 1);
			}
			
		}
		result = max(result, dp[i]);
	}
	return result;
}