#pragma once
#include "common.h"
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    
};

class Solution {
private:
    unordered_map<int, int>index;
public:
    TreeNode* dfs(const vector<int>& preorder,const vector<int>&inorder, int preleft,int preright, int inorderleft, int inorderright)
    {
        if (preleft > preright)
        {
            return nullptr;

        }
        int  preorder_root = preleft;
        int inorder_root = index[preorder[preorder_root]];
        TreeNode* root = new TreeNode(preorder[preorder_root]);
        int size_left_subtree = inorder_root - inorderleft;
        root->left = dfs(preorder, inorder, preleft + 1, preleft + size_left_subtree, inorderleft, inorder_root - 1);
        root->right = dfs(preorder, inorder, preleft + size_left_subtree + 1, preright, inorder_root + 1, inorderright);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        for (int i = 0; i < preorder.size(); i++)
        {
            index[inorder[i]] = i;
        }
        return dfs(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
       
    }
};