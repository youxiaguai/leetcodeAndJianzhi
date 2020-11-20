#pragma once
#include "common.h"
int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
	//找出一行中的最大值，存在col数组中。以及一列中的最大值，存在row数组中
	int n = grid.size();
	int m = grid[0].size();
	vector<int>col(n, 0);
	vector<int>row(m, 0);
	
	for (int i = 0; i < n; i++)
	{	
		row[i] = grid[i][0];
		
		
		for (int j = 0; j < m; j++)
		{
			if (grid[i][j] > row[i])
			{
				row[i] = grid[i][j];
			}
		}
		
	}
	
	
	for (int i = 0; i < m; i++)
	{
		col[i] = grid[0][i];
		for (int j = 0; j < n; j++)
		{
			if (grid[j][i] > col[i])
			{
				col[i] = grid[j][i];
			}
			
		}
	}
	int result=0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			result += min(col[i], row[j]) - grid[i][j];
		}
	}
	return result;
}
