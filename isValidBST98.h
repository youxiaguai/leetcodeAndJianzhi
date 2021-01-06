#pragma once
#include <stack>
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
    //�ݹ�
  /* bool dfs(TreeNode* root,long long lower,long long upper)
    {
       
        if (root == nullptr)
        {
            return true;
        }
        if (root->val <= lower || root->val >= upper)
        {
            return false;
        }
        return dfs(root->left, lower, root->val) && dfs(root->right, root->val, upper);
       

    }
    bool isValidBST(TreeNode* root) {
        

        return dfs(root,LONG_MIN,LONG_MAX);

    }*/
    //�ǵݹ��������
    //bool isValidBST(TreeNode* root) {
    //    //����
    //    if (root == nullptr)
    //    {
    //        return true;
    //    }
    //    //�ǿ���
    //    stack<TreeNode*>stack;
    //    TreeNode* pre = nullptr;//�������浱ǰ�ڵ�
    //    while (root!=nullptr||!stack.empty())
    //    {
    //        //�ҵ�����ߵ�һ���ڵ�
    //        while (root!=nullptr)
    //        {
    //            stack.push(root);
    //            root = root->left;
    //        }
    //        //��������ߵ�һ���ڵ�
    //        root = stack.top();
    //        stack.pop();
    //        //��������� ���Ƕ��������������������Ľڵ�ֵС�ڸ��ڵ��ֵ�����ڵ��ֵС���������ڵ��ֵ�����������֮���ֵӦΪ����
    //        if (pre!=nullptr&&root->val<=pre->val)
    //        {
    //            return false;

    //        }
    //        pre = root;
    //        root = root->right;
    //    }
    //    return true;
    //}
    //�ݹ��������
    TreeNode* pre;
    bool isValidBST(TreeNode* root) {
        //���ǿ���
        if (root == nullptr)
        {
            return true;
        }
        //�ǿ���
        //����������
        if (!isValidBST(root->left))
        {
            return false;
        }
        if (pre != nullptr && pre->val >= root->val)
        {
            return false;
        }
        pre = root;
        //����������
        if (!isValidBST(root->right))
        {
            return false;
        }
        return true;

    }
};