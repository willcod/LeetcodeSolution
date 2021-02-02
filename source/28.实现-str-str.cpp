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
        if (needle == "") return 0;

        int hlen = haystack.length();
        int nlen = needle.length();
        for (int i = 0; i <= (hlen - nlen); i++) {
            if (haystack.substr(i, nlen) == needle) return i;
        }
        return -1;
    }
};
// @lc code=end
