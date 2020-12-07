#pragma once
#include "common.h"
void add(vector<vector<int>>& res, int& R, int& C, int& x, int& y)
{
	if (x < 0 || x >= R || y < 0 || y >= C)
	{
		return;
	}
	res.push_back({ x,y });
}
vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {
	vector<vector<int>>res;
	vector<int>temp;
	int step = 1;
	while (res.size()<R*C)
	{
		for (int i = 0; i < step; i++)
		{
			add(res,R, C, r0, c0);
			c0++;
		}
		
		for (int j = 0; j<step; j++)
		{
			add(res, R, C, r0, c0);
			r0++;
		}
		step++;
		for (int k = 0; k < step; k++)
		{
			add(res, R, C, r0, c0);
			c0--;
		}
		for (int l = 0; l < step; l++)
		{
			add(res, R, C, r0, c0);
			r0--;
		}
		step++;
	}
	return res;

}