#pragma once
#include "common.h"
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};
TreeNode* invertTree(TreeNode* root) {
	if (root==nullptr)
	{
		return root;
	}
	swap(root->left, root->right);
	invertTree(root->left);
	invertTree(root->right);
	return root;
		
}