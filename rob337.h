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
    unordered_map<TreeNode*, int>f, g;
    void dfs(TreeNode* o)
    {
        if (!o)
        {
            return;
        }
        dfs(o->left);
        dfs(o->right);
        f[o] = o->val + g[o->left] + g[o->right];
        g[o] = max(f[o->left], g[o->left]) + max(f[o->right], g[o->right]);
    }
    int rob(TreeNode* root) {
        dfs(root);
        return max(f[root], g[root]);
    }
};