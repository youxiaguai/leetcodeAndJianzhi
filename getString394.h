#pragma once
#include "common.h"
string src;
size_t ptr;
int getNumber()
{
	int ret = 0;
	while (ptr<src.size()&&isdigit(src[ptr]))
	{
		ret = ret * 10 + src[ptr++] - '0';
	}
	return ret;
}
string getString() {
	if (ptr == src.size() || src[ptr] == ']')
	{
		return "";
	}
	char cur = src[ptr];
	int repTime = 1;
	string ret;
	if (isdigit(cur))
	{
		repTime = getNumber();
		++ptr;
		string str = getString();
		++ptr;
		while (repTime--)
		{
			ret += str;
		}
	}
	else if (isalpha(cur))
	{
		ret = string(1, src[ptr++]);
	}
	return ret + getString();
}
string decodeString(string s)
{
	src = s;
	ptr = 0;
	return getString();
}