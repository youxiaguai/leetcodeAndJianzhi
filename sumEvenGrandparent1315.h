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
	//int sum = 0;
public:
	int sumEvenGrandparent(TreeNode* root) {
		int sum = 0;
		if (!root)
		{
			return sum;
		}
		if (root->val % 2 == 0)
		{
			//Ѱ�����ӽڵ㣬���������ӣ���û�У���ݹ鿴���������Ƿ���ż��
			if (root->left != nullptr)
			{
				if (root->left->left != nullptr) sum+=root->left->left->val;
				if (root->left->right != nullptr) sum += root->left->right->val;
				
			}
			if (root->right != nullptr)
			{
				if (root->right->left != nullptr) sum += root->right->left->val;
				if (root->right->right != nullptr) sum += root->right->right->val;
			}
		}
		return sum + sumEvenGrandparent(root->left) + sumEvenGrandparent(root->right);
	}
};