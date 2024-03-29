/*
 * @lc app=leetcode.cn id=520 lang=cpp
 *
 * [520] 检测大写字母
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
 public:
  bool detectCapitalUse(string word) {
    if (word.size() >= 2 && islower(word[0]) && isupper(word[1])) {
      return false;
    }

    for (int i = 2; i < word.size(); ++i) {
      if (islower(word[i]) ^ islower(word[1])) {
        return false;
      }
    }
    return true;
  }
};

// @lc code=end
