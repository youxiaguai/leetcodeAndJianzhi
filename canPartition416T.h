#pragma once
#include "common.h"
#include <numeric>
#include <algorithm>
bool canPartition(vector<int>& nums) {
	int n = nums.size();
	//���
	int sum = accumulate(nums.begin(), nums.end(), 0);
	//�������С��2
	if (n < 2)
	{
		return false;
	}
	//�ж��Ƿ�Ϊż��
	if (sum & 1)
	{
		return false;
	}
	//�ж����Ԫ���Ƿ�����ܺ͵�һ��
	int maxNum = *max_element(nums.begin(), nums.begin()+n);
	int target = sum / 2;
	if (maxNum > target)
	{
		return false;
	}
	vector<vector<int>>dp(n+1, vector<int>(target+1, 0));
	for (int i = 0; i < n; i++)
	{
		dp[i][0] = true;
		
	}
	dp[0][nums[0]] = true;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= target; j++)
		{
			//���Ѿ�װ�����ǰһ�����
			if (j - nums[i - 1] < 0)
			{
				dp[i][j] = dp[i - 1][j];
			}
			else
			{
				//������Ҫ��Ҫ���뱳��
				dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[j - 1]];
			}
			
		}
		
	}
	return dp[n][target];

}