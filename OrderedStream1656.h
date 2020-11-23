#pragma once
#include "common.h"
#include <unordered_map>
class OrderedStream {
private:
    unordered_map<int, string>mStream;
    int ptr;
    int num;
public:
    OrderedStream(int n) {
        for (int i = 1; i <= n; i++)
        {
            mStream[i] = "";
        }
        ptr = 1;
        num = n;
    }

    vector<string> insert(int id, string value) {
        
        mStream[id] = value;
        vector<string>res;
        while (ptr<=num && mStream[ptr]!="")
        {
            res.push_back(mStream[ptr]);
            ptr++;
        }
        return res;
    }
};
