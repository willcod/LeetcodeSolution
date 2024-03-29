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

        int sign = 1;
        int result = 0;

        if (s[i] == '+' || s[i] == '-') sign = s[i++] == '+' ? 1 : -1;

        int guard = INT_MAX / 10;

        while (isdigit(s[i])) {
            if (result > guard || result == guard && s[i] > '7') {
                return sign > 0 ? INT_MAX : INT_MIN;
            }

            result = 10 * result + (s[i++] - '0');
        }

        return sign * result;
    }
};
// @lc code=end
