/*
 * @lc app=leetcode.cn id=201 lang=cpp
 *
 * [201] 数字范围按位与
 */

// @lc code=start
class Solution {
 public:
  int rangeBitwiseAnd(int m, int n) {
    if (m == 0 && n == 2147483647) return m;
    int len = n - m + 1, k = ceil(log(len) / log(2));
    return (m & n) >> (k) << (k);
  }
};
// @lc code=end
