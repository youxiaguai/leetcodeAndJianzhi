#pragma once
#include "common.h"
#include <sstream>
bool dp(string& s, int i, string& p, int j)
{
	unordered_map<string, bool>memo;
	int n = s.size();
	int m = p.size();
	if (j == m)
	{
		return i == n;
	}
	if (i == n)
	{
		//最后剩的冒单为false
		if ((m - j) % 2 == 1)
		{
			return false;
		}
		for (; j + 1 < m; j += 2)
		{
			if (p[j + 1] != '*')
			{
				return false;
			}
		}
		return true;
	}
	string key = std::to_string(i) + "," + to_string(j);

	if (memo.count(key))
		return memo[key];
	bool res = false;
	if (s[i] == p[j] || p[j] == '.')
	{
		res = dp(s, i, p, j + 1)
			|| dp(s, i + 1, p, j + 1);
	}
	else
	{
		if (j < m - 1 && p[j + 1] == '*')
		{
			res = dp(s, i, p, j + 1);
		}
		else
		{
			res = false;
		}
	}
	memo[key] = res;
	return res;
}
bool isMatch(string s, string p) {
	return dp(s, 0, p, 0);
}