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
    //递归
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
    //非递归中序遍历
    //bool isValidBST(TreeNode* root) {
    //    //空树
    //    if (root == nullptr)
    //    {
    //        return true;
    //    }
    //    //非空树
    //    stack<TreeNode*>stack;
    //    TreeNode* pre = nullptr;//用来保存当前节点
    //    while (root!=nullptr||!stack.empty())
    //    {
    //        //找到最左边的一个节点
    //        while (root!=nullptr)
    //        {
    //            stack.push(root);
    //            root = root->left;
    //        }
    //        //弹出最左边的一个节点
    //        root = stack.top();
    //        stack.pop();
    //        //中序遍历中 若是二叉搜索树，则左子树的节点值小于根节点的值，根节点的值小于右子树节点的值，即中序遍历之后的值应为升序
    //        if (pre!=nullptr&&root->val<=pre->val)
    //        {
    //            return false;

    //        }
    //        pre = root;
    //        root = root->right;
    //    }
    //    return true;
    //}
    //递归中序遍历
    TreeNode* pre;
    bool isValidBST(TreeNode* root) {
        //若是空树
        if (root == nullptr)
        {
            return true;
        }
        //非空树
        //访问左子树
        if (!isValidBST(root->left))
        {
            return false;
        }
        if (pre != nullptr && pre->val >= root->val)
        {
            return false;
        }
        pre = root;
        //访问右子树
        if (!isValidBST(root->right))
        {
            return false;
        }
        return true;

    }
};