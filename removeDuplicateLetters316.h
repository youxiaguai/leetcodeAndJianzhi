#pragma once
#include <map>
#include <stack>
#include "common.h"
string removeDuplicateLetters(string s) {
	unordered_map<char, int>index;//��¼ÿ����ĸ�����ֵ��±�
	unordered_map<char, bool>iscount;//��¼ÿ���ַ��Ƿ���ֹ�
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