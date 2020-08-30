/*
 * @lc app=leetcode.cn id=557 lang=cpp
 *
 * [557] 反转字符串中的单词 III
 */

// @lc code=start
class Solution {
 public:
  string reverseWords(string s) {
      int len = s.length();
      for (int i = 0; i < len; i++) {
          if (s[i] != ' ') {
              int j = i;
              for (; j < len && s[j] != ' '; j++){}
              reverse(s.begin() + i, s.begin() + j);
              i = j - 1;
          }
      }
      return s;
  }
};
// @lc code=end
