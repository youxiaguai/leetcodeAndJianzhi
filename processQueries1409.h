#pragma once
#include "common.h"
#include <numeric>
vector<int> processQueries(vector<int>& queries, int m) {
    vector<int> p(m);
    //p���ֵΪ1....m
    iota(p.begin(), p.end(), 1);
    vector<int> ans;
    for (int query : queries) {
        int pos = -1;
        for (int i = 0; i < m; ++i) {
            if (p[i] == query) {
                pos = i;
                break;
            }
        }
        ans.push_back(pos);
        p.erase(p.begin() + pos);
        p.insert(p.begin(), query);
    }
    return ans;

    

}
