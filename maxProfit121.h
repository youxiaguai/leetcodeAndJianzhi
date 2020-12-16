#pragma once
#include "common.h"
int maxProfit(vector<int>& prices) {
	int inf = INT_MAX;
	int minprice = inf;
	int maxpro = 0;
	for (int n : prices)
	{
		maxpro = max(maxpro, n - minprice);
		minprice = min(minprice, n);
	}
	return maxpro;
}