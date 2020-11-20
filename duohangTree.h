#pragma once
#include <stddef.h>
#include <vector>
#include <queue>
#include <iostream>
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
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int>> res;
        if (!pRoot)
        {
            return res;
        }
        queue<TreeNode*>q;
       // int lever = 0;

        q.push(pRoot);

        
        
        
        while (!q.empty())
        {
            int sz = q.size();
            vector<int> ans;
            while (sz--)
            {
                TreeNode* front = q.front();
                q.pop();
                ans.push_back(front->val);
                if (front->left != nullptr)
                {
                    q.push(front->left);
                }
                if (front->right != nullptr)
                {
                    q.push(front->right);
                }
            }
           // lever++;
            res.push_back(ans);

            for (int i = 0; i < ans.size(); i++)
            {
                cout << ans[i];
            }
            cout << endl;
        }

       
        return res;


    }

};