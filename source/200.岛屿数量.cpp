/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
   public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    count++;
                    flood(grid, i, j);
                }
            }
        }
        return count;
    }

    void flood(vector<vector<char>>& grid, int x, int y) {
        if (!isValid(grid, x, y)) return;

        if (grid[x][y] == '1') {
            grid[x][y] = '0';

            flood(grid, x - 1, y);
            flood(grid, x + 1, y);
            flood(grid, x, y - 1);
            flood(grid, x, y + 1);
        }
    }

    bool isValid(vector<vector<char>>& grid, int x, int y) {
        return x >= 0 && y >= 0 && x < grid.size() && y < grid[0].size();
    }
};
// @lc code=end
