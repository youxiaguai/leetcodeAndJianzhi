#pragma once
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * ���ֲ���
     * @param n int���� ���鳤��
     * @param v int���� ����ֵ
     * @param a int����vector ��������
     * @return int����
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