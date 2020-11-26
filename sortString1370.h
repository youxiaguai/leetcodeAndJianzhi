#pragma once
#include "common.h"
string sortString(string s) {
    
    //nums�洢s�е��ַ����ֵĴ���
    vector<int>nums(26);
    for (char& ch : s)
    {
        nums[ch - 'a']++;
    }
    string res = "";
    //��res�ĳ���С��s�ĳ���ʱ
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


    
