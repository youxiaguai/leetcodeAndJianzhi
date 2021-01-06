#pragma once
#include "common.h"
bool dfs(vector<vector<char>>& board, string& word, int i, int j, int w)
{
	if (word[w] != board[i][j])return false;
	if (w = word.length() - 1)return true;
	char temp = board[i][j]; board[i][j] = 0;
	if (((i - 1 >= 0) && dfs(board, word, i - 1, j, w + 1))
		|| ((j + 1 <= board[0].size() - 1) && dfs(board, word, i, j + 1, w + 1))
		|| ((i + 1 <= board.size() - 1) && dfs(board, word, i + 1, j, w + 1))
		|| ((j - 1 >= 0) && dfs(board, word, i, j - 1, w + 1)))
		return true;
	board[i][j] = temp;
	return false;
}
bool exist(vector<vector<char>>& board, string word) {
	int m = board.size();
	int n = board[0].size();
	vector<vector<bool>>flag(m, vector<bool>(n, true));//表示当前节点是否可以选择
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (dfs(board, word, i, j, 0))
				return true;
		}
	}
	return false;
}