#pragma once
#include "common.h"
#include <set>
bool isAnagram(string s, string t) {
	if (s.size() != t.size())
	{
		return false;
	}
	vector<int>table(26, 0);
	for (auto& ch : s)
	{
		table[ch - 'a']++;
	}
	for (auto& ch : t)
	{
		table[ch - 'a']--;
		if (table[ch - 'a'] < 0)
		{
			return false;
		}
	}
	return true;
}