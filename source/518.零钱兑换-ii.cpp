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
        int n = coins.size();
        vector f(amount + 1, 0);

        f[0] = 1;
        for (auto coin : coins) {
            for (int j = coin; j <= amount; j++) {
                f[j] += f[j - coin];
            }
        }
        return f[amount];
    }
};
// @lc code=end
