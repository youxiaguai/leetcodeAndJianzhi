#pragma once
#include "common.h"
int minFlips(string target) {
	//从第一个1开始，往后数，不同1与0的个数，连续的0与1 算一个
	int res = 0;
	if (target[0] == '1')++res ;
	for (int i = 0; i < target.size()-1; i++)
	{
		if (target[i] != target[i + 1])
		{
			res++;
		}
	}
	return res;
}