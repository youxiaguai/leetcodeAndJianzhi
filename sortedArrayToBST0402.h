#pragma once
#include "common.h"
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};
TreeNode* created(vector<int>& nums,int low,int high)
{
	if (low > high)
	{
		return nullptr;
	}
	int mid = (high - low) / 2 + low;
	TreeNode* root=new TreeNode(nums[mid]);
	//root->val = nums[mid];
	root->left = created(nums, low, mid - 1);
	root->right = created(nums, mid + 1, high);
	return root;
}
TreeNode* sortedArrayToBST(vector<int>& nums) {
	return created(nums, 0, nums.size()-1);
}