/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
   public:
    int myAtoi(string s) {
        int i = s.find_first_not_of(' ');
        if (s.empty() || i == -1) return 0;

        int res = 0;
        int sign = 1;
        int base = INT_MAX / 10;

        if (s[i] == '+' || s[i] == '-') sign = s[i++] == '+' ? 1 : -1;

        while (isdigit(s[i])) {
            if (res > base || (res == base && s[i] > '7')) {
                return sign > 0 ? INT_MAX : INT_MIN;
            }
            res = 10 * res + (s[i++] - '0');
        }
        return res * sign;
    }
};
// @lc code=end
