#pragma once
#include "common.h"
#include "UnionFind.h"
bool equationsPossible(vector<string>& equations) {
	//int n = equations.size();
	UnionFind uf(26);
	for (const string &eq:equations)
	{
		if (eq.at(1) == '=')
		{
			char x = eq.at(0);
			char y = eq.at(3);
			uf.unionPQ(x-'a', y-'a');
		}
	}
	for (const string &eq : equations)
	{
		if (eq.at(1) == '!')
		{
			char x = eq.at(0);
			char y = eq.at(3);
			if (uf.connected(x - 'a', y - 'a'))
			{
				return false;
			}
		}
		
	}
	return true;
}