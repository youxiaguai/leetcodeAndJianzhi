#pragma once
#include "common.h"
vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
	vector<vector<int>>res;
	int n = A.size();
	int m = B.size();
	int i = 0, j = 0;
	if (n == 0 || m == 0)
	{
		return res;
	}
	while (i<n&&j<m)
	{
		if (A[i][0] <= B[j][0])
		{
			if (A[i][1] < B[i][0])
			{
				i++;
				continue;
			}
			else
			{
				res.push_back(vector<int>({ B[j][0],min(B[j][1],A[i][1]) }));
				if (A[i][1] == B[j][1])
				{
					i++;
					j++;
				}
				else if (A[i][1] < B[j][1])
				{
					i++;
				}
				else
				{
					j++;
				}
					
			}
		}
		else
		{
			if (B[j][1] < A[i][0])
			{
				j++;
				continue;
			}
			else
			{
				res.push_back(vector<int>({ A[i][0],min(B[j][1],A[i][1]) }));
				if (B[j][1] == A[i][1])
				{
					i++;
					j++;
				}
				else if (B[j][1] < A[i][1])
				{
					j++;
				}
				else
				{
					i++;
				}
			}
		}
	}	
	return res;
}