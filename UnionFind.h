#pragma once
#include "common.h"
class UnionFind
{
public:
	UnionFind(int n);
	void unionPQ(int p, int q);
	bool connected(int p, int q);
	int count();
	
private:
	int cnt;
	vector<int>parent;
	vector<int>size;
	int find(int x);
};

