#pragma once
#include <algorithm>
#include "common.h"
//�ٶ�speed��H��Сʱ�ɲ����Գ���
bool canFinsh(vector<int>& piles,int speed,int H)
{
	int time = 0;
	for (auto n : piles)
	{
		time += timeOf(speed, n);
	}
	
	return time <= H;
}
//��speed���ٶȳ�n����Ҫ�೤ʱ��
int timeOf(int speed, int n)
{

	
	return	(n / speed) + ((n % speed > 0) ? 1 : 0);
	
	
}
int minEatingSpeed(vector<int>& piles, int H) {
	int n = piles.size();
	//�ҵ���1��piles����еĿ�������������С��һ����
	vector<int>::iterator iter = piles.begin();
	int maxx = *max_element(iter,iter+n);
	int left = 1, right = maxx;
	int mid = left + (right - left) / 2;
	while (left<right)
	{
		if (canFinsh(piles,mid,H))
		{
			right = mid;
		}
		else
		{
			left = mid+1;
		}
		
	}
	return left;
}