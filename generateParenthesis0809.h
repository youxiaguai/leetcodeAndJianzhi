#pragma once
#include "common.h"
//left表示可使用的左括号数，right表示可使用的右括号数
void backtrack(vector<string>& res, int left, int right, string track)
{
	if (!right && !left) res.push_back(track);
	else
	{
		//使用一个左括号，同时可使用右括号数加一，避免生成无效括号
		if (left > 0) backtrack(res, left - 1, right + 1, track + '(');
		//可使用的右括号大于0，则用来补齐原来的左括号
		if (right > 0) backtrack(res, left, right - 1, track + ')');
	}
}
vector<string> generateParenthesis(int n) {
	vector<string> res;
	backtrack(res, n, 0, "");
	return res;
}