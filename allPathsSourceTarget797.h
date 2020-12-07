#pragma once
#include "common.h"
void backtrack(vector<vector<int>>& graph, int src, int dst, vector<int>cur, vector<vector<int>>& res)
{
	if (src == dst)
	{
		res.push_back(cur);
		return;
	}
	for (const auto& neighbor : graph[src])
	{
		cur.push_back(neighbor);
		backtrack(graph, neighbor, dst, cur, res);
		cur.pop_back();
	}
}
vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
	int n = graph.size();
	vector<vector<int>>res;
	backtrack(graph, 0, n - 1, { 0 }, res);
	return res;
}