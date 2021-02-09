#pragma once
#include "common.h"
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
    
};

class Solution {
public:
    /*ListNode* left;
    bool digui(ListNode* node)
    {
        if (node == nullptr)return true;
        bool res = digui(node->next);

        res = res && (left->val == node->val);
        left = left->next;
        return res;
    }*/
    ListNode* reverse(ListNode* head)
    {
        ListNode* pre = nullptr;
        ListNode* cur = head;
        while (cur!=nullptr)
        {
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
            
        }
        return pre;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* slow, * fast;
        slow = fast = head;
        while (fast!=nullptr&&fast->next!=nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        if (fast != nullptr)
        {
            slow = slow->next;
        }
        ListNode* left = head;
        ListNode* right = reverse(slow);
        while (right!=nullptr)
        {
            if (left->val != right->val)
            {
                return false;
            }
            left = left->next;
            right = right->next;
        }
        return true;
    }
};