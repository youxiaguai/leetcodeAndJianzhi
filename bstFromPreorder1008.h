#pragma once
#include "common.h"
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
    
};

class Solution {
    
   
public:
    TreeNode* dfs(vector<int>&nums,int l, int r)
    {
        if (l > r)return NULL;
        TreeNode* root = new TreeNode(nums[l]);
        if (l == r)return root;
        int j = l + 1;
        while (nums[j]<nums[l])
        {
            j++;
            if (j >= nums.size())break;
        }
        root->left = dfs(nums, l + 1, j - 1);
        root->right = dfs(nums, j, r);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = dfs(preorder, 0, preorder.size() - 1);
        return root;
    }
};