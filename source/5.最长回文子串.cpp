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
        int n = s.length();
        if (n < 2) return s;

        int leftmost = 0;
        int maxlen = 0;

        int mid = 0;
        while (mid < n) {
            int left = mid;
            int right = mid;

            while (right < n &&s[right+1] == s[right]) right++;
            mid = right + 1;
            
            while (right < n && left > 0 && s[right+1] == s[left-1]) {
                right++;
                left--;
            }

            int len = right - left + 1;
            if (len > maxlen) {
                maxlen = len;
                leftmost = left;
            }
        }

        return s.substr(leftmost, maxlen);
    }
};
// @lc code=end
