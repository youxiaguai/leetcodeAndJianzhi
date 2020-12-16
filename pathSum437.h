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
    int find(TreeNode* root, int num)
    {
        if (root == nullptr)
        {
            return 0;
        }
        num -= root->val;
        return (num == 0 ? 1 : 0) + find(root->left, num) + find(root->right, num);
        
     //   return || find(root->right, num - (root->val));
    }
    int pathSum(TreeNode* root, int sum) {
        //      
        if (root == nullptr)return 0;
        return find(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }
};