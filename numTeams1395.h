#pragma once
#include "common.h"
int numTeams(vector<int>& rating) {
	int n = rating.size();
	
	int result = 0;
	//iless*jmore+jless*imore��Ϊ���
	for (int i = 1; i < n - 1; i++)
	{
		//�ҵ��м�ֵj,iless��ʾ��߱�jС�ģ�imore��ʾ��߱�j���
	int iless = 0, imore = 0;
	//jless��ʾ�ұ߱�jС�ģ�jmore��ʾ�ұ߱�j���
	int jless = 0, jmore = 0;
		for (int j = 0; j < i; j++)
		{
			if (rating[j] < rating[i])
			{
				++iless;
			}
			else if (rating[j] > rating[i])
			{
				++imore;
			}
		}
		for (int k = i + 1; k < n; k++)
		{
			if (rating[k] > rating[i])
			{
				++jmore;
			}
			else if (rating[k] < rating[i])
			{
				++jless;
			}
		}
		result += iless * jmore + jless * imore;
	}

	return result;

}