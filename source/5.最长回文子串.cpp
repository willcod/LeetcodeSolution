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
        
        int mid = 0;
        int begin = 0;
        int max_len = 1;
        while (mid < s.length()) {
            int left = mid, right = mid;

            while (right + 1 < s.length() && s[right] == s[right+1]) right++;
            mid = right + 1;
            while (right + 1 < s.length() && left > 0 && s[right+1] == s[left-1]) {
                left--;
                right++;
            }

            int new_len = right - left + 1;
            if (new_len > max_len) {
                begin = left;
                max_len = new_len;
            }
        }
        return s.substr(begin, max_len);
    }
};
// @lc code=end

