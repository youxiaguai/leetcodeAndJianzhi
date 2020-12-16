#pragma once
#include "common.h"
int monotoneIncreasingDigits(int N) {
	int res = N;
	int index = 1;
	while (index<=N/10)
	{
		int num = res / index % 100;
		index *= 10;
		if (num / 10 > num % 10)
		{
			res = res / index * index - 1;
		}

	}
	return res;
}