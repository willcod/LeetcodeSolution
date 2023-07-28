/*
 * @lc app=leetcode.cn id=2208 lang=cpp
 *
 * [2208] 将数组和减半的最少操作次数
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
 public:
  int halveArray(vector<int>& nums) {
    priority_queue<double> pq(nums.begin(), nums.end());

    int count = 0;
    double tar = accumulate(nums.begin(), nums.end(), 0.0) / 2;

    while (tar > 0) {
      double x = pq.top();
      pq.pop();
      tar -= x / 2;
      pq.push(x / 2);
      count++;
    }
    return count;
  }
};
// @lc code=end
