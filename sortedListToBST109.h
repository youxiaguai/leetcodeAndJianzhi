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
        //�ҵ��������λ����Ϊ���ڵ㣬������������λ�������ڵ㣬������һ��
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
        //���������ݹ�����λ����Ϊ���ڵ�
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