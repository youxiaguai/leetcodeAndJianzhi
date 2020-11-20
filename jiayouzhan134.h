#pragma once
#include <iostream>
#include <vector>
using namespace std;


int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
	int n = gas.size();
	//��¼ÿ���ڵ���Ե������Զ����
	vector<int>farIndex(n, -1);
	//��¼������Զ����ʱ��ʣ��������
	vector<int>farRemain(n, 0);
	for (int i = 0; i < n; i++)
	{
		//j����i���Ե������Զ�ľ���
		int j = i;
		//Ŀǰ����ʣ����
		int remain = gas[i];
		
		while (remain >= cost[j])
		{
			//������һ���ص�
			
			remain =remain- cost[j];
			j = (j + 1) % n;
			//�ж�һ��֮ǰ��û���߹�����
			if (farIndex[j]!= -1)
			{
				//�߹����� ��ֱ����ת����ʱj���Ե���ĵط�
				remain = remain+farRemain[j];
				j = farIndex[j];
			}
			else
			{
				//���û���߹�������ϵ�ǰ�ڵ��������
				remain = remain + gas[j];
			}
			if (j == i)
			{
				//������ص���ԭ�㣬�򷵻�ԭ����±�
				return i;
			}
		}
		//��¼��������
		farIndex[i] = j;
		farRemain[i] = remain;
	}
	return -1;
}