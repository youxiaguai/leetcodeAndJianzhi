#pragma once
#include "common.h"
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};
int countNodes(TreeNode* root) {
	int countSum = 0;
	if (root != nullptr)
	{
		countSum++;
	}
	if (root == nullptr)
	{
		return countSum;
	}
	countSum += countNodes(root->left);
	countSum += countNodes(root->right);
	return countSum;
}