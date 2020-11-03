/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 翻转字符串里的单词
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
   public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());

        int n = s.length();
        int pos = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] != ' ') {
                if (pos > 0) {
                    s[pos++] = ' ';
                }

                int j = i;
                while (j < n && s[j] != ' ') {
                    s[pos++] = s[j++];
                }

                reverse(s.begin() + pos - (j - i), s.begin() + pos);
                i = j;
            }
        }

        s.erase(s.begin() + pos, s.end());
        return s;
    }
};
// @lc code=end
