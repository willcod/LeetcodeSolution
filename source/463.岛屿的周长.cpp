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
        int land = 0;
        int edge = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    land++;

                    if (i > 0 && grid[i - 1][j] == 1) edge++;

                    if (j > 0 && grid[i][j - 1] == 1) edge++;
                }
            }
        }
        return land * 4 - edge * 2;
    }
};
// @lc code=end
