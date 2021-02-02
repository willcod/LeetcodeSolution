/*
 * @lc app=leetcode.cn id=424 lang=cpp
 *
 * [424] 替换后的最长重复字符
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
   public:
    int characterReplacement(string s, int k) {
        vector count(128, 0);
        int n = s.length();
        int maxlen = 0;
        int left = 0, right = 0;

        while (right < n) {
            count[s[right]]++;
            maxlen = max(maxlen, count[s[right]]);
            if (right - left + 1 - maxlen > k) {
                count[s[left]]--;
                left++;
            }
            right++;
        }
        return right - left;
    }
};
// @lc code=end
