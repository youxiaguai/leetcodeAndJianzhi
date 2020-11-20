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
        //若没有左右子树，看他为父节点的左子树还是右子树
        if (pNode->left == nullptr && pNode->right == nullptr)
        {
            //若为左子树 则下一个节点则为父节点
            if (pNode->next->left == pNode )
            {
                return pNode->next;
            }
            //若为右子树，则看父节点是否有父节点 ，如果有则返回，
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
        //若存在左右子树
        else
        {
            //若右子树不为空，则返回右子树的最左节点，如果右子树没有最左节点则返回其自己
            if (pNode->right!=nullptr)
            {
                return pNode->right;
            }
            //右子树为空 并且有父节点 并且为父节点的左子树
            else if (pNode->right == nullptr && pNode->next != nullptr&&pNode->next->left==pNode)
            {
                return pNode->next;
            }
            //右子树为空 并且 要么没有父节点要么是父节点的右子树
            else if (pNode->right==nullptr&&(pNode->next==nullptr)||pNode->next->right==pNode)
            {
                return nullptr;
            }
           
        }
        //如果有左右子树，有左子树则下一个节点就是左子树，无左子树则下一个节点就是右子树
        //-----------------------------------------------------------------------------

        if (!pNode) {
            return pNode;
        }

        // 属于[2 3 6]类
        if (pNode->right) {
            pNode = pNode->right;
            while (pNode->left) {
                pNode = pNode->left;
            }
            return pNode;
        }

        // 属于 [1] 和 [4 5]
        while (pNode->next) {
            TreeLinkNode* root = pNode->next;
            if (root->left == pNode) {
                return root;
            }
            pNode = pNode->next;
        }

        // 属于[7]
        return nullptr;
    }
};
