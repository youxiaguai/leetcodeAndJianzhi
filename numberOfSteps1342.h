#pragma once
#include "common.h"
int times = 0;
int numberOfSteps(int num) 
{
	while (num != 0)
	{
		if (num % 2 == 1)
		{
			num -= 1;
			times++;
		}
		else if (num % 2 == 0)
		{
			num /= 2;
			times++;
		}
	}
	return times;
}