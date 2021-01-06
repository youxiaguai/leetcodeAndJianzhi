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
    void preOrder(TreeNode* root,vector<TreeNode*>&re)
    {
        if (root != NULL)
        {
            re.push_back(root);
            preOrder(root->left, re);
            preOrder(root->right, re);
        }
        
    }
    void flatten(TreeNode* root) {
        vector<TreeNode*>l;
        preOrder(root, l);
        int n = l.size();
        for (int i = 1; i < n; i++)
        {
            TreeNode* pre = l[i - 1], * curr = l[i];
            pre->left = nullptr;
            pre->right = curr;
        }
    }
};