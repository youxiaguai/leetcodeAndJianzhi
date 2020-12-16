#pragma once
#include "common.h"
vector<vector<string>> groupAnagrams(vector<string>& strs) {
	vector<vector<string>>result;
	unordered_map<string, vector<string>>m;
	//����ÿ��strs�е�ÿ�����ʽ����ж�
	for (auto i : strs)
	{
		string t = i;
		sort(t.begin(), t.end());
		auto it = m.find(t);
		if (it==m.end())
		{
			m.insert(pair<string, vector<string>>{t, { i }});
		}
		else
		{
			it->second.push_back(i);
		}
	}
	for (auto i : m)
	{
		result.push_back(i.second);
	}
	return result;
}