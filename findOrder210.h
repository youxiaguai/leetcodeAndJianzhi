#pragma once
#include <queue>
#include "common.h"
vector<vector<int>>edges;
vector<int>indeg;
vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
	edges.resize(numCourses);
	indeg.resize(numCourses);
	vector<int>result;
	for (const auto& info : prerequisites)
	{
		edges[info[1]].push_back(info[0]);
		++indeg[info[0]];
	}
	queue<int>q;
	for (int i = 0; i < numCourses; i++)
	{
		if (indeg[i] == 0)
		{
			q.push(i);
		}
	}
	int visited = 0;
	while (!q.empty())
	{
		++visited;
		int u = q.front();
		q.pop();
		result.push_back(u);
		for (int v : edges[u])
		{
			--indeg[u];
			if (indeg[v] == 0)
			{
				q.push(v);
			}
		}
		
	}
	if (result.size() != numCourses)
	{
		return {};
	}
	return result;
}