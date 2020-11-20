#pragma once
#include "common.h"
int subtractProductAndSum(int n) {
	long long ji = 1;
	int sum = 0;
	int temp = n;
	while (n != 0)
	{
		temp=n % 10;
		ji *= temp;
		sum += temp;
		n /= 10;
	}
	int result = ji - sum;
	return result;
}