#pragma once
#include "common.h"
bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
	//判断pieces每个数组的相对顺序是否和arr中相同
	unordered_map<int, int> ump;
	for (int i = 0; i < pieces.size(); ++i) {
		ump[pieces[i][0]] = i;
	}
	int i = 0;
	while (i < arr.size()) {
		int k = ump[arr[i]];
		for (int j = 0; j < pieces[k].size(); ++j) {
			if (arr[i] != pieces[k][j]) return false;
			i++;
		}
	}
	return true;
}