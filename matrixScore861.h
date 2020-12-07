#pragma once
#include "common.h"
int matrixScore(vector<vector<int>>& A) {
	//�ȷ�ת�б�֤��һλ����1���ٷ�ת�У������ܵĵõ���1������
	int col = A.size();//��
	int row = A[0].size();//��
	for (int i = 0; i < col; i++)
	{
		//�з�ת��������ÿ���е�һ����Ϊ1����ת��һ��
		if (A[i][0] == 0)
		{
			int index = 0;
			while (index<row)
			{
				A[i][index] ^= 1;
				index++;
			}
		}
	}
	int sum = col * pow(2, row - 1);//�����һλ������
	//�ٿ�ÿһ��,ÿһ�з�ת������Ϊ1�ĸ�������������һ��
	for (int i = 1; i < row; i++)
	{
		int count = 0;
		for (int j = 0; j < col; j++)
		{
			
			if (A[j][i] == 1)
			{
				count++;
				
			}
			
			
		}
		if (count <= col / 2)
		{
			count = col - count;
		}
		sum += count * pow(2, row-i-1);
		
	}
	return sum;
}