#pragma once
#include <iostream>
#include <vector>
using namespace std;

vector<int> runningSum(vector<int>& nums)
{
	int n = nums.size();
	vector<int> sum(n, 0);
	sum[0] = nums[0];
	cout << "[" << sum[0] << ",";
	for (int i = 1; i < n; i++)
	{
		sum[i] = nums[i] + sum[i-1];
		
		if (i == n - 1)
		{
			cout << sum[i]<<"]";
		}
		else
		{
			cout << sum[i] << ",";
		}
		
	}
	return sum;
}
