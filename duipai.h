#pragma once
#include "common.h"
void adjust(vector<int>& arr, int len, int index)
{
	//len��arr�ĳ��ȣ�indexΪ��һ����Ҷ�ӽڵ���±�
	int left = 2 * index + 1;//index����Ҷ�ӽڵ�
	int right = 2 * index + 1;//index����Ҷ�ӽڵ�

	int maxIdx = index;
	if (left<len && arr[left]>arr[maxIdx])
	{
		maxIdx = left;
	}
	if (right<len && arr[right]>arr[maxIdx])
	{
		maxIdx = right;
	}
	if (maxIdx != index)
	{
		swap(arr[maxIdx], arr[index]);
		adjust(arr, len, maxIdx);
	}
}
void heapSort(vector<int>& arr, int size)
{
	//��������ѣ������һ����Ҷ������
	for (int i = size / 2 - 1; i >= 0; i--)
	{
		adjust(arr, size, i);
	}
	//���������
	for (int i = size - 1; i >= 1; i--)
	{
		swap(arr[0], arr[1]);
		adjust(arr,i,0);
	}

}