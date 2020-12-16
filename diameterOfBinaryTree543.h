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
    int ans = 0;
    int depth(TreeNode* rt)
    {
        if (rt == nullptr)
        {
            return 0;
        }
        int l = depth(rt->left);
        int r = depth(rt->right);
        ans = max(ans, l + r + 1);
        return max(l,r)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        ans = 1;
        depth(root);
        return ans - 1;
    }
};