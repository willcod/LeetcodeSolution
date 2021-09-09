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
        int min = prices[0];
        int max = 0;
        for (int i = 1; i < prices.size(); i++) {
            max = std::max(max, prices[i] - min);
            min = std::min(min, prices[i]);
        }

        return max;
    }
};
// @lc code=end

