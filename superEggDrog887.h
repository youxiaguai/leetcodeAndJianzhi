#pragma once
#include "common.h"
#include <set>
int superEggDrop(int K, int N) {
	vector<vector<int>>dp(K, vector<int>(N));
	unordered_map<int, int>st;
	if (K == 1)
	{
		return  N;
	}
	if (N == 0)
	{
		return 0;
	}
	if (st.count(dp[K][N]))
	{
		return st[dp[K][N]];
	}
	int res;
	for (int i = 1; i < N; i++)
	{
		res = max(dp[K][N - i], dp[K - 1][i - 1]) + 1;
	}
	st[dp[K][N]] = res;
	return res;
	//转换思路
	vector<vector<int>>dp(K, vector<int>(N, 0));
	int m = 0;
	while (dp[K][m] < N)
	{
		m++;
		for (int k = 0; k <= K; k++)
		{
			dp[k][m] = dp[k][m - 1] + dp[k - 1][m - 1] + 1;//没碎看上面，碎了看下面
		}
	}
	return m;

}