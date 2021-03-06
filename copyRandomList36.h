#pragma once
#include "common.h"
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
struct nodeStruct
{
    int val;
    Node* next;
    Node* random;
};
class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* cur = head;
        //unordered_map来temp按顺序记录一下每个节点的信息
        unordered_map<Node*, Node*>temp;
        int index = 0;
        while (cur!=nullptr)
        {
            temp[cur] =new Node(cur->val);
            cur = cur->next;
        }
        cur = head;
        //创建一个新的链表
       // Node* result = head;
        while (cur!=nullptr)
        {
            temp[cur]->next = temp[cur->next];

            temp[cur]->random = temp[cur->random];
            cur = cur->next;
        }
        return temp[head];
    }

};