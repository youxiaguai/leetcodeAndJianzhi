#pragma once
#include "common.h"
int maximalRectangle(vector<vector<char>>& matrix) {
	int m = matrix.size();
	

	if (m==0)
	{
		return 0;
	}
	int n = matrix[0].size();
	int maxWidth = 0,maxArea=0;
	vector<vector<int>>dp(m, vector<int>(n, 0));
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (j==0)
			{
				dp[i][j] = matrix[i][j] - '0';
			}
			else
			{
				matrix[i][j] == '1' ? dp[i][j] = dp[i][j - 1] + 1 : dp[i][j] = 0;
			}
			maxWidth = dp[i][j];
			for (int k = i; k >= 0; --k)
			{
				maxWidth = min(maxWidth, dp[k][j]);
				maxArea = max(maxArea, maxWidth * (i - k+1));
			}
		}

	}
	return maxArea;
}