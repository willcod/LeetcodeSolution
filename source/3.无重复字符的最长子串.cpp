/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if (n < 2) return n;

        int start = 0;
        int end = 0;
        int maxlen = 1;

        unordered_set<char> set;
        while (start < n && end < n) {
            if (set.count(s[end]) == 0) {
                set.insert(s[end]);
                end++;
                maxlen = max(maxlen, end - start);
            } else {
                set.erase(s[start++]);
            }
        }

        return maxlen;
    }
};
// @lc code=end
