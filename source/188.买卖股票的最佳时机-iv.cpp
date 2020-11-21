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
        if (n < 2) return 0;

        if (k > n/2) {
            return maxProfit(prices);
        }

        vector f(k+1, vector(n, 0));
        for (int i = 1; i <= k; i++) {
            int pre = f[i-1][0] - prices[0];
            for (int j = 1; j < n; j++) {
                f[i][j] = max(f[i][j-1], prices[j] + pre);
                pre = max(f[i-1][j] - prices[j], pre);
            }
        }

        return f[k][n-1];
    }

    int maxProfit(vector<int>& prices) {
        int res = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > prices[i-1]) {
                res += prices[i] - prices[i-1];
            }
        }
        return res;
    }
};
// @lc code=end

