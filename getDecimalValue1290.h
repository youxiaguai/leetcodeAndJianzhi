#pragma once
#include "common.h"
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
	
};
int getDecimalValue(ListNode* head) {
	int result=0;
	while (head!=nullptr)
	{
		int va = head->val;

		result =result*2+ va;
		head = head->next;
	}
	return result;
}