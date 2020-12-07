#pragma once
#include <stack>
#include "common.h"

class CustomStack {
public:
    int index;
    vector<int>stack;

    CustomStack(int maxSize) {
        stack.resize(maxSize);
        index = -1;
    }

    void push(int x) {
        if (index!=stack.size()-1)
        {
            ++index;
            stack[index]=x;
        }
       
    }

    int pop() {
        if (index == -1)
        {
            return -1;
        }
        --index;
        return stack[index + 1];

    }

    void increment(int k, int val) {
        int limit = min(k, index + 1);
        for (int i = 0; i < limit; i++)
        {
            stack[i] += val;
        }
    }

   
  
};
