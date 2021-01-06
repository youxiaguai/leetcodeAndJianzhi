#pragma once
#include "common.h"
void dfs(vector<vector<char>>& grid, int l, int r)
{
	int m = grid.size();
	int n = grid[0].size();
	grid[l][r] = '0';
	if (l - 1 >= 0 && grid[l - 1][r] == '1')dfs(grid, l - 1, r);
	if (l + 1 < m && grid[l][r + 1] == '1')dfs(grid, l+1, r );
	if (r - 1 >= 0 && grid[l][r - 1] == '1')dfs(grid, l, r - 1);
	if (r + 1 < n && grid[l][r + 1] == '1')dfs(grid, l, r + 1);
}
int numIslands(vector<vector<char>>& grid) {
	int m = grid.size();
	if (!m) {
		return 0;
	}
	int n = grid[0].size();
	int num_lans = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (grid[i][j] == '1')
			{
				num_lans++;
				dfs(grid, i, j);
			}
		}
	}
	return num_lans;
}