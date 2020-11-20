#pragma once
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

class Solution {
public:
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        // 中序遍历存入数组
        vector<TreeNode*> ve;
        if (pRoot==nullptr||k<=0)
        {
            return nullptr;
        }
        stack<TreeNode*> stack_node;
        while (pRoot != nullptr || !stack_node.empty())
        {
            if (pRoot!=nullptr)
            {
                stack_node.push(pRoot);
                pRoot = pRoot->left;
            }
            else
            {
                pRoot = stack_node.top();
                if (--k==0)
                {
                    return pRoot;

                }
                stack_node.pop();
                pRoot = pRoot->right;
            }
        }
        return nullptr;



    }


};