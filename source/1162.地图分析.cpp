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
        int m = grid.size();
        int n = grid[0].size();
        // 先把所有的陆地都入队。
        queue<vector<int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                }
            }
        }
        // 从各个陆地开始，一圈一圈的遍历海洋，最后遍历到的海洋就是离陆地最远的海洋。
        bool hasOcean = false;
        vector<int> lastOcean(2, 0);
        while (!q.empty()) {
            lastOcean = q.front();
            q.pop();
            int x = lastOcean[0];
            int y = lastOcean[1];
            // 取出队列的元素，将其四周的海洋入队。
            for (int i = 0; i < 4; i++) {
                int newX = x + offset[i][0];
                int newY = y + offset[i][1];

                if (!isValid(n, newX, newY) || grid[newX][newY] != 0) continue;

                grid[newX][newY] = grid[x][y] + 1;
                hasOcean = true;
                q.push({newX, newY});
            }
        }
        // 没有陆地或者没有海洋，返回-1。
        if (lastOcean.empty() || !hasOcean) return -1;
        // 返回最后一次遍历到的海洋的距离。
        return grid[lastOcean[0]][lastOcean[1]] - 1;
    }

    bool isValid(int n, int x, int y) {
        return x >= 0 && y >= 0 && x < n && y < n;
    }

   private:
    const int offset[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
};
// @lc code=end
