#pragma once
#include "common.h"
void maxHeapify(vector<int>& arr, int size, int index)
{
	int left = 2 * index + 1;
	int right = 2 * index + 2;
	int maxIdx = index;
	if (left<size && arr[left]>arr[index])
	{
		maxIdx = left;
	}
	if (right<size && arr[right]>arr[index])
	{
		maxIdx = right;
	}
	if (maxIdx != index)
	{
		swap(arr[maxIdx], arr[index]);
		maxHeapify(arr, size, maxIdx);
	}
}
void buildMaxHeap(vector<int>& arr, int heapSize)
{
	for (int i = heapSize / 2; i >= 0; i--)
	{
		maxHeapify(arr, heapSize, i);
	}
}
int findKthLargest(vector<int>& nums, int k)
{
	int size = nums.size();
	buildMaxHeap(nums, size);
	for (int i = size-1; i >= size-k+1; i--)
	{
		swap(nums[0], nums[i]);
		--size;
		maxHeapify(nums, 0, size);
	}
	return nums[0];
}