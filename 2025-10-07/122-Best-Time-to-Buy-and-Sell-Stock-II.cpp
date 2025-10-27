//
// Created by egoistpizza on 7.10.2025.
//

// 122. Best Time to Buy and Sell Stock II
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int total = 0;

        for (int i = 1; i < prices.size(); i++){
            if (prices[i] > prices[i-1]){
                total += prices[i] - prices[i-1];
            }
        }
        return total;
    }
};
