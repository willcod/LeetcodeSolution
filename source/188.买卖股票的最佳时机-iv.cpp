/*
 * @lc app=leetcode.cn id=188 lang=cpp
 *
 * [188] 买卖股票的最佳时机 IV
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (k > n/2) {
            return maxP(prices);
        }

        vector<vector<int>> f(k+1, vector<int>(n, 0));

        for (int i = 1; i <= k; i++) {
            int pre = f[i-1][0] - prices[0];
            for (int j = 1; j < n; j++) {
                f[i][j] = max(f[i][j-1], prices[j]+pre);
                pre = max(pre, f[i-1][j] - prices[j]);
            }
        }
        return f[k][n-1];
    }

    int maxP(vector<int>& prices) {
        int profit = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > prices[i-1])
                profit += prices[i] - prices[i-1];
        }

        return profit;
    }
};
// @lc code=end

