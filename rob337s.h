#pragma once
#include "common.h"
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};
class Solution{
public:
	unordered_map<TreeNode*, int>ma;
	int rob(TreeNode * root) {
		if (root == nullptr)return 0;
		if (ma.count(root))return ma[root];
		int do_it = root->val + (root->left == nullptr ? 0 : rob(root->left->left) + rob(root->left->right)) + (root->right == nullptr ? 0 : rob(root->right->left) + rob(root->right->right));
		int undo_it = rob(root->left) + rob(root->right);
		int reuslr = max(do_it, undo_it);
		ma[root] = reuslr;
		return reuslr;
	}
};