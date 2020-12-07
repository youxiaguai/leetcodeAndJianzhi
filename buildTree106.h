#pragma once
#include "common.h"
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    
};

class Solution {
    int post_index;
    unordered_map<int, int>index_map;
public:
    TreeNode* dfs(vector<int>& inorder,  vector<int>& postorder, int left, int right )
    {
        //在后序找到根节点，再在中序中根据跟节点分成左右子树
        if (left > right)
        {
            return nullptr;
        }
        int root_val = postorder[post_index];
        TreeNode* root = new TreeNode(root_val);
        int in_index = index_map[root_val];

        post_index--;
        root->right = dfs(inorder, postorder, in_index+1, right);
        root->left = dfs(inorder, postorder, left, in_index - 1);
        return root;

    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        TreeNode* resu;

      return dfs(inorder, postorder, 0, postorder.size() - 1);
      post_index = (int)postorder.size()-1;
      int index = 0;
      for (auto& a:inorder )
      {
          index_map[a] = index++;
      }
      return dfs(inorder, postorder, 0, (int)inorder.size()-1);
    }
};