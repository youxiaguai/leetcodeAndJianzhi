#pragma once
#include "common.h"
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};
class Solution {
private:
	int maxdep = -1;
	int sum = 0;
public:
	void dfs(TreeNode* root, int depth)
	{

		if (!root)
		{
			return;
		}
		if (depth > maxdep)
		{
			maxdep = depth;
			sum = root->val;
		}
		else if (depth == maxdep)
		{
			sum += root->val;
		}
		dfs(root->left, depth + 1);
		dfs(root->right, depth + 1);
	}
	int deepestLeavesSum(TreeNode* root) {
		dfs(root, 0);
		return sum;
		



};

