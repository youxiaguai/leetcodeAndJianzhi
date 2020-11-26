#pragma once
#include "common.h"
#include <deque>
vector<int> deckRevealedIncreasing(vector<int>& deck) {
	deque<int>dq;
	sort(deck.begin(), deck.end());
	dq.push_back(deck.back());
	for (int i = deck.size() - 2; i >= 0; --i)
	{
		dq.push_front(dq.back());
		dq.pop_back();
		dq.push_front(deck[i]);
	}
	vector<int>ans(dq.begin(), dq.end());
	return ans;

}