/*
 * @lc app=leetcode.cn id=658 lang=cpp
 *
 * [658] 找到 K 个最接近的元素
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
 public:
  vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    int l = 0;
    int r = arr.size() - k;

    while (l < r) {
      int m = l + (r - l) / 2;

      if (x - arr[m] > arr[m + k] - x) {
        l = m + 1;
      } else {
        r = m;
      }
    }

    return {arr.begin() + l, arr.begin() + l + k};
  }
};
// @lc code=end
