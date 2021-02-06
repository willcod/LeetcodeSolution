/*
 * @lc app=leetcode.cn id=518 lang=cpp
 *
 * [518] 零钱兑换 II
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
   public:
    int change(int amount, vector<int>& coins) {
        vector f(amount + 1, 0);
        f[0] = 1;
        for (int coin : coins) {
            for (int i = coin; i <= amount; i++) {
                f[i] += f[i - coin];
            }
        }
        return f[amount];
    }
};
// @lc code=end
