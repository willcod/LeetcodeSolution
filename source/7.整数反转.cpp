/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
   public:
    int reverse(int x) {

        long result = 0;

        while (abs(x) >= 1) {
            result *= 10;
            result += x % 10;
            x /= 10;
        }
        if (abs(result) >= INT_MAX) return 0;
        return result;
    }
};
// @lc code=end
