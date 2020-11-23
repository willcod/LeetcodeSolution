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
        int sold = 0;
        int hold = INT_MIN;
        int rest = 0;

        for (int i = 0; i < prices.size(); i++) {
            int preSold = sold;
            sold = hold + prices[i];
            hold = max(hold, rest - prices[i]);
            rest = max(rest, preSold);
        }

        return max(sold, rest);
    }
};
// @lc code=end
