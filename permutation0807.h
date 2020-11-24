#pragma once
#include "common.h"
vector<string> permutation(string S) {
	sort(S.begin(), S.end());
	vector<string>result;
	
	result.push_back(S);
	while (next_permutation(S.begin(), S.end())) {
		result.push_back(S);
	}
	

	
	
	
	return result;
}