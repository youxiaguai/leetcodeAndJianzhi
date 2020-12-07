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
    void getElement(TreeNode* root,vector<int>&res)
    {
        if (!root)return;
        res.push_back(root->val);
        getElement(root->left, res);
        getElement(root->right, res);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int>res;
       
        getElement(root1, res);
        getElement(root2, res);
        sort(res.begin(), res.end());
        return res;
    }
};