#pragma once
#include "common.h"
#include <stack>
string removeOuterParentheses(string S) {
	string res = "";
	stack<char>st;
	for (int i = 0; i < S.size(); i++)
	{
		if (S[i] == ')')
		{
			st.pop();
		}
		if (!st.empty())
		{
			res += S[i];
		}
		if (S[i] == '(')
		{
			st.push('(');
		}
	}
	return res;
}