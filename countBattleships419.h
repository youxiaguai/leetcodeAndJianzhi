#pragma once
#include "common.h"
int countBattleships(vector<vector<char>>& board) {
    int R = board.size(), C = board[0].size(), res = 0;
    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j)
            if (board[i][j] == 'X' &&
                (!i || board[i - 1][j] == '.') && (!j || board[i][j - 1] == '.'))
                ++res;
    return res;

    
}