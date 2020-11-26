#pragma once
#include "common.h"
#include <stack>
//vector<string>res;
bool valid(const string& str) {
	int balance = 0;
	for (char c : str) {
		if (c == '(') {
			++balance;
		}
		else {
			--balance;
		}
		if (balance < 0) {
			return false;
		}
	}
	return balance == 0;
}

void generate_all(string& current, int n, vector<string>& result) {
	if (n == current.size()) {
		if (valid(current)) {
			result.push_back(current);
		}
		return;
	}
	current += '(';
	generate_all(current, n, result);
	current.pop_back();
	current += ')';
	generate_all(current, n, result);
	current.pop_back();
}


vector<string> generateParenthesis(int n) {
	
	vector<string>res;
	string curr;
	generate_all(curr, n * 2, res);
	return res;
}


