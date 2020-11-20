#pragma once
#include "common.h"
int numTeams(vector<int>& rating) {
	int n = rating.size();
	
	int result = 0;
	//iless*jmore+jless*imore即为结果
	for (int i = 1; i < n - 1; i++)
	{
		//找到中间值j,iless表示左边比j小的，imore表示左边比j大的
	int iless = 0, imore = 0;
	//jless表示右边比j小的，jmore表示右边比j大的
	int jless = 0, jmore = 0;
		for (int j = 0; j < i; j++)
		{
			if (rating[j] < rating[i])
			{
				++iless;
			}
			else if (rating[j] > rating[i])
			{
				++imore;
			}
		}
		for (int k = i + 1; k < n; k++)
		{
			if (rating[k] > rating[i])
			{
				++jmore;
			}
			else if (rating[k] < rating[i])
			{
				++jless;
			}
		}
		result += iless * jmore + jless * imore;
	}

	return result;

}