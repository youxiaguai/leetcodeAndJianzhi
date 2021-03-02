#pragma once
#include <algorithm>
#include "common.h"
//速度speed吃H个小时可不可以吃完
bool canFinsh(vector<int>& piles,int speed,int H)
{
	int time = 0;
	for (auto n : piles)
	{
		time += timeOf(speed, n);
	}
	
	return time <= H;
}
//以speed的速度吃n个需要多长时间
int timeOf(int speed, int n)
{

	
	return	(n / speed) + ((n % speed > 0) ? 1 : 0);
	
	
}
int minEatingSpeed(vector<int>& piles, int H) {
	int n = piles.size();
	//找到从1到piles最大中的可以满足条件最小的一个数
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