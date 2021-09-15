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
        if (needle.empty()) return 0;
        if (haystack.length() < needle.length()) return -1;

        for (int i = 0; i <= (haystack.length() - needle.length()); i++) {
            if (haystack.substr(i, needle.length()) == needle) return i;
        }

        return -1;
    }
};
// @lc code=end
