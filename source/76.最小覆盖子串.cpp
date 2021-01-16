/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
   public:
    string minWindow(string s, string t) {
        int m = s.length();
        int required = t.length();

        vector<int> remaining(128, 0);
        for (auto c : t) {
            remaining[c]++;
        }

        int start = 0;
        int end = 0;
        int begin = 0;
        int minlen = INT_MAX;
        while (end <= m && start < m) {
            if (required) {
                if (end == m) break;

                remaining[s[end]]--;
                if (remaining[s[end]] >= 0) required--;
                end++;
            } else {
                if (end - start < minlen) {
                    minlen = end - start;
                    begin = start;
                }

                remaining[s[start]]++;
                if (remaining[s[start]] > 0) required++;
                start++;
            }
        }
        return minlen == INT_MAX ? "" : s.substr(begin, minlen);
    }
};
// @lc code=end
