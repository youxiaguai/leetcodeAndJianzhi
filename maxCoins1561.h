#pragma once
#include "common.h"
int maxCoins(vector<int>& piles) {
	//���򣬳���3����Ҫȡ���ٴΣ���ǰ��ȡ�������Ӻ���ȡһ��
	//����
	int n = piles.size() / 3;
	sort(piles.begin(), piles.end());
	int result = 0;
	for (int i = n; i < piles.size(); i+=2)
	{
		result += piles[i];
	}
	return result;
}