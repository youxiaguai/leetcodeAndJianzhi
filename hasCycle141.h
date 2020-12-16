#pragma once
#include "common.h"
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
	
};
bool hasCycle(ListNode* head) {
	unordered_set<ListNode*>se;
	while (head!=nullptr)
	{
		if (se.count(head))
		{
			return true;
		}
		se.insert(head);
		head = head->next;
	}
	return false;
}