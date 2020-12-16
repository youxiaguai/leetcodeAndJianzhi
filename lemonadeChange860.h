#pragma once
#include "common.h"
bool lemonadeChange(vector<int>& bills) {
	int qian5 = 0, qian10 = 0, qian20 = 0;
	int n = bills.size();
	for (int i = 0; i < n; i++)
	{
		if (bills[i] == 5)
		{
			qian5++;
		}
		else if (bills[i] == 10)
		{
			
			if (qian5==0)
			{
				return false;
			}
			qian5--;
			qian10++;
		}
		else
		{
			
			if (qian10 > 0 && qian5 > 0)
			{

				qian10--;
				qian5--;
				break;
			}
			else if (qian5 > 2)
			{
				qian5 -= 3;
			}
			else
			{
				return false;
			}
		}
	}
	return true;
}