#pragma once
#include "common.h"
#include <unordered_set>

vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
	unordered_set<int>sset;
	vector<int>res;
	for (auto ed : edges)
	{
		sset.insert(ed[1]);
	}
	for (int i = 0; i < n; i++)
	{
		if (sset.find(i) == sset.end())
		{
			res.push_back(i);
		}
	}
	return res;
}