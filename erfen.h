#pragma once
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * 二分查找
     * @param n int整型 数组长度
     * @param v int整型 查找值
     * @param a int整型vector 有序数组
     * @return int整型
     */
    int upper_bound_(int n, int v, vector<int>& a) {
        // write code here
        int low = 0;
        int high = n - 1;
        
        while (low<=high)
        {
            int mid = low + (high - low) / 2;
            if (a[mid] >= v)
            {
                if (mid == 0 || a[mid - 1] < v)
                {
                    return mid + 1;
                }
                else
                {
                    high = mid;
                }
            }
            else
            {
                low = mid + 1;
            }
            
        }
        return n + 1;
       
    }
};