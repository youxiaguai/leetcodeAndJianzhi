#pragma once
#include "common.h"
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
    
};

class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        ListNode* l1 = headA;
        ListNode* l2 = headB;
        if (headA == NULL || headB == NULL)
        {
            return NULL;
        }
        while (l1!=l2)
        {
            if (l1 != nullptr)
            {
                l1 = l1->next;
            }
            else
            {
                l1=headB;
            }
            if (l2!= nullptr)
            {
                l2 = l2->next;
            }
            else
            {
                l2 = headA;
            }
               
        }
        return l1;
    }
};