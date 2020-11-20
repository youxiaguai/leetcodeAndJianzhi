#pragma once
#include "common.h"
int minOperations(int n)
{
	//找到中位数，前面每个数与中位数差的和
	vector<int>arr(n, 0);
	for (int i = 0; i < n; i++)
	{
		arr[i] = 2 * i + 1;
	}
	int mid = 0;
	int result = 0;
	if (n % 2 == 1)
	{
		mid = arr[n / 2];
		
	}
	else
	{
		mid = (arr[n / 2] + arr[n / 2 - 1]) / 2;
	}
	for (int j = 0; j < n / 2; j++)
		{
			result += mid - arr[j];
		}
	return result;
}