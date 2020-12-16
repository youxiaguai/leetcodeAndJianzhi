#pragma once
#include "common.h"
int majorityElement(vector<int>& nums) {
    int n = nums.size();
    unordered_map<int,int> m;
    int major = 0, cnt = 0;
    for (int a : nums)
    {
        m[a]++;
        if (m[a] > cnt)
        {
            major = a;
            cnt = m[a];
        }
    }
    return major;
}