#pragma once
#include "common.h"
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
    
};

class Solution {
    ListNode* frontPointer;
public:
    bool recur(ListNode* root)
    {
        if (root != nullptr)
        {
            if (!recur(root->next))
            {
                return false;
            }
            if (root->val != frontPointer->val)
            {
                return false;
            }
            frontPointer = frontPointer->next;
        }
        return true;
    }
    bool isPalindrome(ListNode* head) {
        frontPointer = head;
    }
};