#pragma once
#include "common.h"
string zhuanhuanShu(string &num1,string &num2)
{
	int result = 0;	
	int i = num1.size();
	int j = num2.size();
	string ans;
	
	while (i>=0||j>=0||result!=0)
	{
		int x = i >= 0 ? num1.at(i) - '0' : 0;
		int y = j >= 0 ? num2.at(j) - '0' : 0;
		int result = x + y + result;
		ans.push_back(result%10);
		result = result / 10;
		i--; j--;
	}
	reverse(ans.begin(), ans.end());
	for (auto c : ans)
	{
		c += '0';
	}
	return ans;
}
string multiply(string num1, string num2) {
	if (num1 == "0" || num2 == "0")
	{
		return "0";
	}
	string ans = "0";
	int m = num1.size(), n = num2.size();

}