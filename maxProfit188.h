#pragma once
#include "common.h" 
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }

        int n = prices.size();
        k = min(k, n / 2);
        vector<int> buy(k + 1);
        vector<int> sell(k + 1);

        buy[0] = -prices[0];
        sell[0] = 0;
        for (int i = 1; i <= k; ++i) {
            buy[i] = sell[i] = INT_MIN / 2;
        }

        for (int i = 1; i < n; ++i) {
            buy[0] = max(buy[0], sell[0] - prices[i]);
            for (int j = 1; j <= k; ++j) {
                //手上持有的股票是第i天买的 则前一天是没有股票的 则对应buy[j]就应该为前一天卖出的钱减去今天买股票的钱
                //以及不是当天买的 则返回的是前一天买股票的状态
                buy[j] = max(buy[j], sell[j] - prices[i]);
                //对于sell是当天卖出的话 则i-1我们手上是持有股票的 对于buy[j-1]则需要增加当天的收益，
                //当天不卖的话 那么在i-1天我们手上是没有股票的，对应sell[j]


                sell[j] = max(sell[j], buy[j - 1] + prices[i]);
            }
        }

        return *max_element(sell.begin(), sell.end());
    }
};

