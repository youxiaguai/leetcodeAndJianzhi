#pragma once
#include "common.h"
struct Union_find
{
	vector<int>parents;
	Union_find(int size)
	{
		parents.resize(size);
		for (int i = 0; i < size; i++)
		{
			parents[i] = i;
		}
	}
	int find(int x)
	{
		int root = x;
		while (root != parents[root])
		{
			root = parents[root];
		}

		while (root!=x)
		{
			int tmp = parents[x];
			parents[x] = root;
			x = tmp;
		}
		return root;
	}
	void merge(int x, int y)
	{
		parents[find(x)] = parents[find(y)];
	}

};

string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
	Union_find UF(s.size());
	for (auto& pair : pairs)
	{
		UF.merge(pair[0],pair[1]);
	}
	unordered_map<int, vector<int>>group;
	for (int i = 0; i < s.size(); i++)
	{
		group[UF.find(i)].push_back(i);
	}
	string ret(s.size(), '#');
	for (auto it = group.begin(); it != group.end(); it++) {
		vector<int> indexs = it->second;
		string tmp;
		// ȡ��ÿ��groupӵ�е������ַ�
		for (auto& index : indexs) {
			tmp += s[index];
		}
		// ͬһ��group���ַ��ֵ�������
		sort(tmp.begin(), tmp.end());

		int i = 0;
		// �ź�����ַ��ŵ���ǰgroupӵ�е�slot��ȥ
		for (auto& index : indexs) {
			ret[index] = tmp[i++];
		}
	}
	return ret;

}