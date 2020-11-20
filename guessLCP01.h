#pragma once
#include "common.h"
	int game(vector<int>& guess, vector<int>& answer) 
	{
		int result = 0;
		for (int i = 0; i < guess.size(); i++)
		{
			if (guess[i] == answer[i])
			{
				result++;
			}
		}
		return result;
	}