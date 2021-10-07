/*
 * @lc app=leetcode.cn id=434 lang=cpp
 *
 * [434] 字符串中的单词数
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
 public:
  int countSegments(string s) {
    int count = 0;
    for (int i = 0; i < s.length(); i++) {
      if (s[i] != ' ' && (i == 0 || s[i-1] == ' ')) {
        count++;
      }
    }
    return count;
  }
};
// @lc code=end
