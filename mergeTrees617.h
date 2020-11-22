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
    
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (!t1 && !t2)
        {
            return 0;
        }

        TreeNode* result = new TreeNode(0);
        if (t1)
        {
            result->val += t1->val;
        }
        if (t2)
        {
            result->val += t2->val;
        }
        result->left = mergeTrees(t1?t1->left:0, t2?t2->left:0);
        result->right = mergeTrees(t1 ? t1->right : 0, t2 ? t2->right : 0);
        
        return result;
    }
    
};