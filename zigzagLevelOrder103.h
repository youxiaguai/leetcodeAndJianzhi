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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        int lever = 1;
        //queue<int>q;
        vector<vector<int>>ans;
        if (!root)
        {
            return ans;
        }

        queue<TreeNode*>q;
        q.push(root);
        bool isLeft = true;
        while (!q.empty())
        {
            deque<int>de;
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                auto node = q.front();
                q.pop();
                if (isLeft)
                {
                    de.push_back(node->val);
                }
                else {
                    de.push_front(node->val);
                }
                if (node->left)
                {
                    q.push(node->left);
                }
                if(node->right)
                {
                    q.push(node->right);
                }
            }
            ans.emplace_back(vector<int>{de.begin(), de.end()});
            isLeft = !isLeft;
        }
        return ans;
    }
};