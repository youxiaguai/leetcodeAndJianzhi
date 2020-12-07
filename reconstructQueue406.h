#pragma once
#include "common.h"

vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
	sort(people.begin(), people.end(), [](const vector<int>& u, const vector<int>& v)
	{
		return u[0] < v[0] || (u[0] == v[0] && u[1] > v[1]);//身高不同，按身高降序排序，身高相同，按个数升序排序
	});
	int n = people.size();
	vector<vector<int>>ans(n);
	for (const vector<int>& people : people)
	{
		int spaces = people[1] + 1;
		for (int i = 0; i < n; i++)
		{
			if (ans[i].empty())
			{
				--spaces;
				if (!spaces)
				{
					ans[i] = people;
					break;
				}
			}
		}
		
	}
	return ans;
}