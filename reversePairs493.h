#pragma once
#include "common.h"
class Solution {
public:
    int find_reversed_pairs(vector<int>& nums, int& left, int& right) {
        int res = 0, mid = left + (right - left) / 2;
        int i = left, j = mid + 1;
        for (; i <= mid; i++) {
            while (j <= right && (long)nums[i] > 2 * (long)nums[j]) {
                res += mid - i + 1;
                j++;
            }
        }
        return res;
    }

    int merge_sort(vector<int>& nums, int nums_sorted[], int left, int right) {
        if (left >= right) return 0;
        int mid = left + (right - left) / 2;

        int res = merge_sort(nums, nums_sorted, left, mid) +
            merge_sort(nums, nums_sorted, mid + 1, right) +
            find_reversed_pairs(nums, left, right);

        int i = left, j = mid + 1, ind = left;

        while (i <= mid && j <= right) {
            if (nums[i] <= nums[j]) nums_sorted[ind++] = nums[i++];
            else nums_sorted[ind++] = nums[j++];
        }
        while (i <= mid) nums_sorted[ind++] = nums[i++];
        while (j <= right) nums_sorted[ind++] = nums[j++];

        for (int ind = left; ind <= right; ind++) nums[ind] = nums_sorted[ind];

        return res;
    }

    int reversePairs(vector<int>& nums) {
        if (nums.empty()) return 0;
        //int nums_sorted[nums.size()];
       // memset(nums_sorted, 0, sizeof(nums_sorted));
       // return merge_sort(nums, nums_sorted, 0, nums.size() - 1);
    }
};


