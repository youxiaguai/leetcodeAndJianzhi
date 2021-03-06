#pragma once
#include "common.h"
int get(vector<vector<int>>& mat, int m, int n, int x, int y)
{
	x = max(min(x, m), 0);
	y = max(min(y, n), 0);
	return mat[x][y];
}
vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
	int m = mat.size();
	int n = mat[0].size();
	vector<vector<int>>preSum(m + 1, vector<int>(n + 1));
	for (int i = 1; i < m + 1; i++)
	{
		for (int j = 1; j < n + 1; j++)
		{
			preSum[i][j] = preSum[i - 1][j] + preSum[i][j - 1] - preSum[i - 1][j - 1] + mat[i - 1][j - 1];
		}
	}
	vector<vector<int>>res(m, vector<int>(n));
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			res[i][j] = get(preSum, m, n, i + K + 1, j + K + 1) - get(preSum, m, n, i - K, j +K + 1) - get(preSum, m, n, i +K + 1, j - K) + get(preSum, m, n, i - K , j - K);
		}
	}
	return res;
}