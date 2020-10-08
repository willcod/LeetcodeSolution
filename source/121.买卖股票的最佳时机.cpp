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
        int minPrice = INT_MAX;
        int profit = 0;

        for (auto p : prices) {
            profit = max(profit, p - minPrice);
            minPrice = min(minPrice, p);
        }

        return profit;
    }
};
// @lc code=end
