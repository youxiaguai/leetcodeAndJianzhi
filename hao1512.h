#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int numIdenticalPairs(vector<int>& nums) {
	
	int n = nums.size();

	int result = 0;
	
	//用一个unordered_map来存nums各个元素出现的个数
	unordered_map<int, int>numMap;
	for (int num : nums)
	{
		++numMap[num];
	}


	for ( auto iter=numMap.begin();iter!=numMap.end();++iter)
	{
		int v = iter->second;
		result += v * (v - 1) / 2;
	}
	return result;
}