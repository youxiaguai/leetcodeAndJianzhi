#pragma once
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * 返回两次操作后，数组元素之和的最小值
     * @param nums int整型vector 这你你需要操作的数组
     * @return long长整型
     */
    long long minimumValueAfterDispel(vector<int>& nums) {
        // write code here
        long long sum;
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++)
        {
            nums[i] = nums[i] - nums[1];
        }
        for (int i = 0; i < nums.size(); i++)
        {
            nums[i] = nums[i] - nums[0];
            sum += nums[i];
        }
        return sum;
    }
};