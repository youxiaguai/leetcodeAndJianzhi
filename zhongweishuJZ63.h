#pragma once
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> ve;
    void Insert(int num)
    {
        
        if (ve.empty())
        {
            ve.push_back(num);
        }
        else
        {
            auto it = lower_bound(ve.begin(), ve.end(), num);
            ve.insert(it, num);
        }

        
        
    }

    double GetMedian()
    {
        int sz = ve.size();
        if (sz & 1)
        {
            return ve[sz / 2.0f];
        }
        else
        {
            return (ve[sz / 2.0f] + ve[sz / 2.0f - 1.0f]) / 2.0f;
        }
    }

};