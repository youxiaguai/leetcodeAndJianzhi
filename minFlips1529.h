#pragma once
#include "common.h"
int minFlips(string target) {
	//�ӵ�һ��1��ʼ������������ͬ1��0�ĸ�����������0��1 ��һ��
	int res = 0;
	if (target[0] == '1')++res ;
	for (int i = 0; i < target.size()-1; i++)
	{
		if (target[i] != target[i + 1])
		{
			res++;
		}
	}
	return res;
}