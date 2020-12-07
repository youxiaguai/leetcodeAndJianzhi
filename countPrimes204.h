#pragma once
#include "common.h"
bool isPrime(int a)
{
	for (int i = 2; i*i <=a; i++)
	{
		if ( a % i == 0)
		{
			return false;
		}
	}
	return true;
}
int countPrimes(int n) {
	int ans = 0;
	for (int i = 2; i < n; i++)
	{
		ans += isPrime(i);
	}
	return ans;
}