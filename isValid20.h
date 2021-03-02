#pragma once
#include <stack>
#include "common.h"
bool isValid(string s) {
	/*int n = s.size();
	if ( n % 2 == 1)
	{
		return false;
	}
	unordered_map<char, char>pairs = { {']','['}, {')','('} ,{'}','{'} };
	stack<char>st;
	for (auto c : s)
	{
		if (pairs.count(c)) {
			if (st.empty() || st.top() != pairs[c])
			{
				return false;
			}
			st.pop();
		}
		else
		{
			st.push(c);
		}

	}
	return st.empty();

}*/
	int n = s.size();
	unordered_map<char, char>mp = { {'(',')'},{'[',']'},{'{','}'} };
	stack<char>st;
	for (auto it : s)
	{
		if (mp.find(it) != mp.end())
		{
			//if(||)
			char top = st.top();
			if (st.empty()||mp[it] != top)
			{
				return false;
			}
			st.pop();
			
		}
		else
		{
			st.push(it);

		}
	}
	return st.empty();
}