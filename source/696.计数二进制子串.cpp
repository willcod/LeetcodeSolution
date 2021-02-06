/*
 * @lc app=leetcode.cn id=696 lang=cpp
 *
 * [696] 计数二进制子串
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
   public:
    int countBinarySubstrings(string s) {
        int res = 0;
        int pre = 0;
        int cur = 1;
        for (int i = 0; i < s.length() - 1; i++) {
            if (s[i] == s[i + 1]) {
                cur++;
            } else {
                pre = cur;
                cur = 1;
            }

            if (pre >= cur) res++;
        }
        return res;
    }
};
// @lc code=end
