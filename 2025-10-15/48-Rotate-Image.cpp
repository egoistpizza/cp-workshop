//
// Created by egoistpizza on 15.10.2025.
//

// 48. Rotate Image
// https://leetcode.com/problems/rotate-image/
// * Microsoft Interview Question *

// Time: O(n^2)
// Memory: O(1)

// # Rotate by 4 Solution

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        int l = 0;
        int r = matrix.size() - 1;

        while ( l < r ) {

            for(int i = 0; i < r - l; i++) {
                int top = l;
                int bottom = r;

                int topLeft = matrix[top][l + i];

                matrix[top][l + i] = matrix[bottom - i][l];
                matrix[bottom - i][l] = matrix[bottom][r - i];
                matrix[bottom][r - i] = matrix[top + i][r];
                matrix[top + i][r] = topLeft;
            }
            r--;
            l++;
        }
    }
};

// # Reverse + Transpose Matrix Solution

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        reverse(matrix.begin(), matrix.end());

        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = i + 1; j < matrix[i].size(); ++j)
                swap(matrix[i][j], matrix[j][i]);
        }
    }
};
