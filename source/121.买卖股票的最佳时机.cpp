/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int minP = INT_MAX;

        for (int i = 0; i < prices.size(); i++) {
            profit = max(profit, prices[i] - minP);
            minP = min(prices[i], minP);
        }

        return profit;
    }
};
// @lc code=end
