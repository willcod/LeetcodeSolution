/*
 * @lc app=leetcode.cn id=980 lang=cpp
 *
 * [980] 不同路径 III
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int sx = 0, sy = 0;
        int total = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    sx = i;
                    sy = j;
                }

                if (grid[i][j] != -1) {
                    total++;
                }
            }
        }

        return find(grid, sx, sy, 1, total);
    }
    bool isValid(vector<vector<int>>& grid, int x, int y) {
        return x >= 0 && y >= 0 && x < grid.size() && y < grid[0].size();
    }
    int find(vector<vector<int>>& grid, int x, int y, int step, int total) {
        if (!isValid(grid, x, y) || grid[x][y] == -1) return 0;
        if (grid[x][y] == 2) return step == total? 1 : 0;

        grid[x][y] =-1;
        int path = find(grid, x-1, y, step+1, total) +
        find(grid, x+1, y, step+1, total) +
        find(grid, x, y-1, step+1, total) +
        find(grid, x, y+1, step+1, total);
        grid[x][y] = 0;
        return path;
    }
};
// @lc code=end

