/*
 * @lc app=leetcode.cn id=575 lang=cpp
 *
 * [575] 分糖果
 */
#include <algorithm>

#include "cpp_includes.h"
// @lc code=start
class Solution {
 public:
  int distributeCandies(vector<int>& candyType) {
    set<int> types{candyType.begin(), candyType.end()};
    return min(candyType.size() / 2, types.size());
  }
};
// @lc code=end
