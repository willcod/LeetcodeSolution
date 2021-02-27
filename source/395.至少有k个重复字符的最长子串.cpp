/*
 * @lc app=leetcode.cn id=395 lang=cpp
 *
 * [395] 至少有K个重复字符的最长子串
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
   public:
    int longestSubstring(string s, int k) {
        if (s.empty() || k > s.size()) return 0;
        if (k == 0) return s.size();

        unordered_map<char, int> hashCnt;
        for (auto c : s) {
            hashCnt[c]++;
        }

        int i = 0;
        while (i < s.size() && hashCnt[s[i]] >= k) i++;
        if (i == s.size()) return i;

        int left = longestSubstring(s.substr(0, i), k);
        int right = longestSubstring(s.substr(i + 1), k);

        return max(left, right);
    }
};
// @lc code=end
