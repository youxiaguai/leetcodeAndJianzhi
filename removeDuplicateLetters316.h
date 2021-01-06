#pragma once
#include <map>
#include <stack>
#include "common.h"
string removeDuplicateLetters(string s) {
	unordered_map<char, int>index;//记录每个字母最后出现的下标
	unordered_map<char, bool>iscount;//记录每个字符是否出现过
	for (int i=0;i<s.size();i++)
	{
		index[s[i]]=i;
	}
	stack<char>st;//
	string result;
	for (int i = 0; i < s.size(); i++)
	{
		if (iscount[s[i]])continue;

		while (!st.empty() && st.top() > s[i]&&index[st.top()]>i)
		{
			iscount[s[i]] = false;
			st.pop();
		}
		iscount[s[i]] = true;
		st.push(s[i]);
	}
	while (!st.empty())
	{
		result = st.top()+result;
		st.pop();
	}
	return result;
}