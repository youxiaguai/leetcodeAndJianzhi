#pragma once
#include "common.h"
int minSteps(string s, string t) {
	int result = 0;
	//��¼t�е���ĸ�����ִ���
	vector<int>tv(26,0);
	for (int i = 0; i < t.size(); i++)
	{
		tv[t[i]-'a']++;
	}
	//��¼s�е���ĸ�����ִ���
	vector<int>sv(26, 0);
	for (int i = 0; i < s.size(); i++)
	{
		sv[s[i]-'a']++;
	}
	//��s�г��ֵ���ĸ�������ȥ��ʣ�µ�t�еĸ���
	for (int i = 0; i != 26; i++)
	{
		if (sv[i] < tv[i])
		{
			result += tv[i] - sv[i];
		}
	}
	return result;

}