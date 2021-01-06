#pragma once
#include "common.h"
void dfs(vector<string>& conbinations, const unordered_map<char, string>& phoneMap, const string& digits, int index, string& conbination)
{
	if (index == digits.length())
	{
		conbinations.push_back(conbination);
	}
	else
	{
		char digit = digits[index];
		const string& letters = phoneMap.at(digit);
		for (const char& ch : letters)
		{
			conbination.push_back(ch);
			dfs(conbinations, phoneMap, digits, index + 1, conbination);
			conbination.pop_back();
		}
	}
}
vector<string> letterCombinations(string digits) {
	vector<string>conbinations;
	if (digits.empty())
	{
		return conbinations;
	}
	unordered_map<char, string>m = { {'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"} };
	string conbination;
	
	dfs(conbinations, m, digits, 0, conbination);
	return conbinations;
	
}