#pragma once
#include "common.h"


class SubrectangleQueries {
private:
    vector<vector<int>> rectang;
public:
    SubrectangleQueries(vector<vector<int>>& rectangle) {
        rectang = rectangle;
    }
   
    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        for (int i = row1; i <= row2; i++)
        {
            for (int j = col1; j <=col2; j++)
            {
                rectang[i][j] = newValue;

            }
        }
    }

    int getValue(int row, int col) {
        return rectang[row][col];
    }
};
