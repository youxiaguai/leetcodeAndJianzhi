#pragma once
#include "common.h"
string restoreString(string s, vector<int>& indices) {
	string result(indices.size(), 0);
	for (int i = 0; i < indices.size(); i++)
	{
		result[indices[i]] = s[i];
	}
	
	return result;
}