/*
 * @lc app=leetcode.cn id=492 lang=cpp
 *
 * [492] 构造矩形
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
 public:
  vector<int> constructRectangle(int area) {
    int w = sqrt(area);
    while (area % w) w--;

    return {area / w, w};
  }
};
// @lc code=end
