#pragma once
#include "common.h"
string reverseWords(string s) {
	string result = "";
	int length = s.length();
	int i = 0;
	while (i<length)
	{
		int start = i;
		while (i<length&&s[i]!=' ')
		{
			i++;
		}
		int left = start;
		int right = i - 1;
		while (left<right)
		{
			swap(s[left], s[right]);
			left++;
			right--;
		}
		while (i<length&&s[i]==' ')
		{
			i++;
		}
	}
	return s;
}