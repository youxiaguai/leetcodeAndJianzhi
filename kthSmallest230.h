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
    void dfs(TreeNode*root,vector<int>&node,int k)
    {
        if (!root)return;
        dfs(root->left,node,k);
        node.push_back(root->val);
        dfs(root->right,node, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int>res;
        dfs(root, res, k);
        return res[k - 1];
    }
};