/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
 public:
  vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    set<int> set1({nums1.begin(), nums1.end()});

    set<int> cross;
    for (auto n : nums2) {
      if (set1.count(n)) {
        cross.insert(n);
      }
    }

    return vector<int>({cross.begin(), cross.end()});
  }
};
// @lc code=end
