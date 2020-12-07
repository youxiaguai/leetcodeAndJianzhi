#pragma once
#include "common.h"
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
    
};

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (head == nullptr)
        {
            return head;
        }
        //加头节点
        ListNode* pre = new ListNode(0);
        pre->next = head;
        ListNode* curr = head;
        ListNode* post = head->next;
       // he->next = head;
        while (!post)
        {
            if (curr->val <= post->val)
            {
                curr = curr->next;
            }
            else
            {
                ListNode* prev = pre;
                while (prev->next->val <= post->val)
                {
                    prev = prev->next;
                  

                }
                curr->next = post->next;
                post->next = prev->next;
                prev->next = post;
            }
            post = curr->next;
            
        }
        return pre->next;
    }
};