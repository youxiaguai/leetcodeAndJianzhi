#pragma once
#include "common.h"
int maximalSquare(vector<vector<char>>& matrix) {
	/*int m = matrix.size();
	int n = matrix[0].size();
	if (m == 0 || n == 0)
	{
		return 0;
	}
	int maxlong = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (matrix[i][j] = '1')
			{
				maxlong = min(maxlong, 1);
				int curr = min(m - i, n - j);
				for (int k = 0; k < curr; k++)
				{
					bool flag = true;
					if (matrix[i + k][j + k] == '0')
					{
						break;
					}
					for (int m = 0; m < k; m++)
					{
						if (matrix[i + k][j + m] == '0' || matrix[i + m][j + k] == '0')
						{
							flag = false;
							break;
						}
					}
					if (flag)
					{
						maxlong = max(maxlong, k + 1);
					}
					else
					{
						break;
					}
				}
			}


		}
	}
	int result = maxlong * maxlong;
	return result;
}*/
//动态规划
	int m = matrix.size();
	int n = matrix[0].size();
	if (m == 0 || n == 0)
	{
		return 0;
	}
	//dp[i][j]表示以i，j为右下角的最大只含1的正方形个数
	vector<vector<int>>dp(m, vector<int>(n, 0));
	
	int maxSize = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (matrix[i][j] == '1')
			{
				if (i == 0 || j == 0)
				{
					dp[i][j] = 1;
				}
				else
				{
					dp[i][j] = min(dp[i - 1][j], min(dp[i - 1][j - 1], dp[i][j - 1])) + 1;

				}
				maxSize = max(maxSize, dp[i][j]);
			}
			
		}
	}
	int result = maxSize * maxSize;
	return result;

}