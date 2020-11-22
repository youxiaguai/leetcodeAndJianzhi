#pragma once
#include "common.h"
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
    
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        node = node->next;
        node->next = node->next->next;
        
    }
};