#pragma once
#include <stddef.h>
#include <vector>
#include <queue>
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
        //层次遍历，记录下所在的层数，若为奇数则从前往后输出，否则从后往前输出
        queue<TreeNode*> q;
		vector<vector<int>> re;

	
		if (!pRoot) {
			return re;
		}
		q.push(pRoot);
		int lever = 0;


		while (!q.empty()) {				//队不为空循环 
			int sz = q.size();//每一层的大小
			vector<int> ans;
			
			while (sz--) 
			{
				TreeNode* front = q.front();							//出队时的节点 
				q.pop();
				ans.push_back(front->val);
					
				if (front->left != NULL) {				//有左孩子时将该节点进队列 
					q.push(front->left);
					
				}
				if (front->right != NULL) {				//有右孩子时将该节点进队列 
					q.push(front->right);
					
				}
				
				
			}
			++lever;
			if (!(lever & 1)) //偶数行反转输出
				reverse(ans.begin(), ans.end());
			re.push_back(ans);
			
									
		} 		
		
		return re;
		
    }

};