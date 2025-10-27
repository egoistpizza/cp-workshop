//
// Created by egoistpizza on 8.10.2025.
//

// 11. Container With Most Water
// https://leetcode.com/problems/container-with-most-water/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {

        int left = 0, right = height.size() - 1;
        int max_area = 0;

        while (left < right) {
            max_area = max(max_area, (right - left) * min(height[left], height[right]));

            if (height[left] < height[right]) left++;

            else right--;
        }
        return max_area;
    }
};
