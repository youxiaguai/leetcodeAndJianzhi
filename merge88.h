#pragma once
#include "common.h"
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
	int i = nums1.size()-1;
	m--;
	n--;
	while (n>=0)
	{
		while (n>=0&&nums1[m]>nums2[n])
		{
			swap(nums1[m--], nums1[i--]);
		}
		swap(nums1[i--], nums2[n--]);

	}
	
}