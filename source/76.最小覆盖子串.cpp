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
        unordered_map<char, int> hash;
        for (char c : t) {
            hash[c]++;
        }

        int start = 0, end = 0, begin = 0;
        int minlen = INT_MAX;

        while (end <= m && start < m) {
            if (required) {
                if (end == m) break;
                if (--hash[s[end]] >= 0) required--;
                end++;
            } else {
                if (end - start < minlen) {
                    minlen = end - start;
                    begin = start;
                }

                if (++hash[s[start]] > 0) required++;
                start++;
            }
        }


        return minlen == INT_MAX ? "" : s.substr(begin, minlen);

    }
};
// @lc code=end

