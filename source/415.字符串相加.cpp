/*
 * @lc app=leetcode.cn id=415 lang=cpp
 *
 * [415] 字符串相加
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
   public:
    string addStrings(string num1, string num2) {
        int i = num1.size() - 1;
        int j = num2.size() - 1;

        int sum = 0;
        string str;
        while (i >= 0 || j >= 0 || sum) {
            if (i >= 0) sum += num1[i--] - '0';
            if (j >= 0) sum += num2[j--] - '0';

            str.insert(0, 1, sum % 10 + '0');
            sum /= 10;
        }

        return str;
    }
};
// @lc code=end
