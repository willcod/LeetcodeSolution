/*
 * @lc app=leetcode.cn id=1356 lang=cpp
 *
 * [1356] 根据数字二进制下 1 的数目排序
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
 public:
  vector<int> sortByBits(vector<int>& arr) {
      sort(arr.begin(), arr.end(), [](int a, int b) {
          return make_pair(bitset<32>(a).count(), a) <
          make_pair(bitset<32>(b).count(), b);
      });

      return arr;
  }
};
// @lc code=end
