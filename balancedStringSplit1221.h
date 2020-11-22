#pragma once
#include "common.h"
int balancedStringSplit(string s) {
	int num = 0;
	int n = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == 'R')
		{
			n++;
		}
		if (s[i] == 'L')
		{
			n--;
		}
		if (n == 0)
		{
			num++;
		}
	}
	return num;
}