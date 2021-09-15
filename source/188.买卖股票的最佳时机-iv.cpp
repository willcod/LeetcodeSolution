/*
 * @lc app=leetcode.cn id=188 lang=cpp
 *
 * [188] 买卖股票的最佳时机 IV
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
   public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;

        vector f(k + 1, vector(n, 0));
        for (int i = 1; i <= k; i++) {
            int lastbuy = f[i - 1][0] - prices[0];
            for (int j = 1; j < n; j++) {
                f[i][j] = max(f[i][j - 1], lastbuy + prices[j]);
                lastbuy = max(lastbuy, f[i - 1][j] - prices[j]);
            }
        }

        return f[k][n - 1];
    }
};
// @lc code=end
