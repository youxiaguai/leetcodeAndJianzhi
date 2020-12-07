#pragma once
#include "common.h"
int minimumTotal(vector<vector<int>>& triangle) {
	int m = triangle.size();
	vector<vector<int>>dp(m, vector<int>(m, 0));
	
	
	
	//初始化最后一行
	for (int i =0; i <=m-1; i++)
	{
		dp[m - 1][i] = triangle[m - 1][i];
	}
	for (int i =m-2; i>=0; i--)
	{
		for (int j = 0; j <= i; j++)
		{
			dp[i][j] = min(dp[i + 1][j], dp[i + 1][j + 1]) + triangle[i][j];
		}
	}
	return dp[0][0];
}