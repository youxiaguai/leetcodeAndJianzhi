#pragma once
#include "common.h"
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
    
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* cur = NULL;
        ListNode* pre = head;
        while (pre != nullptr)
        {
            ListNode* t = pre->next;
            pre->next = cur;
            cur = pre;
            pre = t;
            
        }
        return cur;
    }
};