#pragma once
#include "common.h"
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    
};

class Solution {
public:
    TreeNode* dfs( int left, int right,vector<int>&nums)
    {
    
        if (left > right)
        {
            return nullptr;
        }
       
            int mid = (left + right) / 2;
            TreeNode* root = new TreeNode(nums[mid]);
            
            
                
            
            root->left = dfs(left, mid - 1, nums);
            root->right = dfs(mid + 1, right, nums);
           
        
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        return dfs(0, n - 1, nums);

    }
};