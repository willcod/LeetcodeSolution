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
        if (s.empty()) return 0;
        unordered_set<char> set;
        int start = 0;
        int end = 0;
        int maxlen = 0;

        while (end < s.length()) {
            if (set.count(s[end]) == 0) {
                set.insert(s[end]);
                end++;
                maxlen = max(maxlen, end - start);
            } else {
                set.erase(s[start]);
                start++;
            }
        }
        return maxlen;
    }
};
// @lc code=end
