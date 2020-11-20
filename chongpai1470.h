#pragma once
#pragma once
#include <iostream>
#include <vector>
using namespace std;

vector<int> shuffle(vector<int>& nums, int n) {
	vector<int>result(2*n,0);
	int j = 0;
	for (int i = 0; i < n; i++)
	{
		
		result[j++] = nums[i];
		result[j++] = nums[i + n];
	}
	for (int i = 0; i < nums.size(); i++)
	{
		if (i == 0)
		{
			cout << "[" << result[i] << ",";
		}
		else if (i == 2*n - 1)
		{
			cout << result[i] << "]";
		}
		else
		{
			cout << result[i] << ",";
		}
	}
	return result;

}