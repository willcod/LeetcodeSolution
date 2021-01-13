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
        int lowest = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            lowest = min(lowest, prices[i]);
            profit = max(profit, prices[i] - lowest);
        }
        return profit;
    }
};
// @lc code=end
