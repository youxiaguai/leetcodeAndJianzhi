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
        //��α�������¼�����ڵĲ�������Ϊ�������ǰ�������������Ӻ���ǰ���
        queue<TreeNode*> q;
		vector<vector<int>> re;

	
		if (!pRoot) {
			return re;
		}
		q.push(pRoot);
		int lever = 0;


		while (!q.empty()) {				//�Ӳ�Ϊ��ѭ�� 
			int sz = q.size();//ÿһ��Ĵ�С
			vector<int> ans;
			
			while (sz--) 
			{
				TreeNode* front = q.front();							//����ʱ�Ľڵ� 
				q.pop();
				ans.push_back(front->val);
					
				if (front->left != NULL) {				//������ʱ���ýڵ������ 
					q.push(front->left);
					
				}
				if (front->right != NULL) {				//���Һ���ʱ���ýڵ������ 
					q.push(front->right);
					
				}
				
				
			}
			++lever;
			if (!(lever & 1)) //ż���з�ת���
				reverse(ans.begin(), ans.end());
			re.push_back(ans);
			
									
		} 		
		
		return re;
		
    }

};