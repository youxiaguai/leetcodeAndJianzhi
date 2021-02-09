#pragma once
#include "common.h"
#include <queue>
int slidingPuzzle(vector<vector<int>>& board) {
	int m = 2, n = 3;
	string start = "";
	string target = "123450";
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			start.push_back(board[i][j] + '0');
		}
	}
	vector<vector<int>>neighbor = {
		{1,3},
		{0,4,2},
		{1,5},
		{0,4},
		{3,1,5},
		{4,2}
	};

	queue<string>q;
	unordered_set<string>visited;
	q.push(start);
	visited.insert(start);

	int step = 0;
	while (!q.empty())
	{
		int size = q.size();
		for (int i = 0; i < size; i++)
		{
			string cur = q.front();
			q.pop();

			if (target == cur)
			{
				return step;
			}
			
			for (int idx = 0; cur[idx] != '0'; idx++)
			{
				for (int adj : neighbor[idx])
				{
					string new_board = cur;
					swap(new_board[adj], new_board[idx]);
					if (!visited.count(new_board))
					{
						q.push(new_board);
						visited.insert(new_board);
					}
				}
				

			}
			
			
		}
		step ++;
		
	}
	return -1;
}