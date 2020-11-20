#pragma once
#include "common.h"
#include <stack>
int maxDepth(string s) {
	stack<char>cs;
	int depth = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '(')
		{
			cs.push(s[i]);
			

		}
		else if (s[i] == ')')
		{
			depth = max(depth, (int)cs.size());
			cs.pop();
		}
	}
	return depth;
}