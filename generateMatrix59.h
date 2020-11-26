#pragma once
#include "common.h"
vector<vector<int>> generateMatrix(int n) {
	vector<vector<int>>res(n, vector<int>(n, 0));
    int count = 1;
    int top = 0;
    int bottom = n - 1;
    int left = 0;
    int right = n - 1;

    while (true) {
        // fill top row
        for (int i = left; i <= right; i++) {
            res[top][i] = count++;
        }
        top++;
        if (top > bottom) {
            break;
        }

        // fill right col
        for (int j = top; j <= bottom; j++) {
            res[j][right] = count++;
        }
        right--;
        if (right < left) {
            break;
        }

        // fill bottom row
        for (int k = right; k >= left; k--) {
            res[bottom][k] = count++;
        }
        bottom--;
        if (bottom < top) {
            break;
        }

        // fill left col
        for (int l = bottom; l >= top; l--) {
            res[l][left] = count++;
        }
        left++;
        if (left > right) {
            break;
        }
    }

    return res;

   

}