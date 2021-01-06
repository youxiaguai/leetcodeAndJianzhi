#pragma once
#include "common.h"
//bool searchMatrix(vector<vector<int>>& matrix, int target) {
//	int m = matrix.size();
//	int n = matrix[0].size();
//
//	if (m == 0 || n == 0)
//	{
//		return false;
//	}
//	int row = 0, col = n - 1;
//	while (row<m&&col>=0)
//	{
//		if (target > matrix[row][col])
//		{
//			row++;
//		}
//		else if (target < matrix[row][col])
//		{
//			col--;
//		}
//		else if (target == matrix[row][col])
//		{
//			return true;
//		}
//	}
//	return false;
//}
//¶þ·Ö·¨
bool binarySearch(vector<vector<int>>& matrix, int i, int target)
{
	int left = 0, right = matrix[0].size() - 1;
	while (left<=right)
	{
		int mid = left + (right - left) / 2;
		if (matrix[i][mid] < target)
		{
			left = mid + 1;
		}
		else if (matrix[i][mid] > target)
		{
			right = mid - 1;
		}
		else
		{
			return true;
		}
	}
	return false;
}
bool searchMatrix(vector<vector<int>>& matrix, int target) {
	int m = matrix.size();
	int n = matrix[0].size();
	for (int i = 0; i < m; i++)
	{

		if (binarySearch(matrix, i, target))
		{
			return true;
		}
	}
	return false;
}