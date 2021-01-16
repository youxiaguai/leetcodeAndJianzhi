#pragma once
#include "common.h"
void dfs(vector<vector<int>>& isConnected, vector<int>& isVisit, int provinces, int j)
{
	for (int i = 0; i < provinces; i++)
	{
		if (!isVisit[i] && isConnected[j][i] == 1)
		{
			isVisit[i] = 1;
			dfs(isConnected, isVisit, provinces, i);
		}
	}
}
int findCircleNum(vector<vector<int>>& isConnected) {
	int provinces = isConnected.size();
	vector<int>isVisit(provinces);

	int circles = 0;
	for (int i = 0; i < provinces; i++)
	{
		if (!isVisit[i])
		{
			dfs(isConnected, isVisit, provinces, i);
			circles++;
		}
	}
	return circles;
}