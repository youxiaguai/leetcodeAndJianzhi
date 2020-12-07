#pragma once
#include "common.h"
#include <queue>
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
    int maxLevelSum(TreeNode* root) {
        int lever = 0;
        if (!root)
        {
            return 0;

        }
        int maxSum = numeric_limits<int>::min();
        int result = 0;
        queue<TreeNode*>q{ {root} };
        while (!q.empty())
        {
            int curSum = 0;
            int size = q.size();
            while (size--)
            {
                auto cur = q.front(); q.pop();
                curSum += cur->val;
                if (cur->left)
                {
                    q.push(cur->left);
                }
                if (cur->right)
                {
                    q.push(cur->right);
                }
            }
            lever++;
            if (curSum > maxSum)
            {
                maxSum = curSum;
                result = lever;
            }
        }
        return result;
    }
};