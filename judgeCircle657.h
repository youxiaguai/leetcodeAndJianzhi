#pragma once
#include "common.h"
bool judgeCircle(string moves) {
	//判断上下和左右的个数最后是否抵消
	int left = 0, right = 0, up = 0, down = 0;
	for (int i = 0; i < moves.size(); i++)
	{
		if (moves[i] == 'L')
		{
			left++;
		}
		else if (moves[i] == 'R')
		{
			right++;
		}
		else if (moves[i] == 'U')
		{
			up++;
		}
		else if (moves[i] == 'D')
		{
			down++;
		}
	}
	return ((abs(left - right) == 0) && (abs(up - down) == 0));
}