#pragma once
#include "common.h"
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};


class Solution {
public:
    void dfs(Node* root, vector<vector<int>>& res, int lever)
    {
        if (!root)
        {
            return;
        }
        if (res.size() == lever)
        {
            res.push_back(vector<int>());
        }
        res[lever].push_back(root->val);
        for (const auto& child : root->children)
        {
            dfs(child, res, lever + 1);
        }
    }
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>>res;
        if (!root)
        {
            return res;
        }
        dfs(root, res, 0);
        return res;
    }
};