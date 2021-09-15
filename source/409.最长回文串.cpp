/*
 * @lc app=leetcode.cn id=409 lang=cpp
 *
 * [409] 最长回文串
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
   public:
    int longestPalindrome(string s) {
        vector<int> count(128, 0);
        for (auto c : s) {
            count[c]++;
        }

        int len = 0;
        for (auto cnt : count) {
            len += cnt - (cnt & 1);
        }

        return len < s.length() ? len + 1 : len;
    }
};
// @lc code=end
