/*
 * @lc app=leetcode.cn id=407 lang=cpp
 *
 * [407] 接雨水 II
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
   public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        if (heightMap.empty() || heightMap[0].empty()) return 0;
        int m = heightMap.size();
        int n = heightMap[0].size();

        vector visited(m, vector(n, false));
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            que;

        int water = 0;
        int Max = INT_MIN;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!(i == 0 || i == m - 1 || j == 0 || j == n - 1)) continue;
                que.push({heightMap[i][j], {i, j}});
                visited[i][j] = 1;
            }
        }
        vector<vector<int>> dir{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        while (!que.empty()) {
            auto pillar = que.top();
            que.pop();
            int height = pillar.first;
            int x = pillar.second.first, y = pillar.second.second;
            Max = max(Max, height);
            for (auto d : dir) {
                int dx = x + d[0], dy = y + d[1];
                if (dx >= m || dx < 0 || dy < 0 || dy >= n || visited[dx][dy])
                    continue;
                visited[dx][dy] = 1;
                if (heightMap[dx][dy] < Max) water += Max - heightMap[dx][dy];
                que.push({heightMap[dx][dy], {dx, dy}});
            }
        }
        return water;
    }
};
// @lc code=end
