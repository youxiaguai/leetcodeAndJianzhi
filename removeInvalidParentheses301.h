#pragma once
#include "common.h"
#include <set>
unordered_set<string>ans;
void dfs(string&s,int index,string res,int left,int right,int cnt)
{
	if (index == s.size())
	{
		if (!cnt) ans.insert(res);
		return;
	}
	if (s[index] == '(')
	{
		dfs(s, index + 1, res + '(', left + 1, right, cnt + 1);//��ɾ
		if (left > 1) dfs(s, index + 1, res, left - 1, right, cnt);//ɾ����ǰ������
	}
	else if (s[index] == ')')
	{
		if (cnt > 0)dfs(s, index + 1, res + ')', left, right, cnt - 1);//��ɾ
		if (right > 0) dfs(s, index + 1, res, left, right - 1, cnt);//ɾ����ǰ������
	}
	else dfs(s, index + 1, res + s[index], cnt, left, right);
}
vector<string> removeInvalidParentheses(string s) {
	int left = 0, right = 0;
	for (auto v : s)
	{
		if (v == '(')left++;
		else if (v == ')') {
			if (left <= 0)right++;
			else
			{
				left--;
			}
		}
	}
	dfs(s, 0, "", left, right, 0);
	vector<string>res;
	for (auto v : ans)res.push_back(v);
	return res;
}