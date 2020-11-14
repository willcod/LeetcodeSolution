/*
 * @lc app=leetcode.cn id=123 lang=cpp
 *
 * [123] 买卖股票的最佳时机 III
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;

        int n = prices.size();
        vector f(n, vector(3, vector(2, 0)));
        f[0][1][0] = 0;
        f[0][1][1] = -prices[0];
        f[0][2][0] = 0;
        f[0][2][1] = -prices[0];

        for (int i = 1; i < n; i++) {
            f[i][2][0] = max(f[i - 1][2][0], f[i - 1][2][1] + prices[i]);
            f[i][2][1] = max(f[i - 1][2][1], f[i - 1][1][0] - prices[i]);
            f[i][1][0] = max(f[i - 1][1][0], f[i - 1][1][1] + prices[i]);
            f[i][1][1] = max(f[i - 1][1][1], f[i - 1][0][0] - prices[i]);
        }

        return f[n - 1][2][0];
    }
};
// @lc code=end
