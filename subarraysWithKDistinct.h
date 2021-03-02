#pragma once
#include "common.h"
int subarraysWithKDistinct(vector<int>& A, int K) {
	//前缀和解法
	int n = A.size();
	vector<int>preSum(n + 1, 0);
	preSum[0] = 0;
	for (int i = 0; i < n; i++)
	{
		preSum[i + 1] = preSum[i] + A[i];
	}
	int res = 0;
	for (int i = 1; i < n+1; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (preSum[i] - preSum[j] == K)
			{
				res++;
			}
		}
	}
	return res;
}
