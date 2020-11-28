#pragma once
#include "common.h"
#include<numeric>
class Su {

public:
	vector<int>temp;
	vector<vector<int>>re;
	void dfs1(int cur, int k, int n, int sum)
	{

		if (temp.size()+(n-cur+1)<k||temp.size()>k)
		{
			return;

		}
		if (temp.size() == k && accumulate(temp.begin(),temp.end(),0)==sum)
		{
			ans.push_back(temp);
			return;

		}
		temp.push_back(cur);
		dfs1(cur+1,k,n,sum);
		temp.pop_back();
		dfs1(cur + 1, k, n, sum);
		


		
	}
	vector<vector<int>> combinationSum3(int k, int n)
	{
		

		dfs1(1,k,9, n);
		
		return ans;
	}


};

