/*
 * @lc app=leetcode.cn id=633 lang=cpp
 *
 * [633] 平方数之和
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
   public:
    bool judgeSquareSum(int c) {
        for (long a = 0; a * a <= c; a++) {
            double b = sqrt(c - a * a);
            if (b == (long)b) return true;
        }
        return false;
    }
};
// @lc code=end
