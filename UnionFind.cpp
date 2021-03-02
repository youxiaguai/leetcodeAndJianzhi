#include "UnionFind.h"

UnionFind::UnionFind(int n)
{
	this->cnt = n;
	for (int i = 0; i < n; i++)
	{
		parent[i] = i;
		size[i] = 1;
	}
}

void UnionFind::unionPQ(int p, int q)
{
	int rootP = find(p);
	int rootQ = find(q);
	if (rootP == rootQ)
	{
		return;
	}
	if (size[rootP] > size[rootQ])
	{
		parent[rootQ] = rootP;
		size[rootP] += size[rootQ];
	}
	else
	{
		parent[rootP] = rootQ;
		size[rootQ] += size[rootP];
	}
	cnt--;
	
}

bool UnionFind::connected(int p, int q)
{
	int rootP = find(p);
	int rootQ = find(q);
	return rootP == rootQ;
	//return false;
}

int UnionFind::count()
{
	return cnt;
}

int UnionFind::find(int x)
{
	while (parent[x]!=x)
	{
		parent[x] = parent[parent[x]];  
		x= parent[x];
	}
	return x;
}
