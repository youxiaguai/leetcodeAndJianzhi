#pragma once
#pragma once
#include <iostream>
#include <vector>
using namespace std;
void moveZeroes(vector<int>& nums) {
	//记录当前零的个数
	int zeroNum = 0;
	int n = nums.size();
	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] == 0)
		{
			zeroNum++;
		}
		else
		{
			nums[i - zeroNum] = nums[i];
		}


	}
	for (int i = n - zeroNum; i < n; i++)
	{
		nums[i] = 0;
	}
	for (int i = 0; i < nums.size(); i++)
	{
		if (i == 0)
		{
			cout << "[" << nums[i] << ",";
		}
		else if(i==n-1)
		{
			cout << nums[i] << "]";
		}
		else
		{
			cout << nums[i] << ",";
		}
	}
}