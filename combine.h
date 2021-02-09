#pragma once
#include "common.h"
vector<vector<int>>res;
void backtrack(int n, int start, int k, vector<int>& track)
{
	if (k == track.size())
	{
		res.push_back(track);
		return;
	}
	//vector<int>track;
	
	for (int i = start; i <=n; i++)
	{
		track.push_back(i);
		backtrack(n, i + 1, k, track);
		track.pop_back();
	}
}
vector<vector<int>> combine(int n, int k) {
	vector<int>track;
	if (k <= 0 || n <= 0)return res;
	
		backtrack(n, 1, k, track);
	
	return res;
}