#pragma once
#include "common.h"
int calculate(string s) {
	int x = 1, y = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i]=='A')
		{
			x = x * 2 + y;
		}
		else if (s[i] == 'B')
		{
			y = y * 2 + x;
		}
	}
	return x + y;
}