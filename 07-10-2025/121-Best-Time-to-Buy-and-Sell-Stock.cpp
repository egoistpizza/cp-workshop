//
// Created by egoistpizza on 7.10.2025.
//

// 121. Best Time to Buy and Sell Stock
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int buy = prices[0];

        for (int sell : prices) {
            if (sell < buy) buy = sell;
            else if (sell - buy > maxProfit) maxProfit = sell - buy;
        }

        return maxProfit;

    }
};
