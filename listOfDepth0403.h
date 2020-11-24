#pragma once
#include "common.h"
#include <queue>
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    
};



 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
 class Solution {
 public:
     vector<ListNode*> listOfDepth(TreeNode* tree) {
         vector<ListNode*>res;
         
         if (!tree)
         {
             return {};
         }
         ListNode* head = new ListNode(tree->val);
         res.push_back(head);
         queue<TreeNode*>Q;
         Q.push(tree);
         while (!Q.empty())
         {
             int all = Q.size(), idx = 0;
             ListNode* p = new ListNode(0);
             ListNode* q = p;
             while (idx++<all)
             {
                 auto top = Q.front();
                 Q.pop();
                 if (top->left)
                 {
                     p->next = new ListNode(top->left->val);
                     Q.push(top->left);
                     p = p->next;
                 }
                 if (top->right) {
                     p->next = new ListNode(top->right->val);
                     Q.push(top->right);
                     p = p->next;
                 }
             }
             if (q->next) {
                 res.push_back(q->next);
             }
         }
         return res;
                
         
     }
};