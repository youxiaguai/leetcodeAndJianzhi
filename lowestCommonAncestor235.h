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
    vector<TreeNode*>getPath(TreeNode* root,TreeNode* target)
    {
        vector<TreeNode*>result;
        TreeNode* head = root;
        while (head!=target)
        {
            result.push_back(head);
            if (head->val < target->val)
            {
                head = head->right;
            }
            else
            {
                head = head->left;
            }
        }
        result.push_back(head);
        return result;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*>path_p = getPath(root, p);
        vector<TreeNode*>path_q = getPath(root, q);
        TreeNode* result;
        for (int i = 0; i < path_p.size() && i < path_q.size(); ++i)
        {
            if (path_p[i] == path_q[i])
            {
                result = path_p[i];
            }
            else
            {
                break;
            }
        }
        return result;
    }

};