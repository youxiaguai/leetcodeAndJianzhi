#pragma once
#include <queue>
#include "common.h"
vector<vector<int>>edges;
vector<int>indeg;

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
	edges.resize(numCourses);
	indeg.resize(numCourses);
	for (const auto& info : prerequisites)
	{
		edges[info[1]].push_back(info[0]);//边
		++indeg[info[0]];//顶点

	}
	queue<int>q;
	for (int i = 0; i < numCourses; i++)
	{
		if (indeg[i] == 0)//入度为0
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
		for (int v : edges[u])
		{
			--indeg[v];//去掉以u入的边
			if (indeg[v] == 0)
			{
				q.push(v);
			}
		}
	}
	return visited == numCourses;
}