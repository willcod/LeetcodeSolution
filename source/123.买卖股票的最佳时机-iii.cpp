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
        int n = prices.size();

        vector f(3, vector(n, 0));

        for (int k = 1; k <= 2; k++) {
            int lastbuy = f[k-1][0] - prices[0];
            for (int i = 1; i < n; i++) {
                f[k][i] = max(f[k][i-1], lastbuy+prices[i]);
                lastbuy = max(lastbuy, f[k-1][i]-prices[i]);
            }
        }

        return f[2][n-1];
    }
};
// @lc code=end

