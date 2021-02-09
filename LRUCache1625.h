#pragma once
#include "common.h"
//链表
class Node
{
public:
    int key, val;
    Node* next, *prev;

	Node();
    Node(int k, int v);
    
	~Node();

private:
   // Node tail;
         
};

//实现一个双链表
class doubleNode
{
public:
	doubleNode();

	~doubleNode();

private:
    Node *head, *tail;
    int size;
};

doubleNode::doubleNode()
{
    head = new Node(0,0);
    tail = new Node(0, 0);
    head->next = tail;
    tail->prev = head;
    size = 0;

}

doubleNode::~doubleNode()
{
}
Node::Node()
{
}
Node::Node(int k, int v)
{
    this->key = k;
    this->val = v;
}
Node::~Node()
{
}
class LRUCache {
private:
   
public:
    LRUCache(int capacity) {

    }

    int get(int key) {

    }

    void put(int key, int value) {

    }
};
