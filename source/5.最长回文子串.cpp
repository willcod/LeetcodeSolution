/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
   public:
    string longestPalindrome(string s) {
        if (s.length() < 2) return s;
        int n = s.length() - 1;
        int lo = 0;
        int max_len = 1;

        int mid = 0;
        while (mid < n) {
            int left = mid;
            int right = mid;
            while (right < n && s[right + 1] == s[right]) right++;
            mid = right + 1;
            while (right < n && left > 0 && s[left - 1] == s[right + 1]) {
                left--;
                right++;
            }

            int len = right - left + 1;
            if (len > max_len) {
                max_len = len;
                lo = left;
            }
        }
        return s.substr(lo, max_len);
    }
};
// @lc code=end
