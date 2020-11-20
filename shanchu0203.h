#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
	
};
using namespace std;
void deleteNode(ListNode* node) {
	node->val= node->next->val;
	node->next = node->next->next;
}