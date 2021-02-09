#pragma once
#include "common.h"
void backtrack(int left, int right, vector<string>& res, string strack)
{
	if (left < 0 || right < 0)
	{
		return;
	}
	if (right < left)
	{
		return;
	}
	if (left == 0 && right == 0)
	{
		res.push_back(strack);
		return;
	}

	strack.push_back('(');
	backtrack(left - 1, right, res, strack);
	strack.pop_back();

	strack.push_back(')');
	backtrack(left, right - 1, res, strack);
	strack.pop_back();

}
vector<string> generateParenthesis(int n) {
	if (n == 0)return {};
	vector<string>res;
	string strack;
	backtrack(n, n, res, strack);
	return res;
}