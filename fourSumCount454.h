#pragma once
#include "common.h"
int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
	unordered_map<int, int>coutAB;
	for (auto a : A)
	{
		for (auto b : B)
		{
			++coutAB[a + b];
		}
	}
	int ans = 0;
	for (auto c : C)
	{
		for (auto d : D)
		{
			if (coutAB.count(-c - d))
			{
				ans += coutAB[-c - d];
			}
		}
	}
	return ans;
}