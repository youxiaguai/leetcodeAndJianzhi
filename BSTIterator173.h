#pragma once
#include "common.h"
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    
};

class BSTIterator {

public:
    vector<int>v;
    int i = 0;
    BSTIterator(TreeNode* root) {
        buildV(root);
    }
    void buildV(TreeNode* r)
    {
        if (!r)return;
        buildV(r->left);
        v.push_back(r->val);
        buildV(r->right);
    }
    /** @return the next smallest number */
    int next() {
        return v[i++];
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        if (i == v.size())return false;
        return true;
    }
};
