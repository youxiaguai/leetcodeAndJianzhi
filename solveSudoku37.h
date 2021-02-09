#pragma once
#include "common.h"
bool isValid(vector<vector<char>>& board, int r, int c, char n)
{
	for (int i = 0; i < 9; i++)
	{
		if (board[r][i] == n)return false;
		if (board[i][c] == n)return false;
		if (board[(r/3)* 3 + i /3][(c/3)*3+i%3]==n){
			return false;
		}
	}
	return true;
}
bool backtrack(vector<vector<char>>& board, int i, int j)
{
	int m = 9, n = 9;
	if (j == n)
	{
		backtrack(board, i + 1, 0);
		return;
	}
	if (i == m)
	{
		return true;
	}
	if (board[i][j] == '.')
	{
		backtrack(board, i, j + 1);
		return;
	}
	for (char ch = '1'; ch <= '9'; ch++)
	{
		if (!isValid(board, i, j, ch))
		{
			continue;
		}
		board[i][j] = ch;
		if (backtrack(board, i, j + 1))
		{
			return true;
		}
		board[i][j] = '.';
	}
	return false;
}
void solveSudoku(vector<vector<char>>& board) {
	int m = board.size();
	int n = board[0].size();
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			backtrack(board, i, j);
			
		}
	}
}