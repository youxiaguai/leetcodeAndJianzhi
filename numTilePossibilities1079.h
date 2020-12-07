#pragma once
#include "common.h"
class Solution {
    int ans = 0;
public:
    int numTilePossibilities(string tiles) {
        vector<int> mp(26, 0);
        for (char& ch : tiles) ++mp[ch - 'A'];
        for (int i = 0, j = 0; i < 26; ++i) if (mp[i] != 0) swap(mp[i], mp[j++]); //把数量是0的字母去掉
        mp.resize(tiles.size());
        dfs(mp);
        return ans;
    }

    void dfs(vector<int>& mp) {
        for (auto& p : mp) {
            if (p != 0) {
                --p;
                ++ans;
                dfs(mp);
                ++p;
            }
        }
    }
};

