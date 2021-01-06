#pragma once
#include "common.h"
char findTheDifference(string s, string t) {
	int snum = s.size();
	int tnum = t.size();
	char result;
	unordered_map<char, int>mapp;
	for (int i = 0; i < snum; i++)
	{
		mapp[s[i]]++;
	}
	for (int i = 0; i < tnum; i++)
	{
		
			mapp[t[i]]--;
			if (mapp[t[i]] < 0)
			{
				return  t[i];
				
			}
			
	}
	return ' ';
}