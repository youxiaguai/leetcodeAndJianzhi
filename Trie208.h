#pragma once
#include <map>
#include "common.h"
struct TireNode
{
    bool isWord;
    TireNode* children[26];
    TireNode() :isWord(false)
    {
        for (auto& child : children)
        {
            child = nullptr;
        }
    }
};
class Trie {
    //方便查找用unordered_map但是还要知道第一个的值
private:
    TireNode* root;
    
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TireNode();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        auto p = root;
        for (const auto& w : word)
        {
            int i = w - 'a';
            if (!p->children[w])
            {
                p->children[i] = new TireNode();
            }
            p = p->children[i];
        }
        p->isWord = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        auto p = root;
        for (const auto& ch : word)
        {
            int i = ch - 'a';
            if (!p->children[i])
            {
                return false;
            }
            else {
                p = p->children[i];
            }
        
        }
        return p->isWord;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        auto p = root;
        for (const auto& ch : prefix)
        {
            int i = ch - 'a';
            if (!p->children[i])
            {
                return false;
            }
            else
            {
                p = p->children[i];
            }
        }
        return true;
    }

};
