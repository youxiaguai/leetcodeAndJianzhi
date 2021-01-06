#pragma once
#include "common.h"
struct  LinkNode
{
    int key, value;
    LinkNode* prev;
    LinkNode* next;
    LinkNode() :key(0), value(0), prev(nullptr), next(nullptr) {}
    LinkNode(int _key, int _value) :key(_key), value(_value), prev(nullptr), next(nullptr) {}
};
class LRUCache {
private:
    unordered_map<int, LinkNode*>mp;
    LinkNode* head;
    LinkNode* tail;
    int size;
    int capacity;
public:
    LRUCache(int _capacity) :capacity(_capacity),size(0){
        head = new LinkNode();
        tail = new LinkNode();
        head->next = tail;
        tail->prev = head;
        
    }

    int get(int key) {
        if (!mp.count(key))
        {
            return -1;
        }
        LinkNode* node = mp[key];
        moveToHead(node);
        return node->value;

    }





    void put(int key, int value) {
        if (!mp.count(key))
        {
            LinkNode* node = new LinkNode(key, value);
            mp[key] = node;
            addToHead(node);
            ++size;
            if (size > capacity)
            {
                LinkNode* removed = removeTail();
                mp.erase(removed->key);
                delete removed;
                --size;
                
            }
        }
        else
        {
            LinkNode* node = mp[key];
            node->value = value;
            moveToHead(node);
        }
    }

    void addToHead(LinkNode* node)
    {
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;

    }

    void removeNode(LinkNode* node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void moveToHead(LinkNode* node)
    {
        removeNode(node);
        addToHead(head);
    }

    LinkNode* removeTail()
    {
        LinkNode* node = tail->prev;
        removeNode(node);
        return node;
    }
};
