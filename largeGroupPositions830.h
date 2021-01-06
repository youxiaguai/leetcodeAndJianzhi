#pragma once
#include "common.h"
vector<vector<int>> largeGroupPositions(string s) {
	int n = s.size();
	vector<vector<int>>result;
	int num = 0;
	for (int i = 0; i < n; i++)
	{
		if (i == n - 1 || s[i] != s[i + 1])
		{
			if (num >= 3)
			{
				result.push_back({ i - num + 1,i });
			}
			num = 1;
		}
		else
		{
			num++;
		}
	}
	return result;
}