#pragma once
#include <set>
#include "common.h"
bool wordBreak(string s, vector<string>& wordDict) {
	unordered_set<string>st;
	for (auto& word : wordDict)
	{
		st.insert(word);
	}
	auto dp = vector<bool>(s.size() + 1);
	dp[0] = true;
	for (int i = 1; i <= s.size(); i++)
	{
		dp[0] = true;
		for (int j = 0; j < i; j++)
		{
			if (dp[j] && (st.find(s.substr(j, i - j)) != st.end()))
			{
				dp[i] = true;
				break;
			}
		}
	}
	return dp[s.size()];
	
}