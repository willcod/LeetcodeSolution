/*
 * @lc app=leetcode.cn id=371 lang=cpp
 *
 * [371] 两整数之和
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
   public:
    int getSum(int a, int b) {
        while (b) {
            auto carry = (unsigned)(a & b) << 1;
            a ^= b;
            b = carry;
        }

        return a;
    }
};
// @lc code=end
