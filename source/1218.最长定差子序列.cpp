/*
 * @lc app=leetcode.cn id=1218 lang=cpp
 *
 * [1218] 最长定差子序列
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
 public:
  int longestSubsequence(vector<int>& arr, int difference) {
    unordered_map<int, int> dict;
    int result = 1;

    for (int n : arr) {
      if (dict.find(n - difference) != dict.end()) {
        dict[n] = dict[n - difference] + 1;
        result = max(result, dict[n]);
      } else {
        dict[n] = 1;
      }
    }

    return result;
  }
};
// @lc code=end
