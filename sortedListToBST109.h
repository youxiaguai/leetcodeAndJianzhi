#pragma once
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
    
};

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
    class Solution {
    public:
        //找到链表的中位数作为根节点，左子树再找中位数做根节点，右子树一样
        ListNode* getMide(ListNode* left, ListNode* right)
        {
            ListNode* fast = left;
            ListNode* slow = left;
            while (fast != right && fast->next != right)
            {
                fast = fast->next;
                fast = fast->next;
                slow = slow->next;
            }
            return slow;
        }
        //构建树，递归找中位数作为根节点
        TreeNode* build(ListNode* left, ListNode* right)
        {
            if (left == right)
            {
                return nullptr;
            }
            ListNode* mid = getMide(left, right);
            TreeNode* root = new TreeNode(mid->val);
            root->left = build(left, mid);
            root->right = build(mid->next, right);
            return root;
        }
        TreeNode* sortedListToBST(ListNode* head) {
            return build(head, nullptr);
        }
};