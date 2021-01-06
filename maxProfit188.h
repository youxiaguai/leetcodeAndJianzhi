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
                //���ϳ��еĹ�Ʊ�ǵ�i����� ��ǰһ����û�й�Ʊ�� ���Ӧbuy[j]��Ӧ��Ϊǰһ��������Ǯ��ȥ�������Ʊ��Ǯ
                //�Լ����ǵ������ �򷵻ص���ǰһ�����Ʊ��״̬
                buy[j] = max(buy[j], sell[j] - prices[i]);
                //����sell�ǵ��������Ļ� ��i-1���������ǳ��й�Ʊ�� ����buy[j-1]����Ҫ���ӵ�������棬
                //���첻���Ļ� ��ô��i-1������������û�й�Ʊ�ģ���Ӧsell[j]


                sell[j] = max(sell[j], buy[j - 1] + prices[i]);
            }
        }

        return *max_element(sell.begin(), sell.end());
    }
};

