#pragma once
#include "common.h"
int findMinArrowShots(vector<vector<int>>& points) {
	////�Ƚ�һ���������������ǰһ���������Ƚϣ����С�����ȥ
	//if (points.empty())return 0;
	////��ʼ���������ͬ���ý����������򣬷�����ÿ�ʼ��������
	//sort(points.begin(), points.end(), [](const vector<int>& v1, const vector<int>& v2)
	//{
	//	return v1[0] == v2[0] ? v1[1] < v2[2] : v1[0] < v2[0];
	//}); 
	//int res = 1,maxright=points[0][1];
	//for (int i = 1; i < points.size(); i++)
	//{
	//	//�����ڿ�ʼ����С�ڽ�������
	//	if (points[i][0] > maxright)
	//	{
	//		res++;
	//		maxright = points[i][1];
	//	}
	//	else
	//	{
	//		//�����������������ֵΪ�����������Сֵ
	//		maxright = min(maxright, points[i][1]);
	//	}
	//}
	//return res;
	int n = points.size();
	if (points.size() == 0)
		return 0;
	sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b)
	{
		return a[1] < b[1];
	});
	int count = 1;
	int x_end = points[0][1];
	for (auto poin:points)
	{
		int start = poin[1];
		if (start > x_end)
		{
			count++;
			x_end = poin[1];
		}

	}
	return count;
}