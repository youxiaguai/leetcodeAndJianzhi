#pragma once
#include "common.h"
void adjust(vector<int>& arr, int len, int index)
{
	//len是arr的长度，index为第一个非叶子节点的下标
	int left = 2 * index + 1;//index的左叶子节点
	int right = 2 * index + 1;//index的右叶子节点

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
	//建立大根堆，从最后一个非叶子往上
	for (int i = size / 2 - 1; i >= 0; i--)
	{
		adjust(arr, size, i);
	}
	//调整大根堆
	for (int i = size - 1; i >= 1; i--)
	{
		swap(arr[0], arr[1]);
		adjust(arr,i,0);
	}

}