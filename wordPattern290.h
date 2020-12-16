#pragma once
#include "common.h"
bool wordPattern(string pattern, string s) {
	int n = pattern.size();
	unordered_map<char, string>paToS;
	unordered_map<string, char>sTochar;
	int m = s.size();
	int i = 0;
	for (auto ch : pattern)
	{
		if (i >= m)
		{
			return false;
		}
		int j = i;
		while (j < m && s[j] != ' ')j++;
		const string &tmp = s.substr(i, j - i);
		if (sTochar.count(tmp) && sTochar[tmp] != ch)
		{
			return false;
		}
		if (paToS.count(ch) && paToS[ch] != tmp)
		{
			return false;
		}
		paToS[ch] = tmp;
		sTochar[tmp] = ch;
		i = j + 1;
		
	}
	return i >= m;
}