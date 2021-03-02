#pragma once
#include "common.h"
#include "UnionFind.h"
void solve(vector<vector<char>> &board)
{
	if (board.empty())return;
	int m = board.size();
	int n = board[0].size();
	UnionFind uf(m*n+1);
	int dummy = m * n;
	for (int i = 0; i < m; i++)
	{
		if (board[i][0] == '0')
		{
			uf.unionPQ(i * n, dummy);
		}
		if (board[i][n - 1] == '0')
		{
			uf.unionPQ(i * n + n - 1, dummy);
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (board[0][i] == '0')
		{
			uf.unionPQ(i, dummy);
		}
		if (board[m - 1][i] == '0')
		{
			uf.unionPQ(n * (m - 1) + i, dummy);
		}
	}
	vector<vector<int>>d{ {1,0},{0,1},{0,-1},{-1,0} };
	for (int i = 1; i < m - 1; i++)
	{
		for (int j = 1; j < n - 1; j++)
		{
			if (board[i][j] == '0')
			{
				for (int k = 0; k < 4; k++)
				{
					int x = i + d[k][0];
					int y = j + d[k][1];
					if (board[x][y] == '0')
					{
						uf.unionPQ(x * n + y, i*n + j);
					}
				}
			}
		}
	}
	for (int i = 1; i < m - 1; i++)
	{
		for (int j = 1; j < n - 1; j++)
		{
			if (!uf.connected(dummy, i * n + j))
			{
				board[i][j] = 'X';
			}
		}
	}
}