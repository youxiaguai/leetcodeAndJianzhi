#pragma once
#include "common.h"
int minSteps(string s, string t) {
	int result = 0;
	//记录t中的字母及出现次数
	vector<int>tv(26,0);
	for (int i = 0; i < t.size(); i++)
	{
		tv[t[i]-'a']++;
	}
	//记录s中的字母及出现次数
	vector<int>sv(26, 0);
	for (int i = 0; i < s.size(); i++)
	{
		sv[s[i]-'a']++;
	}
	//把s中出现的字母及其次数去掉剩下的t中的个数
	for (int i = 0; i != 26; i++)
	{
		if (sv[i] < tv[i])
		{
			result += tv[i] - sv[i];
		}
	}
	return result;

}