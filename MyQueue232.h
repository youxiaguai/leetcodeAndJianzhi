#pragma once
#include <stack>
#include "common.h"
class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        st1.empty();
        st2.empty();
    }

    /** Push element x to the back of queue. */
    void push(int x) {
        
        st1.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int result;
        if(st2.empty())
        {
            while (!st1.empty())
            {
                int temp=st1.top();
                st2.push(temp);
                st1.pop();
            }
            
            
        }
        result = st2.top();
        st2.pop();
        return result;
    }

    /** Get the front element. */
    int peek() {
        if (st2.empty())
        {
            while (!st1.empty())
            {
                int temp = st1.top();
                st2.push(temp);
                st1.pop();
            }
        }
        return  st2.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        if (st1.empty() && st2.empty())
        {
            return true;
        }
        return false;
    }
private:
    stack<int>st1;
    stack<int>st2;
};