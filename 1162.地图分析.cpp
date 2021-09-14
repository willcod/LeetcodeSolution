/*
 * @lc app=leetcode.cn id=1162 lang=cpp
 *
 * [1162] 地图分析
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
   public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();

        queue<vector<int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                }
            }
        }

        bool hasOcean = false;
        vector<int> p;
        while (!q.empty()) {
            p = q.front();
            q.pop();

            int x = p[0];
            int y = p[1];
            for (auto offset : fourDir) {
                int newX = x + offset[0];
                int newY = y + offset[1];

                if (newX < 0 || newY < 0 || newX >= n || newY >= n ||
                    grid[newX][newY] != 0)
                    continue;

                hasOcean = true;
                grid[newX][newY] = grid[x][y] + 1;

                q.push({newX, newY});
            }
        }

        if (p.empty() || !hasOcean) return -1;

        return grid[p[0]][p[1]] - 1;
    }

   private:
    int fourDir[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
};
// @lc code=end
