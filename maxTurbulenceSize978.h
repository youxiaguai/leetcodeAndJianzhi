#pragma once
#include "common.h"
int maxTurbulenceSize(vector<int>& arr) {
	int n = arr.size();
	if (n == 1)return 1;
	if (n == 2)
	{
		if (arr[1] != arr[0])
		{
			return 2;
		}
		return 1;
	}
	//dp[i][0]表示>湍流的个数，dp[i][1]表示<湍流的个数
	vector<vector<int>>dp(n,vector<int>(2,1));
	dp[0][0] =dp[0][1]= 1;
	
	//int jiben = arr[0] - arr[1];
	
	for (int i = 1; i < n; i++)
	{
		
		//int jiben = arr[i - 1] - arr[i - 2];
		int ci = arr[i] - arr[i - 1];
		if (ci > 0)
		{
			dp[i][0] =dp[i-1][1]+1;
				//dp[i][0] = 1;
		}
		else if(ci<0)
		{
			dp[i][1] = dp[i - 1][0] + 1;
		}
		
		
	}
	int res = 1;
	for (int i = 0; i < n; i++)
	{
		res = max(res, dp[i][0]);
		res = max(res, dp[i][1]);
	}
	return res;
}