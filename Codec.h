#pragma once
#include <queue>
#include <sstream>
#include "common.h"
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    
};
#include "common.h"
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr)return "";
        queue<TreeNode*>q;
        q.push(root);
        ostringstream  jieguo;
        while (!q.empty())
        {
            TreeNode* cur = q.front();
            if (cur)
            {
                jieguo << cur->val << " ";
                q.push(cur->left);
                q.push(cur->right);
            }
            else
            {
                jieguo << "null";
            }
        }
        return jieguo.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty())return nullptr;
        istringstream input(data);
        string info;
        vector<TreeNode*>res;
        while (input>>info)
        {
            if (info == "null")
            {
                res.push_back(nullptr);
            }
            else
            {
                res.push_back(new TreeNode(stof(info)));
            }
        }
        int pos = 1;
        for (int i = 0; i < res.size(); i++)
        {
            if (!res[i])
            {
                continue;
            }
            res[i]->left = res[pos++];
            if (pos < res.size())
            {
                res[i]->right = res[pos++];
            }
        }
        return res[0];

    }
};