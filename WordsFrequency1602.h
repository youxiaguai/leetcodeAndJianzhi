#pragma once
#include "common.h"
#include <unordered_map>
class WordsFrequency {
private:
    unordered_map<string, int>m;
public:
    WordsFrequency(vector<string>& book) {
        for (auto word : book)
        {
            m[word]++;
        }
        
    }
    
    int get(string word) {
        
       
        return m[word];
    }
};