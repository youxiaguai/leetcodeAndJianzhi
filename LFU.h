#pragma once
#include "common.h"
struct Node
{
    int key;
    int value;
    int freq;
    Node(int _key, int _value, int _freq) :key(_key), value(_value), freq(_freq) {}
};
class LFUCache {
public:
    LFUCache(int capacity);
        

    int get(int key); 

    void put(int key, int value);
private:
    //LFU的容量
    int cap;
    //最小出现的频次
    int minFreq;
    //key对应的链表
    unordered_map<int, list<Node>::iterator>keys;
    unordered_map<int, list<Node>>freqs;
};
LFUCache::LFUCache(int capacity)
{
    this->cap = capacity;
    minFreq = 0;
    keys.clear();
    freqs.clear();
}
int LFUCache::get(int key)
{
    if (cap == 0)return -1;
  //若不存在key
    auto it = keys.find(key);
    if (it==keys.end())return -1;
    //否则存在key
    list<Node>::iterator p = it->second;
    int value = p->value;
    int fre = p->freq;
    freqs[fre].erase(p);
    if (freqs[fre].size()==0)
    {
        freqs.erase(fre);
        if (minFreq == fre)minFreq++;
    }
    freqs[fre + 1].push_front(Node(key, value, fre + 1));
    keys[key] = freqs[fre + 1].begin();
    return value;


}
void LFUCache::put(int key, int value)
{
    
    if (cap == 0)return;
    //若不存在key
    auto it = keys.find(key);
    if (it == keys.end())
    {
        if (keys.size() == cap)
        {
            auto p = freqs[minFreq].back();
            keys.erase(p.key);
            freqs[minFreq].pop_back();
            if (freqs[minFreq].size() == 0)freqs.erase(minFreq);
        }
        freqs[1].push_front(Node(key, value, 1));
        keys[key] = freqs[1].begin();
        minFreq = 1;
    }
    else
    {
        //若存在
        //得到原来的freq
        list<Node>::iterator p = it->second;
        int fre = p->freq;
        freqs[fre].erase(p);
        if (freqs[fre].size() == 0)
        {
            freqs.erase(fre);
            if (minFreq == fre)minFreq++;
        }
        freqs[fre + 1].push_front(Node(key, value, fre + 1));
        keys[key] = freqs[fre + 1].begin();
    }
    
}