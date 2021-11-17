/*
 * @lc app=leetcode.cn id=318 lang=cpp
 *
 * [318] 最大单词长度乘积
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
 public:
  int maxProduct(vector<string>& words) {
    vector<int> mask(words.size());
    int result = 0;
    for (int i = 0; i < words.size(); i++) {
      for (char c : words[i]) {
        mask[i] |= 1 << (c - 'a');
      }
      for (int j = 0; j < i; j++) {
        if (!(mask[i] & mask[j]))
          result = max(result, int(words[i].size() * words[j].size()));
      }
    }
    return result;
  }
};
// @lc code=end
