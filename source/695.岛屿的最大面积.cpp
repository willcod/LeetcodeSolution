/*
 * @lc app=leetcode.cn id=695 lang=cpp
 *
 * [695] 岛屿的最大面积
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int row = grid.size();
        int col = grid[0].size();

        int maxArea = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 1) {
                    maxArea = max(maxArea, getArea(grid, i, j));
                }
            }
        }
        return maxArea;
    }

    int getArea(vector<vector<int>>& grid, int x, int y) {
        if (!isValid(grid, x, y)) return 0;

        if (grid[x][y] == 1) {
            grid[x][y] = 0;
            return 1 + getArea(grid, x+1, y)
                     + getArea(grid, x-1, y)
                     + getArea(grid, x, y+1)
                     + getArea(grid, x, y-1);
        } else {
            return 0;
        }
    }

    bool isValid(vector<vector<int>>& grid, int x, int y) {
        return x >= 0 && y >= 0 && x < grid.size() && y < grid[0].size();
    }
};
// @lc code=end

