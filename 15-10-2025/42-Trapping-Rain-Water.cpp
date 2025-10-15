//
// Created by egoistpizza on 15.10.2025.
//

// 42. Trapping Rain Water
// https://leetcode.com/problems/trapping-rain-water/
// * Google Interview Question *

// Time: O(n)
// Memory: O(1)

// # Two Pointers Solution

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) {
            return 0;
        }

        int l = 0, r = height.size() - 1;
        int leftMax = height[l], rightMax = height[r];
        int res = 0;

        while (l < r) {
            if (leftMax < rightMax) {
                l++;
                leftMax = max(leftMax, height[l]);
                res += leftMax - height[l];
            } else {
                r--;
                rightMax = max(rightMax, height[r]);
                res += rightMax - height[r];
            }
        }
        return res;
    }
};
