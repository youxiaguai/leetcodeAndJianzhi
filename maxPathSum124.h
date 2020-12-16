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
private:
    int maxx = INT_MIN;
public:
    int maxG(TreeNode* root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        int leftG = max(maxG(root->left),0);
        int rightG = max(maxG(root->right),0);
        int princeMan = leftG + rightG+root->val;
        maxx = max(princeMan, maxx);
        return root->val + max(leftG, rightG);
    }
    int maxPathSum(TreeNode* root) {
        //��ÿ���ڵ�������ֵ����ֵ�Ĺ���ֵ�����䱾�� ���ҽڵ�Ĺ���ֵ�����ֵ
        //���·���������ֵ�����
        maxG(root);
        return maxx;
    }
};