/*
 * @lc app=leetcode.cn id=495 lang=cpp
 *
 * [495] 提莫攻击
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
 public:
  int findPoisonedDuration(vector<int>& timeSeries, int duration) {
    int res = 0;
    int expired = 0;

    for (int i = 0; i < timeSeries.size(); i++) {
      if (timeSeries[i] >= expired) {
        res += duration;
      } else {
        res += timeSeries[i] - expired + duration;
      }

      expired = timeSeries[i] + duration;
    }

    return res;
  }
};
// @lc code=end
