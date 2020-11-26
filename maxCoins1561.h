#pragma once
#include "common.h"
int maxCoins(vector<int>& piles) {
	//排序，除以3即需要取多少次，从前面取两个，从后面取一个
	//堆数
	int n = piles.size() / 3;
	sort(piles.begin(), piles.end());
	int result = 0;
	for (int i = n; i < piles.size(); i+=2)
	{
		result += piles[i];
	}
	return result;
}