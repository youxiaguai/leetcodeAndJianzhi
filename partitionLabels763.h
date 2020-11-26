#pragma once
#include "common.h"

vector<int> partitionLabels(string S) {
	int last[26];
	int length = S.size();
	for (int i = 0; i < length; i++)
	{
		last[S[i] - 'a'] = i;
	}
	vector<int>res;
	int start = 0, end = 0;
	for (int i = 0; i < length; i++)
	{
		end = max(end, last[S[i] - 'a']);
		if (i == end)
		{
			res.push_back(end - start + 1);
			start = end - 1;
		}
	}
	return res;
}