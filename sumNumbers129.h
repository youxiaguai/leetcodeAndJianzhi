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
    int dfs(TreeNode* root, int num)
    {
        if (root == nullptr)
        {
            return 0;
        }
        int sum = num * 10 + root->val;
        if (root->left == nullptr && root->right == nullptr)
        {
            return sum;
        }
        else
        {
            return dfs(root->left, sum) + dfs(root->right, sum);
        }
    }
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }
};