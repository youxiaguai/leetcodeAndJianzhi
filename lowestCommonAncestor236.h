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
    TreeNode* ans;
    bool dfs(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if (root == nullptr)return false;
        bool l = dfs(root->left, p, q);
        bool r = dfs(root->right, p, q);
        if ((l && r) || (root->val == p->val || root->val == q->val) &&(l||r))
        {
            ans = root;
        }
        return l || r || (root->val == p->val || root->val == q->val);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p, q);
        return ans;
    }
};