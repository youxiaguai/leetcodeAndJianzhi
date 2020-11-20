#pragma once
//快速排序 举例6 1 2 7 9 3 4 5 10 8
#include <vector>
#include <iostream>
using namespace std;

void quickSort(int left, int right, vector<int>& arr)
{
	if (left >= right)
	{
		return;
	}
	int i, j, base, temp;
	i = left, j = right;
	base = arr[left];
	while (i<j)
	{
		while(arr[j] >=base && i<j)//从后往前找比base小的，如果不是则前移
		{
			j--;
		}
		while (arr[i] <= base && i<j)//从前往后找比base大的，否则则往后移
		{
			i++;
		}
	    if (i<j)//两个指针未相遇，则交换
		{
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			
		}
		
	}
	arr[left] = arr[i];//i==j时 arr[i]与base交换，完成一次快排
	arr[i] = base;
	cout << "快排一次结束：" << endl;
	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	quickSort(left, i - 1, arr);//对刚刚排完的数前面的进行快排
	quickSort(i + 1, right, arr);//对后面的数进行快排

}
