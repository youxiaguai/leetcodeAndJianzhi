#pragma once
#include "common.h"
int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
	int result = 0;
	for (int i = 0; i < startTime.size(); i++)
	{
		if (startTime[i]<=queryTime&&endTime[i]>=queryTime)
		{
			result++;
		}
	}
	return result;
}
