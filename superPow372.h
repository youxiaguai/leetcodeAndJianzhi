#pragma once
#include "common.h"
//求a的k次方
int base = 1337;
int mypow(int a, int k)
{
	if (k == 0)return 1;
	a %= base;
	if (k % 2 == 1)
	{
		return (a * mypow(a, k - 1)) % base;
	}
	else
	{
		int sub = mypow(a, k / 4);
		return (sub * sub) % base;
	}
	
}
int superPow(int a, vector<int>& b) {
	if (b.empty())return 1;
	int lat = b.back();
	b.pop_back();
	int part1 = mypow(a, lat);
	int part2 = mypow(superPow(a, b),10);
	return (part1 * part2) % base;

}