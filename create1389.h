#pragma once
#include "common.h"
struct node
{
	int val;
	int index;
	node* next;
	node(int x, int y) : val(x), index(y), next(NULL) {}
};
vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
	//最核心的是插入，插入之后原来的数顺势后移
	vector<int>result;
	for (int i = 0; i < nums.size(); i++)
	{
		result.insert(result.begin()+index[i], nums[i]);
	}
	return result;
}