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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr)
        {
            return "";
        }
        ostringstream  result;
        queue<TreeNode*>q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode* temp = q.front();
            q.pop();
            if (temp)
            {
                result << temp->val << " ";
                q.push(temp->left);
                q.push(temp->right);
                   
            }
            else
            {
                result << "null ";
            }
        }
        return result.str();

    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty())
        {
            return nullptr;
        }
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
                res.push_back(new TreeNode(stoi(info)));
            }
        }
        int pos = 1;
        for (int i = 0; pos < res.size(); i++)
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
