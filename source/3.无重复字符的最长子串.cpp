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
        int left = 0;
        int right = 0;
        unordered_set<char> ss;
        int maxCount = 0;
        while (left < s.length() && right < s.length()) {
            if (!ss.count(s[right])) {
                ss.insert(s[right]);
                right++;
                maxCount = max(maxCount, right - left);
            } else {
                ss.erase(s[left]);
                left++;
            }
        }
        return maxCount;
    }
};
// @lc code=end
