#pragma once
#include <queue>
#include "common.h"
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>res;
        if (!root)
        {
            return res;
        }
        queue<TreeNode*>q;
        q.push(root);
        while (!q.empty())
        {
            int currsize = q.size();
            res.push_back(vector<int>());
            for (int i = 0; i < currsize; i++)
            {
                auto tmp = q.front();
                q.pop();
                res.back().push_back(tmp->val);
                if (tmp->left)q.push(tmp->left);
                if (tmp->right)q.push(tmp->right);
                
            }
           
        }
        
       
        return res;
    }
};