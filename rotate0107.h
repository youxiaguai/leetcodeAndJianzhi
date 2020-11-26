#pragma once
#include "common.h"
void rotate(vector<vector<int>>& matrix) {
	int n = matrix.size();
	//ˮƽ��ת
	for (int i = 0; i <n/2; i++)
	{
		for (int j = 0; j <n; j++)
		{
			swap(matrix[i][j], matrix[n - i - 1][j]);
		}
	}
	//���Խ��߷�ת
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			swap(matrix[i][j], matrix[j][i]);
		}
	}
}