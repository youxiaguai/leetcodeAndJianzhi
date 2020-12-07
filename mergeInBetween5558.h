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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* left;
        ListNode* right;
        int leftIndex = 0, rightIndex = 0;
        while (!list1)
        {
            list1 = list1->next;
            leftIndex++;
            rightIndex++;
            if (leftIndex ==a)
            {
                left = list1;
            }if (rightIndex == b)
            {
                right = list1;
            }
        }

    }
};