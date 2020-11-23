#pragma once
#include "common.h"
vector<int> replaceElements(vector<int>& arr) {
	//倒着将后面的数组的最大值存起来
	int n = arr.size();
	vector<int> maxV(n, 0);
	maxV[n - 1] = arr[n-1];
	for (int i = n-2; i>=0; i--)
	{
		maxV[i] = max(maxV[i + 1], arr[i+1]);
		
	}
	maxV[n - 1] = -1;
	for (int i = 0; i < n; i++)
	{
		cout << maxV[i] << ",";
	}
	return maxV;
}