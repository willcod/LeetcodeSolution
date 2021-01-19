/*
 * @lc app=leetcode.cn id=1584 lang=cpp
 *
 * [1584] 连接所有点的最小费用
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
   public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>> pq;
        int n = points.size();
        vector<bool> vi(n, false);
        int ans = 0;

        pq.push({0, 0});
        while (!pq.empty() && n > 0) {
            auto [d, p1] = pq.top();
            pq.pop();
            if (vi[p1]) continue;

            ans += d;
            vi[p1] = true;
            n--;

            for (int p2 = 0; p2 < points.size(); p2++) {
                if (vi[p2]) continue;
                int dis = abs(points[p1][0] - points[p2][0]) +
                          abs(points[p1][1] - points[p2][1]);
                pq.push({dis, p2});
            }
        }
        return ans;
    }
};
// @lc code=end
