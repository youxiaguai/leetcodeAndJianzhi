#pragma once
#include <queue>
#include "common.h"
int nthSuperUglyNumber(int n, vector<int>& primes) {
	//int n = primes.size();
	priority_queue<int, vector<int>, greater<int>>q;
	q.push(1);
	
	int count = 1;
	unordered_set<long>visited;
	while (count <n)
	{
		int curr = q.top();
		q.pop();
		count++;
		for (const auto	& ch : primes)
		{
			long next = (long)curr * ch;
			if (!visited.count(next) && next <= INT_MAX)
			{
				visited.insert(next);
				q.push(next);
			}
		}
		
	}
	return q.top();
}