/*
 * @lc app=leetcode.cn id=414 lang=cpp
 *
 * [414] 第三大的数
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
 public:
  int thirdMax(vector<int>& nums) {
    unordered_set<int> set;
    for (int n : nums) {
      set.insert(n);
    }

    vector<int> result;
    for (int n : set) {
      result.push_back(n);
    }

    sort(result.rbegin(), result.rend());

    return result.size() > 2 ? result[2] : result[0];
  }
};
// @lc code=end
