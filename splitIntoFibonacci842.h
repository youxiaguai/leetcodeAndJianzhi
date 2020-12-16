#pragma once
#include "common.h"
vector<int> splitIntoFibonacci(string S) {
	vector<int>list;
	back(list, S, S.size(), 0, 0, 0);
	return list;
}
bool back(vector<int>& list, string S, int length, int index, long long sum, int prev)
{
	if (index == length)
	{
		return list.size() >= 3;
	}
	long long cur = 0;
	for (int i = index; i < length; i++)
	{
		if (i > index && S[index] == '0')
		{
			break;
		}
		cur = cur * 10 + S[i] - '0';
		if (cur > INT_MAX)
		{
			break;
		}
		if (list.size() >= 2)
		{
			if (cur < sum)
			{
				continue;
			}
			else if (cur > sum)
			{
				break;
			}
		}	 
		list.push_back(cur);
		if (back(list, S, length, i + 1, prev + cur, cur))
		{
			return true;
		}
		list.pop_back();
	}
	return false;
}