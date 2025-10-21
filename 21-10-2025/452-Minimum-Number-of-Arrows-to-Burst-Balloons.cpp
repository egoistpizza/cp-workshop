//
// Created by egoistpizza on 17.10.2025.
//

// 452. Minimum Number of Arrows to Burst Balloons
// https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/

// Time: O(n) -> w/sorting -> O(nlogn)
// Memory: O(1) -> w/sorting -> O(logn) *not defined

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {

        sort(points.begin(), points.end());

        int arrows = points.size();
        vector<int> pre = points[0];

        for (int i = 1; i < points.size(); i++) {
            if (points[i][0] <= pre[1]) {
                arrows--;
                pre = {points[i][0], min(points[i][1], pre[1])};
            } else {
                pre = points[i];
            }
        }
        return arrows;
    }
};
