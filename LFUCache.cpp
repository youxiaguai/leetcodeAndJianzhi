#include "LFUCache.h"

LFUCache::LFUCache(int capacit)
{
    this->capacity = capacit;
    this->minFreq = 0;
    Keys.clear();
    freqs.clear();
}





int LFUCache::get(int key)
{
    if (capacity == 0)return -1;
    auto it = Keys.find(key);
    if (!Keys.count(key))
    {
        return -1;
    }
    list<Node>::iterator p = it->second;
    int val = p->value, fre = p->freq;
    freqs[key].erase(p);
    if (freqs[fre].size() == 0)
    {
        freqs.erase(fre);
        if (minFreq == fre)minFreq++;
    }
    freqs[fre + 1].push_front(Node(key, val, fre + 1));
    Keys[key] = freqs[fre + 1].begin();
    return val;
    
}

void LFUCache::put(int key, int value)
{
    if (capacity == 0)return;
    auto it = Keys.find(key);
    //若key不存在
    if (it == Keys.end())
    {
        //若没有容量
        if (Keys.size() == capacity)
        {
            auto p = freqs[minFreq].back();
            Keys.erase(p.key);
            freqs[minFreq].pop_back();
            if (freqs[minFreq].size() == 0)
            {
                freqs.erase(minFreq);
            }
            freqs[1].push_front(Node(key, value, 1));
            Keys[key] = freqs[1].begin();
            minFreq = 1;
        }
        else
        {
            list<Node>::iterator p = it->second;
            int fre = p->freq;
            freqs[fre].erase(p);
            if (freqs[fre].size() == 0)
            {
                freqs.erase(fre);
                if (minFreq == fre)minFreq++;
            }
            freqs[fre + 1].push_front(Node(key, value, fre + 1));
            Keys[key] = freqs[fre + 1].begin();
        }
    }

}
