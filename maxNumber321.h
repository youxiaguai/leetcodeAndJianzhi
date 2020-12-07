#pragma once
#include "common.h"
#include <stack>
#include <string>
#include <cctype>
vector<int>MaxSub(vector<int>& nums, int k)
{
	int length = nums.size();
	vector<int>stack(k, 0);
	int top = -1;
	int remain = length - k;
	for (int i = 0; i < length; i++)
	{
		int num = nums[i];
		while (top >= 0 && stack[top] < num && remain>0)
		{
			top--;
			remain--;
		}
		if (top < k - 1)
		{
			stack[++top] = num;
		}
		else
		{
			remain--;
		}

		
	}
	return stack;
}
vector<int>merge(vector<int>& subsequence1, vector<int>& subsequence2)
{
	int x = subsequence1.size();
	int y = subsequence2.size();
	if (x == 0)
	{
		return subsequence2;
	}
	if (y == 0)
	{
		return subsequence1;
	}
	int mergeLength = x + y;
	vector<int>merged(mergeLength);
	int index1 = 0, index2 = 0;
	for (int i = 0; i < mergeLength; i++)
	{
		if (compare(subsequence1, index1, subsequence2, index2) > 0)
		{
			merged[i] = subsequence1[index1++];
		}
		else
		{
			merged[i] = subsequence2[index2];
		}
	}
	return merged;
}
int compare(vector<int>& subsequence1, int index1, vector<int>& subsequence2, int index2)
{
	int x = subsequence1.size(), y = subsequence2.size();
	while (index1 < x && index2 < y)
	{
		int different = subsequence1[index1] - subsequence2[index2];
		if (different != 0)
		{
			return different;
		}
		index1++;
		index2++;
	}
	return (x - index1) - (y - index2);
}

vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
	int n1 = nums1.size();
	int n2 = nums2.size();
	vector<int>maxSubsequence(k, 0);
	int start = max(0, k - n2), end = min(k, n1);
	for (int i = start; i <= end; i++)
	{
		vector<int>subsequence1(MaxSub(nums1, i));
		vector<int>subsequence2(MaxSub(nums2, k-i));
		vector<int>curMax(merge(subsequence1, subsequence2));
		if (compare(curMax, 0, maxSubsequence, 0) > 0)
		{
			maxSubsequence.swap(curMax);
		}
	}
	return maxSubsequence;
}