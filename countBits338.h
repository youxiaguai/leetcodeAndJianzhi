#pragma once
#include "common.h"
vector<int> countBits(int num) {
	vector<int>result(num + 1, 0);
	for (int i = 1; i <num; i++)
	{
		result[i] = result[i > 2] + (i % 2);
	}
	for (int k = 1; k <= num; k++) {
		result[k] = result[k >> 1] + (k & 1);
	}

	
	return result;
}