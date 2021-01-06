#pragma once
#include <set>
#include "common.h"
int firstUniqChar(string s) {
	unordered_map<char,int>se;
	int result = 0;
	for (int i = 0; i < s.size(); i++)
	{
		se[s[i]]++;
	}
	for (int i = 0; i < s.size(); i++)
	{
		if (se[s[i]] == 1)
		{
			
			return i;
		}
	}
	return 0;
}