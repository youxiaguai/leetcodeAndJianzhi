#pragma once
#include "common.h"
string sortString(string s) {
    
    //nums存储s中的字符出现的次数
    vector<int>nums(26);
    for (char& ch : s)
    {
        nums[ch - 'a']++;
    }
    string res = "";
    //当res的长度小于s的长度时
    while (res.length() < s.length())
    {
        for (int i = 0; i < 26; i++)
        {
            if (nums[i])
            {
                res.push_back(i+'a');
                nums[i]--;
            }
            
        }
        for (int i = 25; i >=0; i--)
        {
            if (nums[i])
            {
                res.push_back(i+'a');
                nums[i]--;
            }
        }
    }
    return res;
}


    
