/*
 * @lc app=leetcode.cn id=229 lang=cpp
 *
 * [229] 求众数 II
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
 public:
  vector<int> majorityElement(vector<int>& nums) {
    unordered_map<int, int> counts;
    set<int> res;
    for (int i = 0; i < nums.size(); i++) {
      counts[nums[i]]++;
      if (counts[nums[i]] > nums.size() / 3) res.insert(nums[i]);
    }
    return {res.begin(), res.end()};
  }
};
// @lc code=end
