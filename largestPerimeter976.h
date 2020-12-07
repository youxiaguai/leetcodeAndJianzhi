#pragma once
#include "common.h"
bool isT(int a, int b, int c)
{
	if (a + b < c)
	{
		return false;
	}
	else if (b + c < a)
	{
		return false;
	}
	else if (a + c < b)
	{
		return false;
	}

	return true;
}
int largestPerimeter(vector<int>& A) {
	sort(A.begin(), A.end());
	int n = A.size();
	for (int i = n - 3; i >= 0; i--)
	{
		if (isT(A[i], A[i + 1], A[i + 2]))
		{
			return A[i] + A[i + 1] + A[i + 2];
		}
		
	}
	return 0;
}