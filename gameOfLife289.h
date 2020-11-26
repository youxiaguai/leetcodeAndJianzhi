#pragma once
#include "common.h"
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int neighbors[3] = { 0, 1, -1 };

        int rows = board.size();
        int cols = board[0].size();

        // �������ÿһ���������ϸ��
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {

                // ����ÿһ��ϸ��ͳ����˸�����λ����Ļ�ϸ������
                int liveNeighbors = 0;

                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {

                        if (!(neighbors[i] == 0 && neighbors[j] == 0)) {
                            // ����λ�õ�����
                            int r = (row + neighbors[i]);
                            int c = (col + neighbors[j]);

                            // �鿴���ڵ�ϸ���Ƿ��ǻ�ϸ��
                            if ((r < rows && r >= 0) && (c < cols && c >= 0) && (abs(board[r][c]) == 1)) {
                                liveNeighbors += 1;
                            }
                        }
                    }
                }

                // ���� 1 ����� 3 
                if ((board[row][col] == 1) && (liveNeighbors < 2 || liveNeighbors > 3)) {
                    // -1 �������ϸ����ȥ�ǻ����������
                    board[row][col] = -1;
                }
                // ���� 4
                if (board[row][col] == 0 && liveNeighbors == 3) {
                    // 2 �������ϸ����ȥ���������ڻ���
                    board[row][col] = 2;
                }
            }
        }

        // ���� board �õ�һ�θ��º��״̬
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (board[row][col] > 0) {
                    board[row][col] = 1;
                }
                else {
                    board[row][col] = 0;
                }
            }
        }
    }
};

