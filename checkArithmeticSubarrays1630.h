#pragma once
#include "common.h"
vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
    vector<bool> res;
    for (int i = 0, j = 0; i < l.size() && j < r.size(); i++, j++)
    {
        int index_left = l[i], index_right = r[j];
        vector<int> vec;
        for (int k = index_left; k <= index_right; k++)
            vec.push_back(nums[k]);
        sort(vec.begin(), vec.end());
        int diff = vec[1] - vec[0];
        int flag = 1;
        for (int k = 1; k < vec.size(); k++)
        {
            if (vec[k] - vec[k - 1] != diff)
            {
                flag = 0;
                break;
            }
        }
        if (flag == 1)
            res.push_back(true);
        else
            res.push_back(false);
    }
    return res;

    
}