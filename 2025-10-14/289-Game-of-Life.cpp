//
// Created by egoistpizza on 11.10.2025.
//

// 289. Game of Life
// https://leetcode.com/problems/game-of-life/
// * Amazon Interview Question *

// Time: O(n*m)
// Memory: O(1)

// # Solution with State Tagging

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        if (board.empty() || board[0].empty()) {
            return;
        }

        int m = board.size();
        int n = board[0].size();

        vector<pair<int, int>> directions = {
            {1, 0}, {-1, 0}, {0, 1}, {0, -1},
            {-1, 1}, {-1, -1}, {1, 1}, {1, -1}
        };

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int live_neighbors = 0;

                for (auto& dir : directions) {
                    int neighbor_i = i + dir.first;
                    int neighbor_j = j + dir.second;

                    bool is_in_bounds = (neighbor_i >= 0 && neighbor_i < m && neighbor_j >= 0 && neighbor_j < n);

                    if (is_in_bounds) {
                        if (board[neighbor_i][neighbor_j] == 1 || board[neighbor_i][neighbor_j] == 3) {
                            live_neighbors++;
                        }
                    }
                }

                bool was_alive = (board[i][j] == 1);

                if (was_alive) {
                    if (live_neighbors == 2 || live_neighbors == 3) {
                        board[i][j] = 3;
                    }
                } else {
                    if (live_neighbors == 3) {
                        board[i][j] = 2;
                    }
                }
            }
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 2 || board[i][j] == 3) {
                    board[i][j] = 1;
                } else {
                    board[i][j] = 0;
                }
            }
        }
    }
};



// # Solution with Bit Manipulation

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int countLiveNeighbors(const vector<vector<int>>& board, int m, int n, int i, int j) {

        int live_neighbors = 0;

        static const int directions[8][2] = {
            {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}
        };

        for (const auto& dir : directions) {
            int r = i + dir[0];
            int c = j + dir[1];

            if (r >= 0 && r < m && c >= 0 && c < n && (board[r][c] & 1)) {
                live_neighbors++;
            }
        }
        return live_neighbors;
    }

public:
    void gameOfLife(vector<vector<int>>& board) {
        if (board.empty() || board[0].empty()) {
            return;
        }

        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int live_neighbors = countLiveNeighbors(board, m, n, i, j);

                if (board[i][j] & 1) {
                    if (live_neighbors == 2 || live_neighbors == 3) {
                        board[i][j] |= 2;
                    }
                } else {
                    if (live_neighbors == 3) {
                        board[i][j] |= 2;
                    }
                }
            }
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                board[i][j] >>= 1;
            }
        }
    }
};
