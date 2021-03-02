//#pragma once
//#include "common.h"
//class NestedInteger {
//public:
//    NestedInteger(int val);
//    NestedInteger(vector<NestedInteger>& lit);
//        // Return true if this NestedInteger holds a single integer, rather than a nested list.
//        bool isInteger() const;
//    
//            // Return the single integer that this NestedInteger holds, if it holds a single integer
//            // The result is undefined if this NestedInteger holds a nested list
//        int getInteger() const;
//    
//             // Return the nested list that this NestedInteger holds, if it holds a nested list
//            // The result is undefined if this NestedInteger holds a single integer
//        const vector<NestedInteger>& getList() const;
//private:
//    int val;
//    vector<NestedInteger>list;
//    
//};
//class NestedIterator {
//public:
//    vector<int>v;
//    int idx = 0;
//    /*void trarse(NestedInteger &root, vector<int>&res)
//    {
//        if (root.isInteger())
//        {
//            res.push_back(root.getInteger());
//            return;
//        }
//        for (auto child : root.getList())
//        {
//            trarse(child, res);
//        }
//    }*/
//    NestedIterator(vector<NestedInteger>& nestedList) {
//       // helper(nestedList);
//    }
//
//    int next() {
//       
//        int r = v[idx];
//        idx++;
//        return r;
//    }
//
//    bool hasNext() {
//        return (idx + 1 <= v.size());
//    }
//private:
//    
//    /*void helper(vector<NestedInteger>& nestedList)
//    {
//        for ( auto it : nestedList)
//        {
//            if (it.isInteger())
//            {
//                v.push_back(it.getInteger());
//            }
//            else
//            {
//                helper(it.getList());
//            }
//
//        }
//    }*/
//};