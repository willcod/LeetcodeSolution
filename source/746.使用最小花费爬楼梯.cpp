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
        vector f(n, 0);
        f[0] = cost[0];
        f[1] = cost[1];

        for (int i = 2; i < n; i++) {
            f[i] = cost[i] + min(f[i - 2], f[i - 1]);
        }
        return min(f[n - 1], f[n - 2]);
    }
};
// @lc code=end
