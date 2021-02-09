#pragma once
#include <stack>
#include "common.h"
//首先将string转成数字

int helper(string& s, int& i)
{
	stack<int>stk;

	int num = 0;
	char sign = '+';
	while (i<s.size())
	{
		char c = s[i];

		if (isdigit(c))
		{
			num = num * 10 + (c-'0');
		}
		if (c == '(')
		{
		
			num = helper(s, ++i);
		}
		if ((!isdigit(c)&&c!=' ') || (i == s.size() - 1&&c!=')'))
		{
			
			switch (sign)
			{
				int top;
			case '+':
				stk.push(num);
				break;
			case '-':
				stk.push(-num);
				break;
			case '*':
				top = stk.top();
				stk.pop();
				stk.push(top * num);
				break;
			case '/':
				top = stk.top();
				stk.pop();
				stk.push(top / num);
				break;

			}
			sign = c;
			num = 0;
		}
		if (c == ')')
		{
			i++;
			break;
		}
		i++;
		
	}

	
	int res = 0;
	while (!stk.empty())
	{
		res += stk.top();
		stk.pop();
	}
	return res;
}
int calculate(string s) {
	int begin = 0;
	return helper(s, begin);
}