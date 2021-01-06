#pragma once
#include <set>
#include "common.h"
vector<int> findAnagrams(string s, string p) {
	unordered_set<char>st;
	for (int i = 0; i < p.size(); i++)
	{
		st.insert(p[i]);
	}
	int n = s.size(), l = p.size();
	vector<int>key(26, 0), freq(26, 0), res;
	for (char c : p)
	{
		key[c - 'a']++;
	}
	for (int i = 0; i < n; i++)
	{
		if (i >= 1)
		{
			freq[s[i - 1] - 'a']--;
		}
		freq[s[i] - 'a']++;
		if (freq == key)
		{
			res.push_back(i + 1 - l);
		}
	}
	return res;
}