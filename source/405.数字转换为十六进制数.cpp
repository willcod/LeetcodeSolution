/*
 * @lc app=leetcode.cn id=405 lang=cpp
 *
 * [405] 数字转换为十六进制数
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
public:
    string toHex(int num) {
        string hexStr = "";
        string table = "0123456789abcdef";

        unsigned int n = num;

        do {
            hexStr = table[n%16] + hexStr;
            n /= 16;
        } while (n > 0);

        return hexStr;
    }
};
// @lc code=end

