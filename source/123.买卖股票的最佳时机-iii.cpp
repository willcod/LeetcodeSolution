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
        if (prices.size() < 2) return 0;
        int n = prices.size();

        int K = 2;
        vector f(K+1, vector(n, 0));

        for (int k = 1; k <=K; k++) {
            int preBuy = f[k-1][0] - prices[0];
            for (int i = 1; i < n; i++) {
                f[k][i] = max(f[k][i-1], prices[i]+preBuy);
                preBuy = max(f[k-1][i] - prices[i], preBuy);
            }
        }
    }
};
// @lc code=end

