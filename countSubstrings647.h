#pragma once
#include "common.h"
bool isP(string s, int begin, int end)
{
	while (begin<end)
	{
		if (s[begin] != s[end])
		{
			return false;
		}
		else
		{
			begin++;
			end--;

		}
	}
	return true;
}
int countSubstrings(string s) {
	
	int n = s.size();
	int result = 0;
	for (int i = 0; i < 2 * n - 1; i++)
	{
		int l = i / 2,r=i/2+i%2;
		while (l>=0&&r<n&&s[l]==s[r])
		{
			--l;
			++r;
			++result;
		}
	}
	return result;
	
}