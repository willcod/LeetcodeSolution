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

        int left = 0, right =0, maxlen = 0;

        unordered_set<char> set;
        while (left < s.length() && right < s.length()) {
            if (set.count(s[right]) == 0) {
                set.insert(s[right]);
                right++;
                maxlen = max(maxlen, right - left);
            } else {
                set.erase(s[left]);
                left++;
            }
        }

        return maxlen;
    }
};
// @lc code=end

