/*
 * @lc app=leetcode.cn id=309 lang=cpp
 *
 * [309] 最佳买卖股票时机含冷冻期
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n < 2) return 0;

        vector buy(n, 0), sell(n, 0), rest(n, 0);
        buy[0] = -prices[0];
        sell[0] = 0;
        rest[0] = INT_MIN;

        for (int i = 1; i < n; i++) {
            sell[i] = max(sell[i-1], rest[i-1]);
            buy[i] = max(buy[i-1], sell[i-1] - prices[i]);
            rest[i] = max(sell[i-1], buy[i-1] + prices[i]);
        }

        return max(sell[n-1], rest[n-1]);
    }
};
// @lc code=end

