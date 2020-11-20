#pragma once
#include <stddef.h>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

class Solution {
public:
    //将二叉树镜像
    TreeNode* jingxiang(TreeNode* pRoot)
    {
        if (pRoot == nullptr)
        {
            return nullptr;
        }
        TreeNode* temp = pRoot->left;
        pRoot->left = pRoot->right;
        pRoot->right = temp;
        jingxiang(pRoot->left);
        jingxiang(pRoot->right);
        return pRoot;
    }
    //将镜像后的二叉树与原来的二叉树比较
    bool isSymmetrical(TreeNode* pRoot)
    {
        TreeNode* jingxiang1;
       jingxiang1= jingxiang(pRoot);
        if (jingxiang1==pRoot)
        {
            while (jingxiang1->left != nullptr && pRoot->left != nullptr)
            {
                jingxiang1 = jingxiang1->left;
                pRoot = pRoot->left;
                return isSymmetrical(pRoot->left);

            }
            while (jingxiang1->right != nullptr && pRoot->right != nullptr)
            {
                jingxiang1 = jingxiang1->right;
                pRoot = pRoot->right;
                return isSymmetrical(pRoot->right);

            }
            
        }
     
         return false;
    }
    //return false;
    //-------------------------------------------分界线----------------------------------------------------
    bool isSame(TreeNode* root1, TreeNode* root2)
    {
        if (!root1 && !root2)
        {
            return true;
        }
        if (!root1 || !root2)
        {
            
            return false;
        }
        return root1->val == root2->val &&
            isSame(root1->left, root2->right) &&
            isSame(root1->right, root2->left);

    }
    bool isSymmetrical(TreeNode* pRoot)
    {
        return isSame(pRoot, pRoot);
    }
};