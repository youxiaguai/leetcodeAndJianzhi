#pragma once
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * �������β���������Ԫ��֮�͵���Сֵ
     * @param nums int����vector ��������Ҫ����������
     * @return long������
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