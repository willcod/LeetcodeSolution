/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现 strStr()
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.length();
        int n = needle.length();

        if (n == 0) return 0;

        for (int i = 0; i <= m - n; i++) {
            if (haystack.substr(i, n) == needle) {
                return i;
            }
        }

        return -1;
    }
};
// @lc code=end

