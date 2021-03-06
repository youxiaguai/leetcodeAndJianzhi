#pragma once
#include "common.h"
#include <queue>
#include <map>
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    
};

class FindElements {
public:
    map<int, int>mapp;
    FindElements(TreeNode* root) {
        
    
        
         root->val = 0;
        queue<TreeNode*>q;
       
       
        q.push(root);
     
        while (!q.empty())
        {
            
            
                TreeNode* curr = q.front();
                q.pop();
                mapp[curr->val]++;
               
                if (curr->left != nullptr)
                {
                    curr->left->val = 2 * curr->val + 1;
                    q.push(curr->left);
                   
                }
                if (curr->right != nullptr)
                {
                    curr->right->val = 2 * curr->val + 2;
                    q.push(curr->right);
                   
                }
            
        }
        
    }

    bool find(int target) {
        if (mapp[target])
        {
            return true;
        }
        return false;
           
    }

    
};