#pragma once
#include "common.h"
#include <string>
void build(string ss, int times, string tmp)
{
	for (int i = 0; i < times; i++)
	{
		ss.append(tmp);
	}
}
string getNumber(string &v,size_t &pro)
{
	string ret = "";
	while (isdigit(v[pro]))
	{
		ret.push_back(v[pro++]);
	}
	return ret;
}
string getString(vector<string>& v)
{
	string ret;
	for (const auto& s : v)
	{
		ret += s;
	}
	return ret;
}
string decodeString(string s) {
	string res;
	size_t pre=0;
	vector<string>stk;

	while (pre<s.size())
	{
		char cur = s[pre];
		if (isdigit(cur))
		{
			string digits = getNumber(s, pre);
			stk.push_back(digits);
		}
		else if (isalpha(cur) || cur == '[')
		{
			stk.push_back(string(1, s[pre++]));
			
		}
		else
		{
			++pre;
			vector<string>sub;
			while (stk.back()!="]")
			{
				sub.push_back(stk.back());
				stk.pop_back();
			}
			reverse(sub.begin(), sub.end());
			stk.pop_back();
			// ��ʱջ��Ϊ��ǰ sub ��Ӧ���ַ���Ӧ�ó��ֵĴ���
			int repTime = stoi(stk.back());
			stk.pop_back();
			string t, o = getString(sub);
			// �����ַ���
			while (repTime--) t += o;
			// ������õ��ַ�����ջ
			stk.push_back(t);

		}
	}
}