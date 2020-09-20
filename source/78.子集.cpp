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
    vector<int> path;
    subsets(nums, res, path, 0);
    return res;
  }

  void subsets(vector<int>& nums, vector<vector<int>>& res, vector<int>& path,
               int index) {
                   
    res.push_back(path);

    if (index == nums.size()) return;

    for (int i = index; i < nums.size(); i++) {
      path.push_back(nums[i]);
      subsets(nums, res, path, i + 1);
      path.pop_back();
    }
  }
};
// @lc code=end
