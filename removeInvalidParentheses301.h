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
		dfs(s, index + 1, res + '(', left + 1, right, cnt + 1);//²»É¾
		if (left > 1) dfs(s, index + 1, res, left - 1, right, cnt);//É¾³ýµ±Ç°×óÀ¨ºÅ
	}
	else if (s[index] == ')')
	{
		if (cnt > 0)dfs(s, index + 1, res + ')', left, right, cnt - 1);//²»É¾
		if (right > 0) dfs(s, index + 1, res, left, right - 1, cnt);//É¾³ýµ±Ç°ÓÒÀ¨ºÅ
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