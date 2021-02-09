#pragma once
#include "common.h"
#include <set>
vector<vector<int>>res;
void backtrack(vector<int>&nums,vector<int>& track,int first,int len)
{

	if (first == len)
	{
		res.push_back(track);
		return;
	}
	
	//res.push_back(track);
	for (int i = first; i < len; i++)
	{
		swap(track[i], track[first]);
		backtrack(nums, track, first+1,len);
		swap(track[i], track[first]);
		
		
		
	}
}
vector<vector<int>> permute(vector<int>& nums) {
	vector<int>track;
	
	backtrack(nums, track, 0,nums.size());
	return res;
}