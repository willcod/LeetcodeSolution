/*
 * @lc app=leetcode.cn id=746 lang=cpp
 *
 * [746] 使用最小花费爬楼梯
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        if (n == 0) return 0;
        if (n == 1) return cost[0];
        if (n == 2) return min(cost[0], cost[1]);

        vector f(n, 0);
        f[0] = 0;
        f[1] = min(cost[0], cost[1]);
        for (int i = 2; i < n; i++) {
            cout << i << endl;
            f[i] = min(f[i-2]+cost[i-1], f[i-1]+cost[i]);
        }

        return f[n-1];
    }
};
// @lc code=end

