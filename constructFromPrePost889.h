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
  
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        return helper(pre, post, 0, pre.size() - 1, 0, post.size() - 1);

    }


    TreeNode* helper(vector<int>& pre, vector<int>& post, int preleft, int preright, int postleft, int postright)
    {
        if (preleft > preright || postleft > postright)return NULL;
        TreeNode* root = new TreeNode(pre[preleft]);
        if (preleft + 1 <= preright)
        {
            int leftin = postleft;
            while (leftin<=postright&&pre[preleft+1]!=post[leftin])
            {
                leftin++;//找到后序中与前序对应的根节点
            }
            int left = leftin - postleft;//左树节点的个数
            root->left = helper(pre, post, preleft + 1, preleft + left + 1, postleft, postleft + left);
            root->right = helper(pre, post, preleft + left + 2, preright, postleft + left + 1, postright - 1);
            return root;
        }
        else
        {
            return root;
        }
    }
   

           
        
       
};