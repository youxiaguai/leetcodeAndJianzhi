#pragma once
#include "common.h"
#include <stack>
class MinStack {
private:
    stack<int>s;
    //建一个辅助栈来存储每一步中的最小值
    stack<int>min_stack;
    
public:
    /** initialize your data structure here. */
    MinStack() {
        min_stack.push(INT_MAX);
    }

    void push(int x) {
        s.push(x);
        min_stack.push(min(x, min_stack.top()));
    }

    void pop() {
        s.pop();
        min_stack.pop();
    }

    int top() {
       return s.top();

    }

    int getMin() {
        return min_stack.top();
    }
};
