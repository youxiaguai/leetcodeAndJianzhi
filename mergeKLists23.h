#pragma once
#include <queue>
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
    /*ListNode* merge2Lists(ListNode* l1, ListNode* l2)
    {
        if (!l1 || !l2)
        {
            return l1 ? l1 : l2;
        }
        ListNode head, * tail = &head,*apr=l1,*bpr=l2;
        while (apr&&bpr)
        {
            if (apr->val < bpr->val)
            {
                tail->next = apr;
                apr = apr->next;
            }
            else
            {
                tail->next = bpr->next;
                bpr = bpr->next;
            }
            tail = tail->next;
            
        }
        tail->next = (apr ? apr : bpr);
        return head.next;
    }
    ListNode* merge(vector<ListNode*>& lists, int l, int r)
    {
        if (l == r)return lists[1];
        if (l > r)return nullptr;
        int mid = (l + r) >> 1;
        return merge2Lists(merge(lists,l,mid),merge(lists,mid+1,r));
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return merge(lists, 0, lists.size() - 1);
    }*/
    struct status
    {
        int val;
        ListNode* ptr;
        bool operator < (const status& rhs)const {
            return val > rhs.val;
        }
    };
    priority_queue <status>q;
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        for (auto list : lists)
        {
            if (list) q.push({ list->val,list });
        }
        ListNode head, * tail = &head;
        while (!q.empty())
        {
            auto f = q.top();
            q.pop();
            tail->next = f.ptr;
            tail = tail->next;
            if (f.ptr->next)q.push({ f.ptr->next->val,f.ptr->next });
        }
        return head.next;
    }
};