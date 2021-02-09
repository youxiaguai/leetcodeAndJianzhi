#pragma once
#include <set>
#include "common.h"
vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
	unordered_map<string, set<string>> account;
	int n = accounts.size();
	
	for (int i = 0; i < n; i++)
	{
		int m = accounts[i].size();
		set<string>st;
		for (int j = 1; j < m; j++)
		{
			
			st.insert(accounts[i][j]);
			account[accounts[i][0]] = st;
		}
		
	}
	for (int i = 0; i < n; i++)
	{
		if(account[i][0])
	}
}	