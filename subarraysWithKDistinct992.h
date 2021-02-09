#pragma once
#include "common.h"
int subarraysWithKDistinct(vector<int>& A, int K) {
	int n = A.size();
	vector<int>preSum(n+1, 0);
	preSum[0] = 0;
	for (int i = 0; i < n; i++)
	{
		preSum[i + 1] = preSum[i] + A[i];
	}
	for (int i = 1; i < n; i++)
	{
		
	}
}