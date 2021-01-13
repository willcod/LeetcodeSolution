/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
   public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount < 1) return 0;
        vector f(amount + 1, amount + 1);
        f[0] = 0;

        for (int i = 0; i <= amount; i++) {
            for (int c : coins) {
                if (i >= c) {
                    f[i] = min(f[i], f[i - c] + 1);
                }
            }
        }
        return f[amount] == amount + 1 ? -1 : f[amount];
    }
};
// @lc code=end
