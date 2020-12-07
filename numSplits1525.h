#pragma once
#include <bitset>
#include "common.h"
int numSplits(string s) {
	int result = 0;
	int n = s.length();
	vector<int>left(n + 1), right(n + 2);
	bitset<26>rec_left, rec_right;
	for (int i = 1; i <= n; i++)
	{
		int c = s[i - 1] - 'a';
		if (rec_left.test(c))
		{
			left[i] = left[i - 1];
		}
		else
		{
			rec_left.set(c);
			left[i] = left[i - 1] + 1;
		}
	}
	for (int i = n; i > 0; i--)
	{
		int c = s[i - 1] - 'a';
		if (rec_right.test(c))
		{
			right[i] = right[i + 1];
		}
		else
		{
			rec_right.set(c);
			right[i] = right[i + 1] + 1;
		}
	}
	int res = 0;
	for (int i = 1; i < n; i++)
	{
		if (left[i] == right[i+1])
		{
			res++;
		}
	}
	return res;

}