#pragma once
#include "common.h"
vector<vector<string>> groupAnagrams(vector<string>& strs) {
	unordered_map<string, vector<string>>m;
	for (auto& s : strs)
	{
		string key = s;
		sort(key.begin(), key.end());
		m[key].emplace_back(s);
	}
	vector<vector<string>>res;
	for (auto it = m.begin(); it != m.end(); it++)
	{
		res.emplace_back(it->second);
	}
	return res;
}