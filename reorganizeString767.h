#pragma once
#include <queue>
#include"common.h"

string reorganizeString(string S) {
	//将S中每个字符存到数组中
	int n = S.size();
	vector<int>temp(26,0);
	int maxx = 0;
	int index = 0;
	for (int i = 0; i < n; i++)
	{
		temp[S[i] - 'a']++;
		maxx = max(maxx, temp[S[i] - 'a']);
		if (temp[S[i] - 'a'] > maxx)
		{
			maxx = temp[S[i] - 'a'];
			index = i;
		}
		
	}
	if (maxx > (n / 2)&&(n%2==0))
	{
		return "";
	}
	else if (maxx > (n + 1) / 2 && (n % 2 == 1))
	{
		
		return "";
	}
	auto cmp = [&](const char& letter1, const char& letter2) {
		return temp[letter1 - 'a'] < temp[letter2 - 'a'];
	};
	priority_queue<char, vector<char>, decltype(cmp)> queue{ cmp }; 
	for (char c = 'a'; c <= 'z'; c++) {
		if (temp[c - 'a'] > 0) {
			queue.push(c);
		}
	}

	string result = "";
	while (queue.size() >1)
	{
		char letter1 = queue.top(); queue.pop();
		char letter2 = queue.top(); queue.pop();
		result += letter1;
		result += letter2;
		int index1 = letter1 - 'a', index2 = letter2 - 'a';
		temp[index1]--;
		temp[index2]--;
		if (temp[index1] > 0)
		{
			queue.push(letter1);
		}
		if (temp[index2] > 0)
		{
			queue.push(letter2);
		}
	}
	if (queue.size() > 0)
	{
		result += queue.top();
	}
	
	return result;

}