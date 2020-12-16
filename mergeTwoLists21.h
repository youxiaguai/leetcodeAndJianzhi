#pragma once
#include "common.h"
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
    
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* result = new ListNode(-1);
        ListNode* pre = result;
        
            
            while (l1!=nullptr&&l2!=nullptr)
            {
                if (l1->val < l2->val)
                {
                    pre->next = l1;
                    
                    l1 = l1->next;
                }
                else {
                    pre->next = l2;
                    l2 = l2->next;
                }
                pre = pre->next;
            }
           
            pre->next = l1 == nullptr ? l2 : l1;
                return result->next;
        }
        
    
};