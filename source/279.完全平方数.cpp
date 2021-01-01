/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
   public:
    int numSquares(int n) {
        vector f(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            f[i] = i;
            for (int j = 1; i - j * j >= 0; j++) {
                f[i] = min(f[i], f[i - j * j] + 1);
            }
        }

        return f[n];
    }
};
// @lc code=end
