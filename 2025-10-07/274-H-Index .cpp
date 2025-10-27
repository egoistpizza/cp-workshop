//
// Created by egoistpizza on 7.10.2025.
//

// 274. H-Index
// https://leetcode.com/problems/h-index/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int> count(n+1,0);

        for (int c : citations){
            if (c >= n) count[n]++;
            else count[c]++;
        }

        int papers = 0;
        for (int h = n; h >= 0; h--){
            papers += count[h];
            if (papers >= h){
                return h;
            }
        }
        return 0;
    }
};
