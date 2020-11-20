#pragma once
#include <iostream>
#include <vector>
using namespace std;


int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
	int n = gas.size();
	//记录每个节点可以到达的最远距离
	vector<int>farIndex(n, -1);
	//记录到达最远距离时的剩余汽油量
	vector<int>farRemain(n, 0);
	for (int i = 0; i < n; i++)
	{
		//j代表i可以到达的最远的距离
		int j = i;
		//目前汽油剩余量
		int remain = gas[i];
		
		while (remain >= cost[j])
		{
			//进入下一个地点
			
			remain =remain- cost[j];
			j = (j + 1) % n;
			//判断一下之前有没有走过这里
			if (farIndex[j]!= -1)
			{
				//走过这里 则直接跳转到此时j可以到达的地方
				remain = remain+farRemain[j];
				j = farIndex[j];
			}
			else
			{
				//如果没有走过，则加上当前节点的汽油量
				remain = remain + gas[j];
			}
			if (j == i)
			{
				//如果返回到了原点，则返回原点的下标
				return i;
			}
		}
		//记录到哪里了
		farIndex[i] = j;
		farRemain[i] = remain;
	}
	return -1;
}