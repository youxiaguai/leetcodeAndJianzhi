#pragma once
#include "common.h"
int matrixScore(vector<vector<int>>& A) {
	//先翻转行保证第一位都是1，再翻转列，尽可能的得到列1个数多
	int col = A.size();//行
	int row = A[0].size();//列
	for (int i = 0; i < col; i++)
	{
		//行反转的条件，每行中第一个不为1，翻转这一行
		if (A[i][0] == 0)
		{
			int index = 0;
			while (index<row)
			{
				A[i][index] ^= 1;
				index++;
			}
		}
	}
	int sum = col * pow(2, row - 1);//将最高一位加起来
	//再看每一列,每一列反转的条件为1的个数少于行数的一半
	for (int i = 1; i < row; i++)
	{
		int count = 0;
		for (int j = 0; j < col; j++)
		{
			
			if (A[j][i] == 1)
			{
				count++;
				
			}
			
			
		}
		if (count <= col / 2)
		{
			count = col - count;
		}
		sum += count * pow(2, row-i-1);
		
	}
	return sum;
}