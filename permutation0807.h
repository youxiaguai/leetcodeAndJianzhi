#pragma once
#include "common.h"
vector<string> permutation(string S) {
	sort(S.begin(), S.end());
	vector<string>result;
	vector<string>result1;
	result.push_back(S);
	while (next_permutation(S.begin(), S.end())) {
		result.push_back(S);
	}
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << ",";
	}
	cout << endl;
	result1.push_back(S);
	
	while (prev_permutation(S.begin(), S.end())) {
		result1.push_back(S);
	}
	for (int i = 0; i < result1.size(); i++)
	{
		cout << result1[i] << ",";
	}
	return result;
}