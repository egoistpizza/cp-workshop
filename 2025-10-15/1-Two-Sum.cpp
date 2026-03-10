//
// Created by egoistpizza on 15.10.2025.
//

// 1. Two Sum
// https://leetcode.com/problems/two-sum/

// Time: O(n)
// Memory O(n)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); i++) {
            if (mp.find(target - nums[i]) != mp.end()) {
                return {mp[target - nums[i]], i};
            }
            mp[nums[i]] = i;
        }

        return {};
    }
};
