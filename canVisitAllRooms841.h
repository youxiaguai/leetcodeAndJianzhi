#pragma once
#include <set>
#include "common.h"
int num;
vector<int>vis;
bool canVisitAllRooms(vector<vector<int>>& rooms) {
	/*set<int>s;
	for (int i = 0; i < rooms[0].size(); i++)
	{
		s.insert(rooms[0][i]);
	}
	
	
	for (int i = 1; i < rooms.size(); i++)
	{
		if (s.find(i) != s.end())
		{
			for (int j = 0; j < rooms[i].size(); j++)
			{
				s.insert(rooms[i][j]);
			}
		}
	}
	for (int i = 1; i < rooms.size(); i++)
	{
		if (s.find(i) == s.end())
		{
			return false;
		}
	}
	return true;*/
	int n = rooms.size();
	int num = 0;
	vector<int>vis;
	vis.resize(n);
	dfs(0, rooms);
	return num == n;
}
void dfs( int x,vector<vector<int>>&rooms)
{
	vis[x] = true;
	num++;
	for (auto& it : rooms[x])
	{
		if (!vis[it])
		{
			dfs(it, rooms);
		}
	}
}