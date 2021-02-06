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
        int begin = 0;
        int maxlen = 1;

        int n = s.length();
        int mid = 0;
        while (mid < n) {
            int left = mid;
            int right = mid;
            while (right < n && s[right] == s[right + 1]) right++;

            mid = right + 1;
            while (left > 0 && right < n && s[left-1] == s[right+1]) {
                left--;
                right++;
            }
            int len = right - left + 1;
            if (len > maxlen) {
                maxlen = len;
                begin = left;
            }
        }
        return s.substr(begin, maxlen);
    }
};
// @lc code=end
