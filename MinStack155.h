#pragma once
#include "common.h"
#include <stack>
class MinStack {
private:
    stack<int>s;
    //��һ������ջ���洢ÿһ���е���Сֵ
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
