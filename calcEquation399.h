#pragma once
#include "common.h"
double dfs(vector<vector<int>>& g, vector<bool>& visit, int from, int to)
{
	if (from == to)return 1.0;
	double ans = -1;
	for (int i = 0; i < g.size(); i++)
	{
		if (i == from || visit[i])continue;
		if (g[from][i] > 0)
		{
			visit[i] = true;
			double res = dfs(g, visit, i, to);
			visit[i] = false;
			if (res > 0)ans = g[from][i] * res;
		}
		
	}
	return ans;
}
vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
	if (queries.empty())return {};
	unordered_map<string, int>wordId;
	int n = 0;
	for (vector<string>& i : equations)
	{
		if (!wordId.count(i[0]))
		{
			wordId[i[0]] = n++;
		}
		if (!wordId.count(i[1]))
		{
			wordId[i[1]] = n++;
		}
	}
	vector<vector<double>>g(n, vector<double>(n, 0));
	for (int i = 0; i < values.size(); i++)
	{
		int from = wordId[equations[i][0]], to = wordId[equations[i][1]];
		g[from][to] = values[i];
		if (values[i] != 0)
		{
			g[to][from] = 1.0 / values[i];
		}
	}
	vector <bool>visit(n, false);
	vector<double>ans;
	for (vector<string>& query : queries)
	{
		if (!wordId.count(query[0]) || !wordId.count(query[1]))
		{
			ans.push_back(-1);
			continue;
		}

		int from = wordId[query[0]], to = wordId[query[1]];
		fill(visit.begin(), visit.end(), 0);
		cout << from << "," << to << endl;
		for(bool i:visit)
		{
			cout << i << ",";
		}
		cout << endl;
		ans.push_back(dfs(g, visit, from, to));
	}
	return ans;
}