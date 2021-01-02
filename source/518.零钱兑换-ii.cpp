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
        vector f(n+1, vector(amount+1, 0));
        f[0][0] = 1;

        for (int i = 1; i <= n; i++) {
            f[i][0] = 1;
            for (int j = 1; j <= amount; j++) {
                f[i][j] = f[i-1][j];
                if (j >= coins[i-1]) {
                    f[i][j] += f[i][j-coins[i-1]];
                }
            }
        }
        return f[n][amount];
    }
};
// @lc code=end

