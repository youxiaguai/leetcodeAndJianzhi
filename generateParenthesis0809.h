#pragma once
#include "common.h"
//left��ʾ��ʹ�õ�����������right��ʾ��ʹ�õ���������
void backtrack(vector<string>& res, int left, int right, string track)
{
	if (!right && !left) res.push_back(track);
	else
	{
		//ʹ��һ�������ţ�ͬʱ��ʹ������������һ������������Ч����
		if (left > 0) backtrack(res, left - 1, right + 1, track + '(');
		//��ʹ�õ������Ŵ���0������������ԭ����������
		if (right > 0) backtrack(res, left, right - 1, track + ')');
	}
}
vector<string> generateParenthesis(int n) {
	vector<string> res;
	backtrack(res, n, 0, "");
	return res;
}