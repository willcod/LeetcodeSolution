/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
 public:
  vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> sub;

    subsets(res, sub, nums, 0);
    return res;
  }

  void subsets(vector<vector<int>>& res, vector<int>& sub, vector<int>& nums,
               int index) {
    res.push_back(sub);
    if (index >= nums.size()) return;

    for (int i = index; i < nums.size(); i++) {
      sub.push_back(nums[i]);
      subsets(res, sub, nums, i + 1);
      sub.pop_back();
    }
  }
};
// @lc code=end
