#pragma once
#include "common.h"
#include "intervalSchedule.h"

int eraseOverlapIntervals(vector<vector<int>>& intervals) {
	int n = intervals.size();
	return n - intervalSchedule(intervals);
}