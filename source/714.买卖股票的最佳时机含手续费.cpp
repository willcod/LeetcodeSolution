/*
 * @lc app=leetcode.cn id=714 lang=cpp
 *
 * [714] 买卖股票的最佳时机含手续费
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
   public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        if (n < 2) return 0;

        vector buy(n, 0), sell(n, 0);
        buy[0] = -prices[0] - fee;
        sell[0] = 0;

        for (int i = 1; i < n; i++) {
            buy[i] = max(buy[i - 1], sell[i - 1] - prices[i] - fee);
            sell[i] = max(sell[i - 1], buy[i - 1] + prices[i]);
        }

        return sell[n - 1];
    }
};
// @lc code=end
