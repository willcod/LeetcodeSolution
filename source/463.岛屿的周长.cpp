/*
 * @lc app=leetcode.cn id=463 lang=cpp
 *
 * [463] 岛屿的周长
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
   public:
    int islandPerimeter(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;

        int land = 0;
        int edge = 0;
        int m = grid.size();
        int n = grid[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    land++;
                    if (i > 0 && grid[i - 1][j]) edge++;
                    if (j > 0 && grid[i][j - 1]) edge++;
                }
            }
        }

        return land * 4 - edge * 2;
    }
};
// @lc code=end
