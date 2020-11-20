#pragma once
#include <stddef.h  >
struct TreeLinkNode {
    int val;
    struct TreeLinkNode* left;
    struct TreeLinkNode* right;
    struct TreeLinkNode* next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {

    }
};

class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        //��û����������������Ϊ���ڵ������������������
        if (pNode->left == nullptr && pNode->right == nullptr)
        {
            //��Ϊ������ ����һ���ڵ���Ϊ���ڵ�
            if (pNode->next->left == pNode )
            {
                return pNode->next;
            }
            //��Ϊ���������򿴸��ڵ��Ƿ��и��ڵ� ��������򷵻أ�
            else 
            {
                if (pNode->next->next != nullptr)
                {
                    return pNode->next->next;

                }
                else
                {
                    return nullptr;
                }
            }
            
        }
        //��������������
        else
        {
            //����������Ϊ�գ��򷵻�������������ڵ㣬���������û������ڵ��򷵻����Լ�
            if (pNode->right!=nullptr)
            {
                return pNode->right;
            }
            //������Ϊ�� �����и��ڵ� ����Ϊ���ڵ��������
            else if (pNode->right == nullptr && pNode->next != nullptr&&pNode->next->left==pNode)
            {
                return pNode->next;
            }
            //������Ϊ�� ���� Ҫôû�и��ڵ�Ҫô�Ǹ��ڵ��������
            else if (pNode->right==nullptr&&(pNode->next==nullptr)||pNode->next->right==pNode)
            {
                return nullptr;
            }
           
        }
        //���������������������������һ���ڵ������������������������һ���ڵ����������
        //-----------------------------------------------------------------------------

        if (!pNode) {
            return pNode;
        }

        // ����[2 3 6]��
        if (pNode->right) {
            pNode = pNode->right;
            while (pNode->left) {
                pNode = pNode->left;
            }
            return pNode;
        }

        // ���� [1] �� [4 5]
        while (pNode->next) {
            TreeLinkNode* root = pNode->next;
            if (root->left == pNode) {
                return root;
            }
            pNode = pNode->next;
        }

        // ����[7]
        return nullptr;
    }
};
