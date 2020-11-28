#pragma once
#include "common.h"
class Solution39 {

public:
    
    
    void dfs(vector<int>& candidates, int target, vector<vector<int>>&ans, vector<int>&temp, int index)
    {
        if (index == candidates.size())
        {
            return;
        }
        if (target == 0)
        {
            ans.emplace_back(temp);
            return;
        }
        dfs(candidates, target, ans, temp, index + 1);
        if (target - candidates[index] >= 0)
        {
            temp.emplace_back(candidates[index]);
            dfs(candidates, target - candidates[index], ans, temp, index );
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        dfs(candidates,target,ans,temp,0);
        return ans;
    }
};