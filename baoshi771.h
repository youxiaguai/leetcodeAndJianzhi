#pragma once
#include "common.h"
int numJewelsInStones(string J, string S) {
	int result=0;
	//��J�е�Ԫ�طŵ�unordered_set��
	unordered_set<char>Jset;
	for (int i = 0; i < J.size(); i++)
	{
		Jset.insert(J[i]);
	}

	for (int i = 0; i < S.size(); i++)
	{
		if (Jset.find(S[i]) != Jset.end())
		{
			result++;
		}
	}
	return result;

}