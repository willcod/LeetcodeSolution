/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) return 0;

        int mp = 0;

        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > prices[i - 1]) {
                mp += prices[i] - prices[i - 1];
            }
        }

        return mp;
    }
};
// @lc code=end
