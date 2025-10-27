//
// Created by egoistpizza on 17.10.2025.
//

// 56. Merge Intervals
// https://leetcode.com/problems/merge-intervals/
// * Microsoft Interview Question *

// Time: O(n) -> w/sorting -> O(nlogn)
// Memory: O(1) -> w/sorting -> O(logn) *not defined / O(n) for output list

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end());
        vector<vector<int>> output;
        output.push_back(intervals[0]);

        for (auto& interval : intervals) {
            int start = interval[0];
            int end = interval[1];
            int lastEnd = output.back()[1];

            if (start <= lastEnd) {
                output.back()[1] = max(lastEnd, end);
            } else {
                output.push_back({start, end});
            }
        }
        return output;
    }
};
